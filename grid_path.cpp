#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/dp_c.cpp
using namespace std;

const int M = 1e9 + 7, N = 1e6 + 10;
int c[101]; int dp[1001][1001];
string arr[1001];


int main(){
	int x;
	cin>>x;
	

	for(int i =0; i<x; i++){

		cin>>arr[i];
	}
	if(arr[0][0] == '.'){
		dp[0][0] = 1;
	}

	for(int i =0; i<x; i++){
		for(int j =0; j<x; j++){
			if(i ==0 && j==0){
				continue;
			}
			else if(i ==0 && j!=0){
				if(arr[i][j] != '*' )
					dp[i][j] = dp[i][j-1];
				else 
					dp[i][j] = 0;
			}
			else if(i != 0 && j== 0){
				if(arr[i][j] != '*' )
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = 0;
			}
			else{
				if(arr[i][j] != '*' ){
					dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
				}
				else
					dp[i][j] = 0;
			}
		}
	}
	cout<<dp[x-1][x-1]<<endl;
}
	
