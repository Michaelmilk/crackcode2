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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if(!l1)
		return l2;
	if(!l2)
		return l1;

	ListNode dummy(-1);
	ListNode *p_cur = &dummy;
	int c = 0;
	while(l1 || l2)
	{
		int val1 = l1 ? l1->val : 0;
		int val2 = l2 ? l2->val : 0;
		int sum = (val1 + val2 + c) % 10;
		c = (val1 + val2 + c) / 10;
		p_cur->next = new ListNode(sum);
		p_cur = p_cur->next;
	    l1 = l1 ? l1->next : NULL;
	    l2 = l2 ? l2->next : NULL;
	}
	if(c != 0)
		p_cur->next = new ListNode(c);
	return dummy.next;
}

int main()
{
	

	system("pause");
	return 0;
}