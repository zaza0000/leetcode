//Given a string, determine if a permutation of the string could form a palindrome.
//Solution : too easy
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> hash;
        for(int i = 0; i < s.size(); i++){
            if(hash.count(s[i]))
                hash.erase(s[i]);
            else
                hash.insert(s[i]);
        }
        if(hash.size() <= 1)
            return true;
        return false;
    }
};