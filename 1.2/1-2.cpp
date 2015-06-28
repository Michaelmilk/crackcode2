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

void Reverse(char *s)
{
	char *p_end = s;
	while(*p_end)
		p_end++;
	p_end--;

	while(s < p_end)
	{
		char t = *s;
		*s++ = *p_end;
		*p_end-- = t;
	}
}

int main()
{
	char s[] = "dsfgdgfd";
	Reverse(s);
	cout << s << endl;

	system("pause");
	return 0;
}