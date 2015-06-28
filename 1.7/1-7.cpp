#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
	int rows = matrix.size();
	if(0 == rows)
		return;
	int cols = matrix[0].size();
	bool first_row = false;
	bool first_col = false;

	for(int i = 0; i < cols; i++)
	{
		if(matrix[0][i] == 0)
			first_row = true;
	}

	for(int i = 0; i < rows; i++)
	{
		if(matrix[i][0] == 0)
			first_col = true;
	}

	for(int i = 1; i < rows; i++)
	{
		for(int j = 1; j < cols; j++)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	// for(int i = 1; i < cols; i++)
	// {
	// 	if(matrix[0][i] == 0)
	// 	{
	// 		for(int j = 0; j < rows; j++)
	// 			matrix[j][i] = 0;
	// 	}
	// }

	// for(int i = 1; i < rows; i++)
	// {
	// 	if(matrix[i][0] == 0)
	// 	{
	// 		for(int j = 0; j < cols; j++)
	// 			matrix[i][j] = 0;
	// 	}
	// }

	for(int i = 1; i < rows; i++)
	{
		for(int j = 1; j < cols; j++)
		{
			if(matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}

	if(first_row)
	{
		for(int i = 0; i < cols; i++)
			matrix[0][i] = 0;
	}

	if(first_col)
	{
		for(int i = 0; i < rows; i++)
			matrix[i][0] = 0;
	}
}


int main()
{
	

	system("pause");
	return 0;
}