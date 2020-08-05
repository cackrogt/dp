#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/projects.cpp
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first != b.first) {
		return a.first<b.first;
	}
       return a.second<b.second;
}
 
int main(){
	struct projects{
		int start_date = 0;
		int end_date = 0;
		int reward = 0;
	};
	int n; cin>>n;
	vector<projects> project_list(n+1);
	for(int i = 1; i<=n; i++) {
		cin>>project_list[i].start_date>>project_list[i].end_date>>project_list[i].reward;
	}
	vector<long long> dp(n+1, 0);
	vector<int> only_end_dates(n+1);
	sort(project_list.begin()+1, project_list.end(), [](const projects &p1, const projects &p2){
		return p1.end_date<p2.end_date;
	});
	for(int i = 1; i<=n; i++) {
		only_end_dates[i] = project_list[i].end_date;
	}
	for(int i = 1; i<=n; i++) {
		int j = std::distance(only_end_dates.begin(), lower_bound(only_end_dates.begin(), only_end_dates.end(), project_list[i].start_date)) - 1;
		dp[i] = max(dp[i-1], dp[j] + project_list[i].reward);
	}
	cout<<dp[n]<<endl;
	return 0;
}