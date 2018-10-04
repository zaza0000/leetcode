//Given a linked list, determine if it has a cycle in it.
//Solution 1: reverse the list, if there is a cycle, it will finally come back to head.
//Solution 2; use 2 pointers, one pointer goes one step each while the other goes two step.
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
    bool hasCycle(ListNode *head) {
    	if(!head || !head->next)
    		return false;
    	ListNode *p, *q, *s;
    	p = head;
    	q = NULL;
    	while(p){
    		s = p->next;
    		p->next = q;
    		q = p;
    		p = s;
    		if(p == head)
    			return true;
    	} 
        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
    		return false;
        ListNode *speed1, *speed2;
        speed1 = speed2 = head;
        while(speed1->next != NULL && speed1->next->next != NULL){
            speed1 = speed1->next->next;
            speed2= speed2->next;
            if(speed1 == speed2) 
            	return true;
        }
        return false;
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
	p->next = head->next->next;
	Solution s;
	cout<<s.hasCycle(head)<<endl;

	return 0;
}