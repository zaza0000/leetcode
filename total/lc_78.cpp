#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int numOfSubset = 1 << n;
        for (int i = 0; i < numOfSubset; i++){
            vector<int> subset;
            for (int j = 0; j < n; j++)
                if (i >> j & 1)
                    subset.push_back(nums[j]);
            ans.push_back(subset);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int> > a;
    vector<int> b;
    vector<vector<int> > subsets(vector<int>& nums) {
        dfs(nums,0);
        return a;
    }
    void dfs(vector<int> nums,int p){
        if (p == nums.size()){
            a.push_back(b);
            return;
        }
        dfs(nums,p+1);
        b.push_back(nums[p]);
        dfs(nums,p+1);
        b.pop_back();
    }
};

int main(){

	cout<<"helloworld"<<endl;
	return 0;
}