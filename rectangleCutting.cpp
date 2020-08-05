#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/rectangleCutting.cpp
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first != b.first) {
		return a.first<b.first;
	}
       return a.second<b.second;
}
 
int main(){
	int l, b;
	cin>>l>>b;
	int dp[l+1][b+1];
	dp[0][0] = 0;
	for(int i = 0; i<l+1; i++) {
		for(int j =0; j<b+1; j++) {
			dp[i][j] = std::numeric_limits<int>::max();
		}
	}
	for(int i = 0; i<l+1; i++) {
		for(int j =0; j<b+1; j++) {
			if(i == j) {
				dp[i][j] = 0;
				continue;
			}
			for(int k = 1; k < i; k++) {
				dp[i][j] = min(dp[i][j], 1+dp[i-k][j] + dp[k][j]);
			}
			for(int k = 1; k < j; k++) {
				dp[i][j] = min(dp[i][j], 1+dp[i][j-k] + dp[i][k]);
			}
		}
	}
	cout<<dp[l][b]<<endl;
}