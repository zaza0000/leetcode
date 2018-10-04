//Given a linked list, rotate the list to the right by k places, where k is non-negative.
//Solution: first get the length by traversal the list, k%length, make it a ring and cut in the right place
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
    ListNode* rotateRight(ListNode* head, int k) {
    	ListNode *preHead;
    	preHead = head;
    	if(!head)
    		return head;
    	int length = 0;
    	while(preHead){
    		length ++;
    		preHead = preHead->next;
    	}
    	k %= length;
    	if(length == 1 || k == 0)
    		return head;

    	preHead = head;
    	for(int i = 0; i < length-k-1; i++){
    		head = head->next;
    	}
    	ListNode *newtail = head;
    	head = head->next;
    	newtail->next = NULL;
    	ListNode *temp = head;
    	while(temp->next){
    		temp = temp->next;
    	}
    	temp->next = preHead;
        return head;
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
	display(s.rotateRight(head, 3));

	return 0;
}