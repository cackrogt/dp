#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7, N = 1e6 + 10;

int main(){
	int x;
	cin>>x;
	int arr[x];
	for(int i =0; i<x; i++){
		cin>>arr[i];
	}
	set<int> st; //this is where i store the theoretical subsequence, of sorts
	st.insert(arr[0]);

	for(int i = 1; i<x ;i++){
		if(arr[i] > *st.crbegin(arr[i])){ //returns the iterator pointing to the last element, so reduces time complexity
			st.insert(arr[i]);//takes log(n)
			//cout<<i<<endl;
		}
		else{
			st.erase(*st.lower_bound(arr[i]));//takes log(n)
			st.insert(arr[i]);//takes log(n)
		}
	}
	//n time 2 times log(n) is the worst case for the loop above
	cout<<st.size()<<endl;
	
}
//can we call this dp, as we do remember something;
