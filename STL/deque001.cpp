#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
#define endl "\n"
#define int long long int


void print(deque<int>& dq){
	cout << "printing : " << endl;
	
	while(!dq.empty()){
		cout << dq.front() << " ";
		dq.pop_front();
	}cout << endl << endl;
}


void solve(){
	deque<int> dq(4,0);
	int n = dq.size();
	
	for(int i=1;i<=n;i++){
		dq[i] = i*i;
	}
	
	
	dq.push_back(10);
	dq.push_front(20);
	dq.push_front(30);
	dq.push_back(40);
	dq.push_front(50);
	
	n = dq.size();
	int m = -1;
	
	cout << n << " " << m << endl;
	
	int a = dq.front();
	int b = dq.back();
	
	cout << a << " " << b << endl;
	
	dq.erase(dq.begin()+1,dq.begin()+2);
	
	dq.pop_front();
	dq.pop_back();
	
	dq.resize(10);
	
	print(dq);
	
	dq.clear();
	
	print(dq);
	
}

int32_t main(){
	solve();
	return 0;
}