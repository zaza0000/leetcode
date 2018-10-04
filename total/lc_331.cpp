#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	string pre;
	int length;
	bool isValidSerialization(string preorder) {
		pre = preorder + ",";
		length = pre.size();
		int index = dfs(0);
		if(index == length - 1)
			return true;
		return false;
	}

	int dfs(int index){

		if(pre[index] == '#'){
			return index + 1;
		}
		int nextIndex = index;
		while(pre[nextIndex] != ','){
			nextIndex++;
		}
		if(nextIndex == length - 1)
			return -1;
		int lBack = dfs(nextIndex + 1);
		if(lBack == length - 1 || lBack == -1)
			return -1;
		int rBack = dfs(lBack + 1);
		if(rBack == -1)
			return -1;
		return rBack;
	}
};

int main(){
	string str = "9,#,#,1";
	Solution s;
	cout<<s.isValidSerialization(str)<<endl;
	cout<<"helloworld"<<endl;
	return 0;
}