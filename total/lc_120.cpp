#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	int minimumTotal(vector<vector<int> >& triangle) {
		int ans;
		for(int i = triangle.size() - 2; i >= 0; i--){
			for(int j = 0; j < i + 1; j++)
				triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
		}
		ans = triangle[0][0];
		return ans;
	}
};

int main(){

	cout<<"helloworld"<<endl;
	return 0;
}