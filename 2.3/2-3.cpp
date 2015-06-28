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

bool DeleteSpecificNode(ListNode *p_node)
{
	if(!p_node || !p_node->next)
		return false;
	ListNode *p_nxt = p_node->next;
	p_node->next = p_nxt->next;
	p_node->val = p_nxt->val;
	delete p_nxt;
	return true;
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
	DeleteSpecificNode(root);
	DeleteSpecificNode(p_cur);
	printList(root);
	

	system("pause");
	return 0;
}