//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//Solution : do traversal 3 times, 1: record the length, 2:reverse the second half of the list, 3:conbine
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
    void reorderList(ListNode* head) {
    	if(!head)
    		return;
    	ListNode *temp = head;
    	int length = 0;
    	while(temp){
    		length ++;
    		temp = temp->next;
    	}
    	if(length <= 2)
    		return;
    	ListNode *tempHead;
    	temp = head;
    	for(int i = 0; i < int(length/2)-1; i++)
    		temp = temp->next;
    	tempHead = temp->next;
    	temp->next = NULL;
    	temp = reverse(tempHead);
    	ListNode *a = head;
    	ListNode *b = a->next;
    	ListNode *c = temp;
    	tempHead = c->next;
    	while(b){
    		c->next = b;
    		a->next = c;
    		c = tempHead;
    		tempHead = tempHead->next;
    		a = b;
    		b = b->next;
    	}
    	a->next = c;
    	display(head);
    }

    ListNode* reverse(ListNode* head2){
    	if(!head2 || !head2->next)
    		return head2;
    	ListNode *tail = reverse(head2->next);
    	head2->next->next = head2;
    	head2->next = NULL;
    	return tail;
    }
};

int main(){
	ListNode *head, *p;
	head = new ListNode(1);
	p = head;
	for(int i = 1; i < 9; i++){
		p->next = new ListNode(i+1);
		p = p->next;
	}
	display(head);
	Solution s;
	s.reorderList(head);
	return 0;
}