#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<char> mappings[10];

	void dispDigit(){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < mappings[i].size(); j++)
				cout<<mappings[i][j];
			cout<<endl;
		}
	}

    void init(){
    	char a = 'a';
    	for(int i = 2; i < 10; i++){
    		for(int j = 0; j < 3; j++)
    			mappings[i].push_back(a++);
    		if(i == 7 || i == 9)
    			mappings[i].push_back(a++);
    	}
    	//dispDigit();
    }

    void dfs(vector<string> &res, string digits, int index, string cur) {
    	if(index == digits.size()){
			res.push_back(cur);
    		return;
    	}
    	int num = digits[index] - '0';
    	for(int i = 0; i < mappings[num].size(); i++)
    		dfs(res, digits, index + 1, cur + mappings[num][i]);
    	
    }

    vector<string> letterCombinations(string digits) {
    	vector<string> ans;
    	//cout<<ans.size()<<endl;
    	if(digits == "")
    		return  ans;
    	
		init();
		dfs(ans, digits, 0, "");
		//cout<<ans.size()<<endl;
    	return ans;      
    }

};

int main(){
	Solution s;
	s.letterCombinations("23");
	cout<<"helloworld"<<endl;
	return 0;
}