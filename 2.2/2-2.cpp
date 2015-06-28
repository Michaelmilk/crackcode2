#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* FindNthFromEnd(ListNode *head, int n)
{
	ListNode *p_slow = head;
	ListNode *p_fast = head;

	for(int i = 0; i < n && p_fast; i++)
		p_fast = p_fast->next;

	if(!p_fast)
		return NULL;
	while(p_fast)
	{
		p_fast = p_fast->next;
		p_slow = p_slow->next;
	}

	return p_slow;
}

ListNode* removeNthFromEnd2(ListNode* head, int n)
{
	ListNode *p_slow = head;
	ListNode *p_fast = head;

	for(int i = 0; i < n && p_fast; i++)
		p_fast = p_fast->next;

	while(p_fast && p_fast->next)
	{
		p_fast = p_fast->next;
		p_slow = p_slow->next;
	}
	//如果p_fast为空，那么说明需要删除头结点
	ListNode *p_tmp = p_fast ? p_slow->next : p_slow;
	p_slow->next = p_tmp->next;
	if(!p_fast)
		head = p_slow->next;
	delete p_tmp;
	return head;
}


//如果可能处理头结点的问题，考虑加一个伪头结点
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if(!head)
		return NULL;
	ListNode dummy(-1);
	dummy.next = head;
	ListNode *p_slow = &dummy;
	ListNode *p_fast = &dummy;

	for(int i = 0; i < n && p_fast; i++)
		p_fast = p_fast->next;

	if(!p_fast)
		return NULL;

	while(p_fast->next)
	{
		p_slow = p_slow->next;
		p_fast = p_fast->next;
	}

	ListNode *p_tmp = p_slow->next;
	p_slow->next = p_tmp->next;
	return dummy.next;
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
	printList(root);
	root = removeNthFromEnd(root, 5);
	printList(root);

	system("pause");
	return 0;
}