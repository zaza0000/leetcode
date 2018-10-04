//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//Solution : compare the val of each list head and then combine
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(!l1)
    		return l2;
    	if(!l2)
    		return l1;
        ListNode * newList = new ListNode(0);
        ListNode * cur, *h1, *h2;
        cur = newList;
        h1 = l1;
        h2 = l2;
        while(h1 and h2){
        	if(h1->val <= h2->val){
        		cur->next = h1;
        		h1 = h1->next;
        		cur = cur->next;
        	}else{
        		cur->next = h2;
        		h2 = h2->next;
        		cur = cur->next;
        	}
        }
        if(h1)
        	cur->next = h1;
        else
        	cur->next = h2;

        return newList->next;
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

	ListNode *head2;
	head2 = new ListNode(3);
	p = head2;
	for(int i = 5; i < 8; i++){
		p->next = new ListNode(i+1);
		p = p->next;
	}
	display(head);
	display(head2);
	Solution s;
	display(s.mergeTwoLists(head,head2));
	return 0;
}