#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	vector<vector<int> > ans;
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target){
		sort(candidates.begin(), candidates.end());
		vector<int> path;
		dfs(candidates, target, path, 0, 0);
		//cout<<ans.size()<<endl;
		return ans;
	}
	void dfs(vector<int>& candidates, int target, vector<int> path, int sum, int index){
		if(sum == target){
			ans.push_back(path);
			//display(path);
			return;
		}
		if(index >= candidates.size())
			return;

		for(int i = index; i < candidates.size(); i++){
			if(i > 0 && candidates[i] == candidates[i-1])
				continue;
			sum += candidates[i];
			if(sum > target)
				return;
			int curCan = candidates[i];
			path.push_back(candidates[i]);
			candidates.erase(candidates.begin()+i);
			dfs(candidates, target, path, sum, i);
			candidates.insert(candidates.begin()+i, curCan);
			path.pop_back();
			sum -= candidates[i];
		}
	}

	void display(vector<int>& path){
		for(int i = 0; i < path.size(); i++)
			cout<<path[i]<<",";
		cout<<endl;
	}
};

int main(){
	vector<int> can;
	can.push_back(1);
	can.push_back(2);
	can.push_back(2);
	can.push_back(2);
	can.push_back(5);
	int tar=5;
	Solution s;
	s.combinationSum(can, tar);


	cout<<"helloworld"<<endl;
	return 0;
}