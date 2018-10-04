class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int ans = 0;
        int flag = 0;
        for(int i = 0; i < s.size(); i++){
            if(++hash[s[i]] > 1){
                while(flag < i){
                    hash[s[flag]]--;
                    flag ++;
                    if(hash[s[i]] == 1)
                        break;
                }
            }
            ans = max(ans, i - flag +1);
        }

        return ans;
    }
};