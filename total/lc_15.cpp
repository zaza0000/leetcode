// Three sum = 0
//Solution : Sort, then start from the first ele and set it as -target. 
//           Then the problem becomes find two sum = target. 
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        if(nums.size() <= 2)
            return ans;
        for(int i = 0; i < nums.size()-2; i++){
            while(i != 0 && nums[i] == nums[i-1])
                i++;
            int target = -nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l < r){
                if(nums[l] + nums[r] > target){
                    do{ r--; }while(l < r && nums[r] == nums[r+1]);
                }
                    
                else if(nums[l] + nums[r] < target){
                    do{ l++; }while(l < r && nums[l] == nums[l-1]);
                }
                
                else{
                    cout<<-target<<" "<<nums[l]<<" "<<nums[r]<<endl;
                    vector<int> ans1;
                    ans1.push_back(-target);
                    ans1.push_back(nums[l]);
                    ans1.push_back(nums[r]);
                    ans.push_back(ans1);
                    do{ r--; }while(l < r && nums[r] == nums[r+1]);
                    do{ l++; }while(l <r && nums[l] == nums[l-1]);
                }
            }
        }
        return ans;
    }
};

int main(){
    int a[16] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    vector<int> test;
    for(int i = 0; i < 16; i++)
        test.push_back(a[i]);
    Solution s;
    s.threeSum(test);
    return 0;
}