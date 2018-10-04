//Reverse a linked list from position m to n. Do it in one-pass.
//Solution: need three pointer to do the reverse, at the same time record the position m-1(as p) and m(as a)
//Need a extra head to headle m = 1
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

void display(ListNode *headnode){
	while(headnode != NULL){
		cout<<headnode->val<<", ";
		headnode = headnode->next;
	}
	cout<<endl;

}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || n == m)
        	return head;
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *p = temp;
        for(int i = 0; i < m-1; i++)
        	p = p->next;
        ListNode *a = p->next, *b = a, *c = b->next;
        for(int i = m; i < n; i++){
        	ListNode *d = c->next;
        	c->next = b;
        	b = c;
        	c = d;
        }
        p->next = b;
        a->next = c;
        return temp->next;
    }
};

int main(){

	ListNode *head, *p;
	head = new ListNode(1);
	p = head;
	for(int i = 1; i < 10; i++){
		p->next = new ListNode(i+1);
		p = p->next;
	}
	display(head);
	Solution s;
	display(s.reverseBetween(head, 1, 6));

	return 0;
}