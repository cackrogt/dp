#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/slidingMedian2Sets.cpp
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first != b.first) {
		return a.first<b.first;
	}
       return a.second<b.second;
}

multiset<long>larger_than_median;
multiset<long>median_or_smaller;

void insertSpecial(long val, long window_size) {
	long median = *median_or_smaller.rbegin();
	if (val > median) {
		larger_than_median.insert(val);
		if(larger_than_median.size() > window_size/2) {
			median_or_smaller.insert(*larger_than_median.begin());
			larger_than_median.erase(larger_than_median.find(*larger_than_median.begin()));
		}
	}
	else{
		median_or_smaller.insert(val);
		if(median_or_smaller.size() > (window_size + 1)/2) {
			larger_than_median.insert(*median_or_smaller.rbegin());
			median_or_smaller.erase(median_or_smaller.find(*median_or_smaller.rbegin()));
		}
	}
}

void eraseSpecial(long val, long window_size) {
	if(larger_than_median.find(val) != larger_than_median.end()) {
		larger_than_median.erase(larger_than_median.find(val));
	}
	else if(median_or_smaller.find(val) != median_or_smaller.end()) {
		median_or_smaller.erase(median_or_smaller.find(val));
	}
	if(median_or_smaller.empty()) {
		median_or_smaller.insert(*larger_than_median.begin());
		larger_than_median.erase(larger_than_median.find(*larger_than_median.begin()));
	}
	// to make the add and erase agnostic to window size, this should be done properly.
	// if (larger_than_median.size() > window_size / 2) {
	// 	median_or_smaller.insert(*larger_than_median.begin());
	// 	larger_than_median.erase(larger_than_median.begin());
	// }
	// else if (median_or_smaller.size() > (window_size + 1) / 2) {
	// 	larger_than_median.insert(*median_or_smaller.rbegin());
	// 	median_or_smaller.erase(median_or_smaller.rbegin());
	// }
}
 
int main(){
	int num_elements, window_size;
	cin>>num_elements>>window_size;
	int vals[num_elements];
	for(int i = 0; i<num_elements; i++) {
		cin>>vals[i];
	}
	if(window_size == 1) {
		for(int i = 0; i<num_elements; i++) {
			cout<<vals[i]<< " ";
		}
		return 0;
	}
	median_or_smaller.insert(vals[0]);
	for(int i = 1; i<window_size; i++) {
		insertSpecial(vals[i], window_size);
	}
	cout<<*median_or_smaller.rbegin()<< " ";
	for(int i = window_size; i < num_elements; i++) {
		eraseSpecial(vals[i-window_size], window_size);
		insertSpecial(vals[i], window_size);
		cout<<*median_or_smaller.rbegin()<< " ";
	}
	cout<<endl;
	return 0;
}