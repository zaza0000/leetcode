#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public: 
	unordered_map<int, int> nodePos;
	TreeNode* buildTree(vector<int> preorder, vector<int> inorder){
		TreeNode *root;
		for(int i = 0; i < preorder.size(); i++)
			nodePos[inorder[i]] = i;
		root = dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
		return root;
	}
	TreeNode* dfs(vector<int> preorder, vector<int> inorder, int pStart, int pEnd, int iStart, int iEnd){
		if(pStart > pEnd)
			return NULL;
		int numOfLeftInorder = nodePos[preorder[pStart]] - iStart;
		TreeNode *node;
		node = new TreeNode(preorder[pStart]);
		node->left = dfs(preorder, inorder, pStart + 1, pStart + numOfLeftInorder, iStart, iStart + numOfLeftInorder - 1);
		node->right = dfs(preorder, inorder, pStart + numOfLeftInorder + 1, pEnd, iStart + numOfLeftInorder + 1, iEnd);
		return node;
	}
};

int main(){
	vector<int> preorder, inorder;
	Solution s;
	s.buildTree(preorder, inorder);
	cout<<"helloworld"<<endl;
	return 0;
}