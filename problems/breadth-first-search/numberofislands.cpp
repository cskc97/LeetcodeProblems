#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
	void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
		if (row<0 || col<0 || row >= grid.size() || col >= grid[0].size()) {
			return;
		}
		if (visited[row][col] || grid[row][col]=='0') {
			return;
		}
		
		visited[row][col] = true;

		dfs(grid, visited, row + 1, col);


		dfs(grid, visited, row - 1, col);


		dfs(grid, visited, row, col + 1);


		dfs(grid, visited, row, col - 1);
		

		

	}

	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		for (int i = 0; i<grid.size(); i++) {
			for (int j = 0; j<grid[0].size(); j++) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					dfs(grid, visited, i, j);
					count++;
				}
			}

		}

		return count;

	}
};


int main() {

	Solution s;
	vector<vector<char>> grid{ };
	if (grid.size() == 0) {
		cout<< 0;
		return 0;
	}
	
	cout<<s.numIslands(grid);
}
