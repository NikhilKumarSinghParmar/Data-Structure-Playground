#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
#define all(a) a.begin(),a.end()
#define vi vector<int>


template <typename ty>
void print(ty arr){
	for(auto t : arr){
		cout << t << " ";
	}cout << endl <<  endl;
}



void solve(){
	set<int> s = {1,2,5,3,2,1,2,3,1,2};
	unordered_set<int> st = {1,2,5,3,2,1,2,3,1,2};
	
	
	vi v = {1,5,6,10};
	
	print(s);
	cout << "for set element : " << endl;
	for(auto t : v){
		cout << t << " : " ;
		if(s.find(t) != s.end()){
			cout << "present ";
			s.erase(t);
		}
		else{
			cout << "absent";
		}cout << endl;
	}
	//cout << endl;
	print(s);
	
	print(st);
	cout << "for unordered_set element : " << endl;
	for(auto t : v){
		cout << t << " : " ;
		if(st.find(t) != st.end()){
			cout << "present ";
			st.erase(t);
		}
		else{
			cout << "absent";
		}cout << endl;
	}cout << endl;
	print(st);
}



int main(){
	solve();
	
	return 0;
}