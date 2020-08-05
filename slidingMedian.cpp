#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/slidingMedian.cpp
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first != b.first) {
		return a.first<b.first;
	}
       return a.second<b.second;
}
 
int main(){
	int n, k;
	cin>>n>>k;
	int vals[n];
	for(int i = 0; i<n; i++) {
		cin>>vals[i];
	}
	std::multiset<int> current_window_set;
	std::queue<int> current_window_queue;
	for(int i = 0; i<n; i++) {
		if(current_window_queue.size() == k) {
			if(k&1) {
				auto mid = current_window_set.begin();
				std::advance(mid, k/2);
				cout<< *mid << " ";
			}
			else{
				auto mid = current_window_set.begin();
				std::advance(mid, k/2 -1);
				cout<< *mid << " ";
			}
			int val_to_remove = current_window_queue.front();
			auto it = current_window_set.find(val_to_remove);
			current_window_set.erase(it);
			current_window_queue.pop();
		}
		current_window_set.insert(vals[i]);
		current_window_queue.push(vals[i]);
	}
	if(k&1) {
		auto mid = current_window_set.begin();
		std::advance(mid, k/2);
		cout<< *mid << " ";
	}
	else{
		auto mid = current_window_set.begin();
		std::advance(mid, k/2 -1);
		cout<< *mid << " ";
	}
	cout<<endl;
	return 0;
}