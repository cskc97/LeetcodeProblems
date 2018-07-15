#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


bool isValid(string s) {
	stack<char> stackVal;
	for (char ch : s) {
		if (ch == '(' || ch == ')') {
			if (ch == ')' && stackVal.empty()) {
				return false;
			}
			if (ch == ')' && stackVal.top() == '(') {
				stackVal.pop();
			}
			else
			{
				stackVal.push(ch);
			}
		}
	}
	return stackVal.empty();
}

vector<string> removeInvalidParentheses(string s) {

	if (s == "") {
		vector<string> vec;
		vec.push_back("");
		return vec;
	}
	vector<string> retVec;
	if (isValid(s)) {
		retVec.push_back(s);

		return retVec;
	}

	queue<string> bfsQueue;
	map<int, vector<string>> levelStr;
	int level = 0;
	level++;
	bfsQueue.push(s);
	bool found = false;
	while (!bfsQueue.empty() && !found) {
		for (int counter = 0;counter < s.size();counter++) {
			if (!(s[counter] == '(' || s[counter] == ')')) {
				continue;
			}
			string redStr = "";
			redStr += s.substr(0, counter);
			redStr += s.substr(counter + 1, s.size());
			if (isValid(redStr)) {
				levelStr[level].push_back(redStr);
				found = true;
			}
			bfsQueue.push(redStr);
		}
		level++;
		if (level > s.size()) {
			retVec.push_back("");
			return retVec;
		}
	}

	retVec = levelStr[level - 1];
	unordered_set<string> removeDups;
	for (string str : retVec) {
		removeDups.insert(str);
	}
	retVec.clear();
	for (string str : removeDups) {
		retVec.push_back(str);

	}


	return retVec;
}


int main() {

	string s = "a()";
	for (string str : removeInvalidParentheses(s)) {
		cout << str << endl;
	}

}
