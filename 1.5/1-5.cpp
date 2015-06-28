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

void Compress(int len, string &s, string &ans, int &len_after_compress)
{
	char previous = s[0];
	int count = 1;//!!!
	for(int i = 1; i <= len; i++)
	{
		if(s[i] != previous || i == len)//count the last char
		{
			ans.append(1, previous);
			stringstream ss;
			ss << count;
			string num;
			ss >> num;
			ans.append(num);
			previous = s[i];
			len_after_compress += num.length() + 1;
			count = 1;
		}
		else if(s[i] == previous)
			count++;
	}

	// ans.append(1, previous);
	// stringstream ss;
	// ss << count;
	// string num;
	// ss >> num;
	// ans.append(num);
	// len_after_compress += num.length() + 1;
}

string CompressString(string &s)
{
	int len = s.length();
	if(0 == len)
		return s;
	string ans;
	int len_after_compress = 0;
	Compress(len, s, ans, len_after_compress);
	if(len_after_compress >= len)
		return s;
	return ans;
}

int main()
{
	string s = "     ";//"k";//"adccef";
	cout << CompressString(s) << endl;

	system("pause");
	return 0;
}