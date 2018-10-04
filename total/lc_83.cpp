//Given a sorted linked list, delete all duplicates such that each element appear only once.
//Solution 1: if the val of the current node is equal to its next,p->next = p->next->next. Else p = p->next
//Solution 2: use pointer p find the next different val, than do q->next = p, q = q->next
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

class Solution{
public:
	ListNode* deleteDuplicates(ListNode* head){
		ListNode *p;
		p = head;
		if(!head)
			return head;
		while(p->next != NULL){
			if(p->next->val == p->val){
				p->next = p->next->next;
			}
			else
				p = p->next;
		}
		return head;
	}

};

class Solution2{
public:
	ListNode* deleteDuplicates(ListNode* head){
		ListNode *p, *q;
		p = head;
		q = head;
		if(!head)
			return head;
		while(p != NULL){
			if(p->val == q->val){
				p = p->next;
			}
			else{
				q->next = p;
				q = q->next;
			}
		}
		q->next = p;
		return head;
	}

};

int main(){
	ListNode *head, *p;
	head = new ListNode(1);
	p = head;
	for(int i = 1; i < 5; i++){
		p->next = new ListNode(i+1);
		p = p->next;
		p->next = new ListNode(i+1);
		p = p->next;
	}
	display(head);
	Solution2 s;
	display(s.deleteDuplicates(head));

	return 0;
}