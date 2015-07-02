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

class Stack3
{
public:
	Stack3(int s = 100)
	{
		buf = new int[s * 3];
		memset(sp, 0, sizeof(int) * 3);
		size = s;
	}

	~Stack3()
	{
		delete buf;
	}

	void push(int stk_num, int v)
	{
		int idx = stk_num * size + sp[stk_num];
		buf[idx] = v;
		sp[stk_num]++;
	}

	void pop(int stk_num)
	{
		if(sp[stk_num] == 0)
		{
			cout << "no data" << endl;
			return;
		}
		sp[stk_num]--;
	}

	int top(int stk_num)
	{
		if(sp[stk_num] == 0)
		{
			cout << "no data" << endl;
			return -1;
		}
		return buf[stk_num * size + sp[stk_num] - 1];
	}

	bool empty(int stk_num)
	{
		return sp[stk_num] == 0;
	}

private:
	int *buf;
	int sp[3];
	int size;
};

int main()
{
	Stack3 stk;
	stk.push(0, 33);
	stk.push(1, 22);
	stk.push(2, 455);
	cout << stk.top(2) << endl;
	cout << stk.top(0) << endl;
	cout << stk.top(1) << endl;
	stk.pop(2);
	cout << stk.top(2) << endl;
	system("pause");
	return 0;
}