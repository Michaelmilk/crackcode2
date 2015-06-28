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

int GetLength(ListNode *l)
{
	int len = 0;
	while(l)
	{
		len++;
		l = l->next;
	}
	return len;
}

void FillList(ListNode *&l, int k)
{
	ListNode *p_cur = NULL;
	while(k--)
	{
		p_cur = new ListNode(0);
		p_cur->next = l;
		l = p_cur;
	}
}

ListNode* AddTwoLists(ListNode* l1, ListNode* l2, int &c)
{
	if(!l1 && !l2 && c == 0)
		return NULL;
	if(!l1 && !l2)
		return new ListNode(c);
	ListNode *p_nxt = AddTwoLists(l1->next, l2->next, c);
	int sum = l1->val + l2->val + c;
	c = sum / 10;
	sum %= 10;
	ListNode *root = new ListNode(sum);
	root->next = p_nxt;
	return root;
}


//结点正序，1->2->3->4, 5->4->3相加为1777
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int len1 = GetLength(l1);
	int len2 = GetLength(l2);
	if(len1 > len2)
		FillList(l2, len1 - len2);
	else
		FillList(l1, len2 - len1);
	int c = 0;
	ListNode *root =  AddTwoLists(l1, l2, c);
	if(c != 0)
	{
		ListNode *p_tmp = new ListNode(c);
		p_tmp->next = root;
		root = p_tmp;
	}
	return root;
}

void printList(ListNode *root)
{
	while(root)
	{
		cout << root->val;
		root = root->next;
		if(root)
			cout << " -> ";
	}
	cout << endl;
}

int main()
{
	ListNode *l1 = new ListNode(9);
	ListNode *p_cur = l1;
	for(int i = 2; i < 5; i++)
	{
		ListNode *p_tmp = new ListNode(i);
		p_cur->next = p_tmp;
		p_cur = p_cur->next;
	}

	ListNode *l2 = new ListNode(9);
	p_cur = l2;
	for(int i = 9; i > 7; i--)
	{
		ListNode *p_tmp = new ListNode(i);
		p_cur->next = p_tmp;
		p_cur = p_cur->next;
	}

	printList(l1);
	printList(l2);

	ListNode *root = addTwoNumbers(l1, l2);
	printList(root);

	system("pause");
	return 0;
}