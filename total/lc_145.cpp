#include <vector>
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
	vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        PostOrderTraverse(root);
        return ans;
    }

    void PostOrderTraverse(TreeNode* T) {
    	if(T){
	    	PostOrderTraverse (T->left);
	    	PostOrderTraverse (T->right);
	   		ans.push_back(T->val);
     	}
	}

};

int main(){
	cout<<"helloworld"<<endl;
	return 0;
}