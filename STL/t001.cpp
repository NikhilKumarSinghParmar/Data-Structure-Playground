#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
#define all(a) a.begin(),a.end()
#define vi vector<int>

void printarr(vi& arr){
	for(auto t : arr){
		cout << t << " ";
	}cout << endl;
}


void solve(){
	vi v = {1,2,3,4,5,6,7,8,9,10};
	int n = v.size();
	
	int k = 8;
	int ans = 0;
	unordered_map<int,int> mp;
	
	for(auto t : v){
		if(mp.find(t) != mp.end()){
			ans += mp[t];
		}else{
			mp[k - t]++;
		}
	}
	
	cout << "answer : " << ans << endl;
	
}


void solve1(){
	vi v = {1,2,3,4,5,6,7,8,9,10};
	int n = v.size();
	
	int k = 8;
	int ans = 0;
	unordered_set<int> st;
	
	for(auto t : v){
		if(st.find(k-t) != st.end()){
			++ans;
		}else{
			st.insert(t);
		}
	}
	
	cout << "answer : " << ans << endl;
	
}



int main(){
	solve();
	solve1();
	
	return 0;
}