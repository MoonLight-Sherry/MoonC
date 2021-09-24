#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> direction{ -1, 0, 1, 0, -1 };

void dfs(vector<vector<char>>& board, int i, int j)
{
	if (i < 0 || i > board.size() || j < 0 || j > board.size())
		return;
	if (!board[i][j] == 'O')
		return;
	board[i][j] = '*';
	for (int k = 0; k < 4; k++)
	{
		int m = i + direction[k];
		int n = j + direction[k + 1];
		dfs(board, m, n);
	}

}



void solve(vector<vector<char>>& board) {
	if (board.empty()) return;

	int row = board.size();
	if (row == 0) return;
	int col = board[0].size();
	if (col == 0) return;

	//遍历上下边界中的O
	for (int i = 0; i < col; i++) {
		dfs(board, 0, i);
		dfs(board, row - 1, i);
	}

	//遍历左右边界中的O
	for (int i = 0; i < row; i++) {
		dfs(board, i, 0);
		dfs(board, i, col - 1);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == '*') board[i][j] = 'O';
			else if (board[i][j] == 'O') board[i][j] = 'X';
		}
	}
	return;

}

int main()
{
	vector<vector<char>> board;
	solve(board);
	return 0;
}






