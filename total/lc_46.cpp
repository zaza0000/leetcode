#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > ans;
	void dfs(vector<int> nums, vector<int> path){
		if(nums.size() == 0){
			ans.push_back(path);
			return;
		}

		for(int i = 0; i < nums.size(); i++){
			path.push_back(nums[i]);
			int curNum = nums[i];
			nums.erase(nums.begin() + i);
			dfs(nums, path);
			nums.insert(nums.begin() + i, curNum);
			path.pop_back();
		}

	}

    vector<vector<int> > permute(vector<int>& nums) {
        //cout<<ans.size()<<endl;
        if(nums.size() == 0)
        	return ans;

		vector<int> path;
        dfs(nums, path);
        //cout<<ans.size()<<endl;
        return ans;
    }
};

int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	
	Solution s;
	s.permute(nums);
	cout<<"helloworld"<<endl;
	return 0;
}
