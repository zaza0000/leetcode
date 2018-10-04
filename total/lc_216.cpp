#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<vector<int> > ans;

	void dfs(vector<int> path, int sum, int k, int target, int index){
		if(sum == target && path.size() == k){
			ans.push_back(path);
			//display(path);
			return;
		}
		if(sum < target && path.size() == k)
			return;

		for(int i = index; i <= 9; i++){
			if (target >= i)
            {
                path.push_back(i);
                sum += i;
                dfs(path, sum, k, target, i+1);
                sum -= i;
                path.pop_back();
            }
		}

	}

	void display(vector<int>& path){
		for(int i = 0; i < path.size(); i++)
			cout<<path[i]<<",";
		cout<<endl;
	}

    vector<vector<int> > combinationSum3(int k, int n) {
		vector<int> path;
        dfs(path, 0, k, n, 1);
		//cout<<ans.size()<<endl;
        return ans;
    }
};

int main(){
	Solution s;
	s.combinationSum3(3,7);
	cout<<"helloworld"<<endl;
	return 0;
}