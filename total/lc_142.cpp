//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//Solution 1: use hash map
//Solution 2: use two pointer, when find a cycle, the fast one restart from head in the same speed as the other one. Until they meet again
#include <unordered_map>
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
    ListNode *detectCycle(ListNode *head) {
    	if(!head)
    		return NULL;
    	ListNode *p = head;
    	unordered_map<ListNode*, int> hash;
    	while(p){
    		if(hash.count(p))
    			return p;
    		hash[p] = p->val;
    		p = p->next;
    	}
        return NULL;
    }
};

// Space complexity : O(1)
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
    	if(!head || !head->next)
    		return NULL;
    	ListNode *speed1 = head;
		ListNode *speed2 = head;
		while(speed2->next->next){
			speed1 = speed1->next;
			speed2 = speed1->next;
			if(speed2)
				speed2 = speed1->next;
			else
				return NULL;
			if(speed1 == speed2)
			{
				speed2 = head;
				while(speed2 != speed1){
					speed1 = speed1->next;
					speed2 = speed2->next;
				}
				return speed1;
			}
		}
		return NULL;	
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
	Solution2 s;
	cout<<s.detectCycle(head)->val<<endl;

	return 0;
}