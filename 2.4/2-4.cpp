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

ListNode* partition(ListNode* head, int x)
{
	ListNode *p_less = NULL;
	ListNode *p_greater = NULL;
	ListNode *p_lcur = p_less;
	ListNode *p_gcur = p_greater;
	ListNode *p_cur = head;
	while(p_cur)
	{
		if(p_cur->val < x)
		{
			if(!p_less)
			{
				p_less = p_cur;
				p_lcur = p_less;
			}
			else
			{
				p_lcur->next = p_cur;
				p_lcur = p_lcur->next;
			}
		}
		else
		{
			if(!p_greater)
			{
				p_greater = p_cur;
				p_gcur = p_greater;
			}
			else
			{
				p_gcur->next = p_cur;
				p_gcur = p_gcur->next;
			}
		}
		p_cur = p_cur->next;
	}

	if(!p_less)
		return p_greater;
	p_lcur->next = p_greater;
	if(p_gcur)
	    p_gcur->next = NULL;
	return p_less;
}

int main()
{
	

	system("pause");
	return 0;
}