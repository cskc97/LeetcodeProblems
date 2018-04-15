//
// Created by krish on 4/14/18.
//

//
// Created by krish on 4/14/18.
//

#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


    if(beginWord==endWord){
        return 1;
    }
    queue<string> bfsQ;
    bfsQ.push(beginWord);
    unordered_map<string,int> strCounts;

    for(string word: wordList){

        strCounts[word] = INT32_MAX;


    }

    if(strCounts.find(endWord) == strCounts.end()){
        return 0;
    }

    unordered_set<string> inQ;
    inQ.insert(beginWord);
    strCounts[beginWord] = 1;

    while(!bfsQ.empty()){
        string front;
        front = bfsQ.front();
        inQ.erase(front);
        bfsQ.pop();
        for(int i=0;i<front.size();i++){
            for(char ch='a';ch<='z';ch++){
                string anotherStr = front;
                anotherStr[i] = ch;
                if(front != anotherStr){
                    if(strCounts.find(anotherStr) != strCounts.end()){
                        strCounts[anotherStr] = min(strCounts[anotherStr], strCounts[front] + 1);
                        if(inQ.find(anotherStr)==inQ.end()) {
                            bfsQ.push(anotherStr);
                            inQ.insert(anotherStr); //Add word to queue only when it is not already in the queue (makes the algo faster)
                        }
                        if(anotherStr == endWord){
                            return strCounts[endWord];
                        }

                    }



                }

            }

        }




    }

    return 0;




}




int main(){
    vector<string> wordlist = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength("hit","cog",wordlist);
}