//Given an input string , reverse the string word by word. 
//Solution : reverse the whole vector first, then start from the first ele, reverse the sub-vectors splited by space
class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int j=0;
        for(int i = 0; i< str.size(); i++){
            if(!isspace(str[i]))
                continue;
            reverse(str.begin()+j, str.begin()+i);
            j = i+1;
        }
        reverse(str.begin()+j, str.end());
        
    }
};

//if it is not allowed to use the reverse function, we could write a new one.
class Solution2 {
public:
    void reverseWords(vector<char>& str) {
        //reverse(str.begin(), str.end());
        reverse2(str,0,str.size()-1);
        int j=0;
        for(int i = 0; i< str.size(); i++){
            if(!isspace(str[i]))
                continue;
            //reverse(str.begin()+j, str.begin()+i);
            reverse2(str,j,i-1);
            j = i+1;
        }
        reverse2(str,j,str.size()-1);
        
    }
    
    void reverse2(vector<char>& str, int start, int end){
	    while(start < end)
		    swap(str[start++], str[end--]);
    }
};