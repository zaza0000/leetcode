//4 Sum = 0
//Solution : based on 3 sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        if(nums.size() <= 3)
            return ans;
        for(int i = 0; i < nums.size()-3; i++){
            while(i != 0 && nums[i] == nums[i-1])
                i++;
            int target2 = target - nums[i];
            for(int j = i+1; j < nums.size()-2; j++){
                while(j != i+1 && nums[j] == nums[j-1])
                    j++;
                int target3 = target2 - nums[j];
                int l = j+1;
                int r = nums.size()-1;
                while(l < r){
                    if(nums[l] + nums[r] > target3){
                        do{ r--; }while(l < r && nums[r] == nums[r+1]);
                    }
                    
                    else if(nums[l] + nums[r] < target3){
                        do{ l++; }while(l < r && nums[l] == nums[l-1]);
                    }
                
                    else{
                        ans.push_back( {nums[i], nums[j], nums[l], nums[r]} );
                        do{ r--; }while(l < r && nums[r] == nums[r+1]);
                        do{ l++; }while(l <r && nums[l] == nums[l-1]);
                    }
                }
            }
            
        }
        return ans;
    }
};