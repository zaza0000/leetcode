//Reverse a singly linked list.
//Solution 1:iterative method, use three pointer to record the current node(need to reverse) ,previous list(reversed), successor list(to reverse)
//Solution 2:recursive method, reverse from tail to head
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

void display(ListNode *headnode){
	while(headnode != NULL){
		cout<<headnode->val<<", ";
		headnode = headnode->next;
	}
	cout<<endl;

}

//Solution 1
class Solution{
public:
	ListNode* reverseList(ListNode* head) {
		if(!head || !head->next)
			return head;
		ListNode *p, *q;
		p = head;
		q = NULL;
		while(head){
			head = head->next;
			p->next = q;
			q = p;
			p = head;
		}
		return q;
	}

};

//Solution 2 faster but need more space
class Solution2{
public:
	ListNode* reverseList(ListNode* head) {
		if(!head || !head->next)
			return head;
		ListNode *tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
	}

};

int main(){

	ListNode *head, *p;
	head = new ListNode(1);
	p = head;
	for(int i = 1; i < 5; i++){
		p->next = new ListNode(i+1);
		p = p->next;
	}
	display(head);
	Solution2 s;
	display(s.reverseList(head));

	return 0;
}