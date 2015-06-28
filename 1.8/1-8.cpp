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

bool IsRotation(string &s1, string &s2)
{
	string s = s1 + s1;
	if(s1.length() == s2.length() && s.find(s2) != string::npos)
		return true;
	return false;
}

int main()
{
	string s1 = "asdfghj";
	string s2 = "hjasdfg";
	cout << IsRotation(s1, s2) << endl;

	system("pause");
	return 0;
}