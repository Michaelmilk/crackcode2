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

void ConvertSpace(char *str)
{
	if(*str == '\0')
		return;
	int len = strlen(str);
	cout << len << endl;
	int space_num = 0;
	for(int i = 0; i < len; i++)
	{
		if(str[i] == ' ')
			space_num++;
	}
	int new_len = len + 2 * space_num;
	str[new_len--] = '\0';
	for(int i = len - 1; i >= 0; i--)
	{
		if(str[i] == ' ')
		{
			str[new_len--] = '%';
			str[new_len--] = '0';
			str[new_len--] = '2';
		}
		else
			str[new_len--] = str[i];
	}
}

int main()
{
	char str[50] = "a a ";//"I am a student! ";
	cout << str << endl;
	ConvertSpace(str);
	cout << str << endl;

	system("pause");
	return 0;
}