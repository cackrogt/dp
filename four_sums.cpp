#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/four_sums.cpp
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first != b.first) {
		return a.first<b.first;
	}
       return a.second<b.second;
}
 
int main(){
	int input_length, expected_value;
	cin>>input_length>>expected_value;
	vector<pair<int, int>>input_values(input_length);
	multimap<long, pair<int, int>> paired_sums;
	for(int i = 0; i<input_length; i++) {
		int temp_inputs;
		cin>>temp_inputs;
		input_values[i] = (make_pair(temp_inputs, i));
	}
	for(int i = 0; i<input_length; i++) {
		for(int j = i+1; j<input_length; j++) {
			paired_sums[input_values[i].first + input_values[j].first] = {i, j};
		}
	}
	for(auto iter : paired_sums) {
		if(paired_sums.count(expected_value-iter.first)){
			cout<< iter.second.first +1 << " " << iter.second.second +1 << " "  
				<< paired_sums[expected_value-iter.first].first << paired_sums[expected_value-iter.first].second +1;
				return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}