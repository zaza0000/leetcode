//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//Solution :start from begin and end simultaneously and compare 
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size();
        while(l < r){
            while(!isalnum(s[l]) && l < r){l++;}
            while(!isalnum(s[r]) && l < r){r--;}
            if(toupper(s[l]) != toupper(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};