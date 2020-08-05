#include <bits/stdc++.h>
//g++ c:/Users/cackr/OneDrive/Desktop/competitive/three_sums.cpp
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
	for(int i = 0; i<input_length; i++) {
		int temp_inputs;
		cin>>temp_inputs;
		input_values[i] = (make_pair(temp_inputs, i));
	}
	sort(input_values.begin(), input_values.end());
	for(int i = 0; i<input_length; i++) {
		int first_index = 0, last_index = input_length - 1;
		while(first_index<last_index) {
			if(first_index == i) first_index++;
			else if(last_index == i) last_index--;
			else if(input_values[first_index].first + input_values[last_index].first + input_values[i].first > expected_value) last_index--;
			else if(input_values[first_index].first + input_values[last_index].first + input_values[i].first < expected_value) first_index++;
			else {
				cout<< input_values[first_index].second +1 << " " << input_values[last_index].second +1 << " "  << input_values[i].second +1;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}