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

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) : val(v), next(NULL){}
};

void DeleteDups(ListNode *root)
{
	if(!root)
		return;
	unordered_map<int, bool> mp;
	mp[root->val] = true;
	ListNode *p_cur = root;
	while(p_cur && p_cur->next)//当p_tmp是最后一个节点的时候，最后一句p_cur = p_cur->next;后p_cur == NULL 奔溃
	{
		if(mp[p_cur->next->val])
		{
			ListNode *p_tmp = p_cur->next;
			p_cur->next = p_tmp->next;
			delete p_tmp;
		}
		else
			mp[p_cur->next->val] = true;
		p_cur = p_cur->next;
	}
}


//clean and understandable
void DeleteDups2(ListNode *root)
{
	if(!root)
		return;
	unordered_map<int, bool> mp;
	ListNode *p_prev = NULL;//previous node
	while(root)
	{
		if(mp[root->val])
		{
			ListNode *p_tmp = root;
			p_prev->next = p_tmp->next;
			delete p_tmp;
		}
		else
		{
			mp[root->val] = true;
			p_prev = root;//p_prev指针的位置一定要赋值
		}
		root = p_prev->next;
	}
}

void DeleteDups3(ListNode *root)
{
	if(!root)
		return;

	ListNode *p_cur = root;
	
	while(p_cur)
	{
		ListNode *p_prev = p_cur;
		ListNode *p_nxt = p_cur->next;
		while(p_nxt)
		{
			if(p_nxt->val == p_cur->val)
			{
				ListNode *p_tmp = p_nxt;
				p_prev->next = p_tmp->next;
				p_nxt = p_tmp->next;
				delete p_tmp;
			}
			else
			{
				p_prev = p_nxt;//p_prev指针的位置一定要赋值
				p_nxt = p_nxt->next;
			}
		}
		p_cur = p_cur->next;
	}
}

void printList(ListNode *root)
{
	while(root)
	{
		cout << root->val << endl;
		root = root->next;
	}
}

int main()
{
	ListNode *root = new ListNode(1);
	ListNode *p_cur = root;
	for(int i = 1; i < 5; i++)
	{
		ListNode *p_tmp = new ListNode(i);
		p_cur->next = p_tmp;
		p_cur = p_cur->next;
	}

	p_cur->next = new ListNode(3);

	printList(root);
	DeleteDups3(root);
	printList(root);

	system("pause");
	return 0;
}