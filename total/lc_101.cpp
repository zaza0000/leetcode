#include <stack>
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
        	return true;
        if(dfs(root->left,root->right))
        	return true;
        return false;
    }
    bool dfs(TreeNode* l, TreeNode* r){
    	if(!l || !r)
    		return !l && !r;
    	if(l->val != r->val)
    		return false;
    	if(dfs(l->left, r->right) && dfs(l->right, r->left))
    		return true;
    	else 
    		return false;
    }
};

int main(){
	//int num[7] = {1,2,2,3,4,4,3}; 
	int num[7] = {1,2,2,0,3,0,3}; 
	int numSize = sizeof(num) / sizeof(num[0]);
	TreeNode *root = creattree(num, 1, numSize);
	Solution s;
	cout<<s.isSymmetric(root)<<endl;

	cout<<"helloworld"<<endl;
	return 0;
}


class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> left, right;
        TreeNode *lc = root->left;
        TreeNode *rc = root->right;
        while(lc || rc || left.size())
        {
            while (lc && rc)
            {
                left.push(lc), right.push(rc);
                lc = lc->left, rc = rc->right;
            }
            if (lc || rc) return false;
            lc = left.top(), rc = right.top();
            left.pop(), right.pop();
            if (lc->val != rc->val) return false;
            lc = lc->right, rc = rc->left;
        }
        return true;
    }

};