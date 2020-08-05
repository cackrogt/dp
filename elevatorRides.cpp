#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/elevator_rides.cpp
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first != b.first) {
		return a.first<b.first;
	}
       return a.second<b.second;
}
 
int main(){
	int n, max_weight;
	cin>>n>>max_weight;
	int people_weights[n];
	for(auto &x: people_weights) cin>>x;

	vector<pair<int, int>> dp(1<<n); // contains all subsets;
// the logic, as suggested, is for each subset, you just find 2 values{ min rides, weight used in the last ride}
// and then minimize result in the oreder of {min rides} followed by min weight of the last ride
	dp[0] = {1, 0};
	for(int i  = 1; i<(1<<n); i++) {
		dp[i] = {21, 0};
		// every one uses a separate ride, and all rides are full capacity;
		for(int j = 0; j<n; j++) {
			if( 1<<j & i){
				auto [ride_count, weight_of_last_ride] = dp[i ^ (1<<j)];
				if(people_weights[j] + weight_of_last_ride > max_weight) {
					ride_count++;
					weight_of_last_ride = min(weight_of_last_ride, people_weights[j]);
				}
				else {
					weight_of_last_ride += people_weights[j];
				}
				dp[i] = min(dp[i], {ride_count, weight_of_last_ride});
			} // j is contained in the current subset, it think this works will have to check;
		}
	}
	cout<< dp[(1<<n) - 1 ].first << endl;
}