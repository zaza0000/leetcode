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

class Solution{
public:
	bool findPath(TreeNode* curNode, TreeNode* des, vector<TreeNode* > &path){
		if(curNode == NULL)
			return false;
		if(curNode->val == des->val){
			path.push_back(curNode);
			return true;
		}
		if (findPath(curNode -> left, des, path) || findPath(curNode -> right, des, path)) {
            path.push_back(curNode);
            return true;
        }
        return false;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		vector<TreeNode* > pPath, qPath;
		if(findPath(root, p, pPath) && findPath(root, q, qPath)){
			int n = min(pPath.size(), qPath.size());
			TreeNode* comAncestor = root;
			for (int i = 0; i < n; i++){
				if(pPath[pPath.size() - 1 - i]->val == qPath[qPath.size() - 1 -i]->val){
					comAncestor = pPath[pPath.size() - 1 - i];
				}
				else
					break;
			}
			return comAncestor;
		}
		return NULL;
	}
};

int main(){

	cout<<"helloworld"<<endl;
	return 0;
}