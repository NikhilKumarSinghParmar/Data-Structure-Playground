#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define all(a) a.begin(),a.end()
#define vi vector<int>

void print(stack<int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}cout << endl << endl;
}



void solve(){
	stack<int> s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	
	print(s);
 }



int main(){
	solve();
	
	return 0;
}