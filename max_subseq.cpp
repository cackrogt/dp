#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/dp_c.cpp
using namespace std;

const int M = 1e9 + 7, N = 1e6 + 10;
int c[101]; long long dp[N];



int main(){
	int x;
	cin>>x;
	
	int arr[x];
	for(int i =0; i<x; i++){
		cin>>arr[i];
	}
	

	int sum = 0;

	dp[0] = 1;

	for(int i =1; i<x; i++){
		dp[i] = 1; //it always has itself
		for(int j =0; j<i; j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i], 1+dp[j]); //check if any old one is bigger

			} 
		}
		if(dp[i] > sum){
					sum = dp[i];
				}
	}

	
	cout<<sum<<endl;
	//else cout<<-1<<endl;
}
	
