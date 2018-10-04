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

class Solution {
public:
    vector<int> nodes;
    void getvector(TreeNode*root)
    {
        if(root != NULL){  
        	getvector(root->left);
        	nodes.push_back(root->val);
        	getvector(root->right);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        getvector(root);
        sort(nodes.begin(),nodes.end());

        int p1 = 0, p2 = nodes.size()-1;
        while(p1 != p2)
        {
            int sum = nodes[p1] + nodes[p2];
            if(sum == k)
                return true;
            else if(sum > k)
                p2--;
            else if(sum < k)
                p1++;
        }
        return false;
    }
};

int main(){

	cout<<"helloworld"<<endl;
	return 0;
}