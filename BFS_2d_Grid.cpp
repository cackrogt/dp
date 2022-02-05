#include <bits/stdc++.h>
using namespace std;
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/Graph.cpp

#define ii pair<int,int>
#define mp make_pair
#define f first
#define s second


char arr[1001][1001];
char arr2[1001][1001];
int visited[1001][1001];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0, 1, 0, -1};
string steps = "URDL";
 
int main(){
	int m,n;
	cin>>m>>n;
	ii start,end;
	queue<ii> q; 
	for(int i =0; i<m; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'A'){
				start = mp(i,j);
			} 
			if(arr[i][j] == 'B'){
				end = mp(i,j);
			}
		}
	}

	visited[start.f][start.s] = 1;
	q.push(start);
	while(!q.empty()){
		ii current = q.front();
		q.pop();
		for(int i =0; i<4; i++){
			ii adjacent = mp(current.f + dx[i], current.s + dy[i]);
			if(adjacent.f < 0 || adjacent.f >= m || adjacent.s < 0 || adjacent.s >= n)continue;
			if(arr[adjacent.f][adjacent.s] == '#' ) continue;
			if(visited[adjacent.f][adjacent.s] == 1) continue;
			visited[adjacent.f][adjacent.s] = 1;
			arr2[adjacent.f][adjacent.s]=i;
			q.push(adjacent);
		}
	}

	if(visited[end.f][end.s] ==1){
		cout<<"YES"<<endl;
		vector<int> path;
		while(end != start){
			int p = arr2[end.f][end.s];
			path.push_back(p);
			end = mp(end.f - dx[p], end.s - dy[p]);
		}
		reverse(path.begin(), path.end());

		cout << path.size() << endl;
		for (int c : path) {
			cout << steps[c];
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
