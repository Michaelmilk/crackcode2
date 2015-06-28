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

bool CheckDuplicates(string &s)
{
	bool mp[256];
	memset(mp,false, 256);
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
		if(mp[s[i]])
			return false;
		mp[s[i]] = true;
	}
	return true;
}

//O(1) space complexity
bool CheckDuplicates2(string &s)
{
	int len = s.length();
	int mark = 0;
	for(int i = 0; i < len; i++)
	{
		if(mark & (1 << (s[i] - 'a')))
			return false;
		mark |= (1 << (s[i] - 'a'));
	}
	return true;
}

int main()
{
	string s = "khjousdd";
	cout << CheckDuplicates(s) << endl;
	cout << CheckDuplicates2(s) << endl;

	system("pause");
	return 0;
}