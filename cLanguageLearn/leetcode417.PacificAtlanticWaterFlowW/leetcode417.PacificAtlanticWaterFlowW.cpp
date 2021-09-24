// unknown bugs to be solved

#include <vector>
#include <iostream>

using namespace std;


vector<int> direction{ -1, 0, 1, 0, -1 };


void dfs(vector<vector<int>> matrix, vector<vector<bool>> &ocean, int i, int j)
{
	if (ocean[i][j]) return;//∑¿÷π—≠ª∑∑√Œ 

	ocean[i][j] = true;
	int x, y;

	for (int d = 0; d < 4; d++)
	{
		x = i + direction[d];
		y = j + direction[d + 1];
		if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size())
			if (matrix[x][y] >= matrix[i][j])
				dfs(matrix, ocean, x, y);
	}
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> height)
{
	int width = height.size();
	int length = height[0].size();
	vector<vector<bool>> Pacific(length,vector<bool>(length, false));
	vector<vector<bool>> Atlantic(length, vector<bool>(length, false));
	vector<vector<int>> solution;

	for (int j = 0; j < height[0].size(); j++)
	{
		Pacific[0][j] = true;
	}

	for (int i = 1; i < height[0].size(); i++)
	{
		Pacific[i][0] = true;
	}
	

	for (int i = 0; i < height.size(); i++)
	{
		for (int j = 0; j < height[0].size(); j++)
		{

			dfs(height, Pacific, i, j);
		}
	}

	//atlantic
	for (int j = 0; j < height[0].size(); j++)
	{
		Atlantic[0][j] = true;
	}

	for (int i = 1; i < height[0].size(); i++)
	{
		Atlantic[i][0] = true;
	}


	for (int i = height.size() - 1; i >= 0; i--)
	{
		for (int j = height.size() - 1; j >= 0; j--)
		{
			dfs(height, Atlantic, i, j);
		}
	}

	for (int i = 0; i < height[0].size(); i++)
	{
		for (int j = 0; j < height[0].size(); j++)
			if (Pacific[i][j] && Atlantic[i][j])
				solution.push_back({ i,j });
	}
	
	return solution;


}


int main()
{
	vector<vector<int>> height = { {1, 2, 2, 3, 5},{3, 2, 3, 4, 4},{2, 4, 5, 3, 1},{6, 7, 1, 4, 5},{5, 1, 1, 2, 4} };
	vector<vector<int>> output = pacificAtlantic(height);
	for (int i = 0; i < output.size(); i++)
	{
		for (int j = 0; j < output[1].size(); j++)
			cout << i << "," << j << endl;
	}

	return 0;
}









