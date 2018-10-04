#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
	map<vector<int>, bool> flag;
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
        dfs(nums,0);
		//cout<<ans.size()<<endl;
        return ans;
    }
	void display(vector<int> subs){
		for(int i = 0; i < subs.size(); i++)
			cout<<subs[i]<<",";
		cout<<endl;
	}

    void dfs(vector<int> nums,int p){
        if (p == nums.size()){
            int t=path.size();
            if (!flag[path]){
				ans.push_back(path);
                flag[path] = true;
            }
			//display(path);
            return;
        }
        dfs(nums,p+1);
        path.push_back(nums[p]);
        dfs(nums,p+1);
        path.pop_back();
    }
};

int main(){
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(1);
	Solution s;
	s.subsetsWithDup(num);
	cout<<"helloworld"<<endl;
	return 0;
}