//Write a program to find the node at which the intersection of two singly linked lists begins
//Solution : need two pointers, traverse each list, when to the end, redirect that pointer to another head. stop when two pointers equal to each other
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
        	return nullptr;
        ListNode *p1, *p2;
        p1 = headA;
        p2 = headB;
        while(p1 != p2){
        	if(p1)
        		p1 = p1->next;
        	else
        		p1 = headB;
        	if(p2)
        		p2 = p2->next;
        	else
        		p2 = headA;
        }
        return p1;
    }
};

int main(){

	ListNode *head, *head2, *p, *q;
	head = new ListNode(1);
	p = head;
	for(int i = 2; i < 9; i += 2){
		p->next = new ListNode(i+1);
		p = p->next;
	}
	head2 = new ListNode(0);
	q = head2;
	for(int i = 1; i < 9; i += 2){
		q->next = new ListNode(i+1);
		q = q->next;
	}
	q->next = p;
	for(int i = 10; i < 15; i++){
		p->next = new ListNode(i+1);
		p = p->next;
	}
	display(head);
	display(head2);
	Solution s;
	s.getIntersectionNode(head,head2);


	return 0;
}