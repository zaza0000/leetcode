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

class Solution{
public:
	vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> >ans;
        if(root == NULL)
            return ans;
        vector<TreeNode* > level;
        level.push_back(root);
        while(!level.empty()){
        	vector<TreeNode* > nextLevel;
        	vector<int> sub_ans;
        	for(int i = 0; i < level.size(); i++){
                if(level[i] != NULL){
        		    if(level[i]->left != NULL)
        			    nextLevel.push_back(level[i]->left);
        		    if(level[i]->right != NULL)
        			    nextLevel.push_back(level[i]->right);
        	    	sub_ans.push_back(level[i]->val);
                }
        	}
            ans.push_back(sub_ans);
        	level = nextLevel;
        }
        return ans;
    }
};

int main(){
	int num[7] = {3,9,20,0,0,15,7}; 
	int numSize = sizeof(num) / sizeof(num[0]);
	TreeNode *root = creattree(num, 1, numSize);
	Solution s;
	s.levelOrder(root);
	cout<<"helloworld"<<endl;
	return 0;
}