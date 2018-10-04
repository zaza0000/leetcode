//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//Return a deep copy of the list.
//Solution : use hash map
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	unordered_map<RandomListNode*, RandomListNode*> hash;
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(!head)
    		return head;
    	if(hash.count(head))
    		return hash[head];
    	RandomListNode *newHead = new RandomListNode(head->label);
    	hash[head] = newHead;
    	newHead->next = copyRandomList(head->next);
    	newHead->random = copyRandomList(head->random);
     	return newHead;
    }
};


int main(){

	// this is hard to write a test.
	return 0;
}

/*
class Solution(object):
    """
    :type head: RandomListNode
    :rtype: RandomListNode
    """
    def __init__(self):
        # Dictionary which holds old nodes as keys and new nodes as its values.
        self.visitedHash = {}

    def copyRandomList(self, head):

        if head == None:
            return None

        # If we have already processed the current node, then we simply return the cloned version of it.
        if head in self.visitedHash:
            return self.visitedHash[head]

        # create a new node
        # with the label same as old node.
        node = RandomListNode(head.label)

        # Save this value in the hash map. This is needed since there might be
        # loops during traversal due to randomness of random pointers and this would help us avoid them.
        self.visitedHash[head] = node

        # Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
        # Thus we have two independent recursive calls.
        # Finally we update the next and random pointers for the new node created.
        node.next = self.copyRandomList(head.next)
        node.random = self.copyRandomList(head.random)

        return node
*/