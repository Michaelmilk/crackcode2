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

class Stack
{
public:
	void push(int v)
	{
		stk1.push(v);
		if(stk2.empty() || v <= stk2.top())
			stk2.push(v);
	}

	int top()
	{
		return stk1.top();
	}

	void pop()
	{
		if(stk1.top() == stk2.top())
			stk2.pop();
		stk1.pop();
	}

	int min()
	{
		return stk2.top();
	}

private:
	stack<int> stk1;
	stack<int> stk2;
};

int main()
{
	

	system("pause");
	return 0;
}