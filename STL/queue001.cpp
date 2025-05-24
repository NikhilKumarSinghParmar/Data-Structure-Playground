#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define all(a) a.begin(),a.end()
#define vi vector<int>

void print(queue<int> q){
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}cout << endl << endl;
}


void solve(){
	queue<int> q;
	
	int n = 10;
	
	for(int i=1;i<=n;i++){
		q.push(i*i);
	}
	
	print(q);
	
	for(int i=1;i<=n/2;i++){
		q.pop(); 
	}
	
	print(q);
}



int main(){
	solve();
	
	return 0;
}