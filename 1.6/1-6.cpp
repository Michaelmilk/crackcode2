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

void rotate(vector<vector<int>>& matrix)
{
	int rows = matrix.size();
	if(rows == 0)
		return;
	int cols = matrix[0].size();
	for(int i = 0; i < rows / 2; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			int t = matrix[i][j];
			matrix[i][j] = matrix[rows - 1 - i][j];
			matrix[rows - 1 - i][j] = t;
		}
	}

	for(int i = 0; i < row - 1; i++)//!! i < rows - 1
	{
		for(int j = i + 1; j < cols; j++)
		{
			int t = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = t;
		}
	}
}

int main()
{
	

	system("pause");
	return 0;
}