#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define all(a) a.begin(),a.end()
#define vi vector<int>

// min_heap and max_heap depends on b not a
class compare{
public:
	bool operator()(int& a,int& b){
		//return a > b;  // min_heap;
		return a < b;  // max_heap;
	}
};

template<typename t>
void print(t heap){
	while(!heap.empty()){
		cout << heap.top() << " " ;
		heap.pop();
	}cout << endl << endl;
}


void solve(){
	vi v = {1,2,3,4,5,6,7,8,9,10};
	int n = v.size();
	
	priority_queue<int> max_heap;
	priority_queue<int,vector<int>,greater<int>> min_heap;
	priority_queue<int, vi , compare > heap;
	
	for(auto t : v){
		max_heap.push(t);
		min_heap.push(t);
		heap.push(t);
	}
	
	cout << "max heap : " << endl;
	print(max_heap);
	cout << "min heap : " << endl;
	print(min_heap);
	cout << "comparator based heap : " << endl;
	print(heap);
}


int main(){
	solve();
	
	return 0;
}