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

class SetOfStack
{
private:
	stack<int> *stk;
	int cur;
	int capacity;
public:
	SetOfStack(int capa, int stk_num = 10)
	{
		stk = new stack<int>[stk_num];
		cur = 0;
		capacity = capa;
	}

	~SetOfStack()
	{
		//cout << "eee" << endl;
		delete[] stk;
		//cout << "ewww" << endl;
	}

	void push(int v)
	{
		if(stk[cur].size() >= capacity)
			cur++;
		stk[cur].push(v);
	}

	void pop()
	{
		if(stk[cur].empty())
			cur--;
		stk[cur].pop();
	}

	int top()
	{
		if(stk[cur].empty())
			cur--;
		return stk[cur].top();
	}

	bool empty()
	{
		if(cur == 0)
			return stk[cur].empty();
		return false;
	}

	bool full()
	{
		return stk[cur].size() >= capacity;
	}
};

class SetOfStack1
{
private:
	stack<int> *stk;
	int cur;
	int capacity;
public:
	SetOfStack1(int capa, int stk_num = 10)
	{
		stk = new stack<int>[stk_num];
		cur = 0;
		capacity = capa;
	}

	~SetOfStack1()
	{
		delete[] stk;
	}

	void push(int v)
	{
		if(stk[cur].size() >= capacity)
			cur++;
		stk[cur].push(v);
	}

	void pop()
	{
		while(stk[cur].empty())
			cur--;
		stk[cur].pop();
	}

	void popAt(int num)
	{
		while(stk[num].empty())
			num--;
		stk[num].pop();
	}

	int top()
	{
		if(stk[cur].empty())
			cur--;
		return stk[cur].top();
	}

	bool empty()
	{
		if(cur == 0)
			return stk[cur].empty();
		return false;
	}

	bool full()
	{
		return stk[cur].size() >= capacity;
	}
};

int main()
{
	SetOfStack s(1);
	s.push(2);
	s.push(33);
	cout << s.top() << endl;
	s.pop();
	cout << s.empty() << endl;
	s.pop();
	cout << s.empty() << endl;

	system("pause");
	return 0;
}