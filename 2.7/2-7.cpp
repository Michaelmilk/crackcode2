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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool CheckPalindromeList(ListNode *root)
{
	stack<int> stk;
	int len = 0;
	ListNode *p_slow = root;
	ListNode *p_fast = root;
	while(p_fast && p_fast->next)
	{
		stk.push(p_slow->val);
		p_slow = p_slow->next;
		p_fast = p_fast->next->next;
	}

	if(p_fast)
		p_slow = p_slow->next;

	while(p_slow && p_slow->val == stk.top())
	{
		stk.pop();
		p_slow = p_slow->next;
	}

	return stk.empty();
}

int main()
{
	ListNode *root = new ListNode(1);
	root->next = new ListNode(1);
	cout << CheckPalindromeList(root) << endl;

	system("pause");
	return 0;
}