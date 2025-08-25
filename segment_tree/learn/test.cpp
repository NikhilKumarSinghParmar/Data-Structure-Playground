#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define vi vector<int>
#define vvi vector<vi>
#define int long long int

struct sgt{
	vi st;
	int n;

	void init(int n){
		this->n=n;
		st.resize(4*n);
	}

	void build(int start,int end,int node,vi& v){
		// leaf node
		if(start==end){
			st[node] = v[start];
			return;
		}

		int mid = (start+end)/2;
		//left subtree
		build(start, mid,node*2+1,v);
		// right subtree
		build(mid+1,end,node*2+2,v);

		st[node] = st[node*2+1] + st[node*2+2];
	}

	void build(vi& v){
		build(0,v.size()-1,0,v);
	}

	void print_tree(){
		int m = st.size();

		for(int i=0;i<m;i++){
			cout << i << " -> " << st[i] << endl;
		} 
	}

	int query(int s,int e,int l,int r,int node){
		int mid = (s+e)/2;

		if(l<=s && r>=e){
			return st[node];
		}else if(r < s || e < l){
			return 0;
		}
		int q1 = query(s,mid,l,r,node*2+1);
		int q2 = query(mid+1,e,l,r,node*2+2);

		return q1 + q2; 
	}


	void query(int start,int end){
		int ans = query(0,n-1,start,end,0);
		cout << "ans : " << ans << endl;
	}

	void update(int s,int e,int ind,int val,int node){
		if(s==e){
			st[node] = val;
			return;
		}

		int mid = (s + e)/2;
		if(ind <= mid){
			update(s,mid,ind,val,node*2+1);
		}else{
			update(mid+1,e,ind,val,node*2+2);
		}

		st[node] = st[node*2+1] + st[node*2+2];
		
	}

	void update(int ind,int val){
		update(0,n-1,ind,val,0);
	}
};


void solve(){
	int n;
	cin >> n;
	vi v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	sgt tree;
	tree.init(n);
	tree.build(v);

	// tree.print_tree();
	int m = 1;
	cin >> m;
	for(int i=0;i<m;i++){
		int a,b,c,d;
		cin >> a >> b;
		tree.update(a,b);
		cin >> c >> d;
		tree.query(c,d);
	}
}


int32_t main(){

	int t=1;
	// cin >> t:
	while(t--){
		solve();
	}

	return 0;
}