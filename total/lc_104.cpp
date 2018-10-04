#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
	TreeNode(TreeNode* t): val(t->val), left(t->left), right(t->right) {}

};

TreeNode* creattree (int num[], int i, int size){
	if(i > size)
		return NULL;
	if(num[i-1] == 0)
		return NULL;
	TreeNode *node;
	node = new TreeNode(num[i-1]);
	node->left = creattree(num, 2*i, size);
	node->right = creattree(num, 2*i+1, size);
	return node;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
    	if(root)
    		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return 0;
    }
};

int main(){
	//int num[7] = {1,2,2,3,4,4,3}; 
	int num[7] = {1,2,2,0,3,0,3}; 
	int numSize = sizeof(num) / sizeof(num[0]);
	TreeNode *root = creattree(num, 1, numSize);
	Solution s;
	cout<<s.maxDepth(root)<<endl;
	cout<<"helloworld"<<endl;
	return 0;
}