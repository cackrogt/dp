#include <bits/stdc++.h>
using namespace std;
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/graphdfs.cpp

#define ii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define pb push_back


int n,m;
vector <int> arr[100001];
int visited[100001];
vector <int> res;
int components;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0, 1, 0, -1};
string steps = "URDL";

void dfs(int x){
	visited[x] =1;
	//cout<<x<<endl;
	for(int i =0; i<arr[x].size(); i++){
		if (visited[arr[x][i]] == 0){
			dfs(arr[x][i]);
		}
	}
}
 
int main(){
	
	cin>>n>>m;

	for (int i =0; i<m;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;

		arr[temp1].pb(temp2);
		arr[temp2].pb(temp1);
		//cout <<arr[temp1][0]<<" "<<arr[temp2][0]<<endl;
	}

	for (int i =1; i<=n ; i++){
		//cout<<"inside dfs with"<< i <<endl;
		if (visited[i] == 0){
			//cout<<"inside dfs loop"<< i <<endl;
			res.pb(i);
			dfs(i);
		}
	}
	cout<<res.size()-1<<endl;
	for (int i = 1; i<res.size(); i++){
		cout << res[i-1] << " " << res[i];
		cout << endl;
	}


}