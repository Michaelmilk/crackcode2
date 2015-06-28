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

bool hasCycle2(ListNode *head)
{
	if(!head)
		return false;
	ListNode *p_slow = head;
	ListNode *p_fast = head;
	while(p_fast && p_fast->next)
	{
		p_slow = p_slow->next;
		p_fast = p_fast->next->next;
		if(p_fast == p_slow)
		    break;
	}

	if(!p_fast || !p_fast->next)
		return false;
	return true;
}

bool hasCycle(ListNode *head)
{
	ListNode *p_slow = head;
	ListNode *p_fast = head;

	while(p_fast && p_fast->next)
	{
		p_slow = p_slow->next;
		p_fast = p_fast->next->next;
		if(p_slow == p_fast)
			return true;
	}
	return false;
}


ListNode *detectCycle2(ListNode *head)
{
	if(!head)
		return NULL;
	ListNode *p_slow = head;
	ListNode *p_fast = head;

	while(p_fast && p_fast->next)
	{
		p_slow = p_slow->next;
		p_fast = p_fast->next->next;
		if(p_slow == p_fast)
			break;
	}

	if(!p_fast || !p_fast->next)
		return NULL;

	p_slow = head;
	while(p_slow != p_fast)
	{
		p_slow = p_slow->next;
		p_fast = p_fast->next;
	}
	return p_fast;
}

ListNode *detectCycle(ListNode *head)
{
	ListNode *p_slow = head;
	ListNode *p_fast = head;
	while(p_fast && p_fast->next)
	{
		p_fast = p_fast->next->next;
		p_slow = p_slow->next;
		if(p_fast == p_slow)
		{
			p_fast = head;
			while(p_fast != p_slow)
			{
				p_fast = p_fast->next;
				p_slow = p_slow->next;
			}
			return p_fast;
		}
	}
	return NULL;
}

int main()
{
	

	system("pause");
	return 0;
}