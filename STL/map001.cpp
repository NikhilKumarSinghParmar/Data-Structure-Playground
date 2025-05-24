#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define all(a) a.begin(),a.end()
#define vi vector<int>
#define vs vector<string>


void solve(){
	// sorted ordered map based on key only
	map<string,int> mp;
	
	vs v = {"apple","banana","mango","melon","guava","pineapple"};
	
	for(auto t : v){
		mp[t]++;
	}
	
	vs nums = {"mango","lichi","melon","lemon"};
	
	for(auto t : nums){
		cout << t << " : " ;
		if(mp.count(t)==0){
			cout << "absent";
		}else{
			cout << "present";
			mp.erase(t);
		}cout << endl;
	}cout << endl;
	
	// updated map
	for(auto t : mp){
		cout << t.first << " " ;
	}cout << endl;
}


int main(){
	solve();
	
	return 0;
}