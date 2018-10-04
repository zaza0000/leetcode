//Sort a linked list using insertion sort.
//Solution :do the traversal, if the current node val is smaller than the previous one, find the right position.
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
    ListNode* insertionSortList(ListNode* head) {
    	if(!head || !head->next)
    		return head;
    	ListNode *dummy = new ListNode(0);
    	dummy->next = head;
    	ListNode *p, *pre;
    	pre = head;
    	p = head->next;
    	while(p){
    		ListNode *cur = p;
    		p = p->next;
    		if(cur->val < pre->val){
    			pre->next = p;
    			ListNode *newPos = dummy;
    			while(newPos->next->val < cur->val){
    				newPos = newPos->next;
    			}
    			cur->next = newPos->next;
    			newPos->next = cur;
    		}
    		else
    			pre = pre->next;
    	}

        return dummy->next;
    }
};

int main(){

	ListNode *head, *p;
	head = new ListNode(1);
	p = head;
	for(int i = 9; i > 0; i--){
		p->next = new ListNode(i+1);
		p = p->next;
	}
	cout<<p->val<<endl;
	display(head);
	Solution s;
	display(s.insertionSortList(head));

	return 0;
}