//2 sum = target
//Solution : use hash map
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++){
            int comp = target -nums[i];
            if(hash.count(comp)){
                ans.push_back(hash[comp]);
                ans.push_back(i);
                return ans;
            }
            hash[nums[i]] = i;
        }
        return ans;
    }
};

int main(){

	cout<<"helloworld"<<endl;
	return 0;
}