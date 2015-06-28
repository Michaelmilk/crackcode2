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

ifstream in("in.in");
#define cin in

//区分大小写，并且不忽略空格

//sort
bool IsAnagram(string &s1, string &s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if(s1 == s2)
		return true;
	return false;
}

//hash
bool IsAnagram2(string &s1, string &s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 != len2)
		return false;
	vector<int> hash_table(256, 0);
	for(int i = 0; i < len1; i++)
		hash_table[s1[i]]++;

	for(int i = 0; i < len2; i++)
	{
		if(--hash_table[s2[i]] < 0)
			return false;
	}

	return true;
}

int main()
{
	string s1 = "adcb";
	string s2 = "acd";
	cout << IsAnagram(s1, s2) << endl;
	cout << IsAnagram2(s1, s2) << endl;

	system("pause");
	return 0;
}