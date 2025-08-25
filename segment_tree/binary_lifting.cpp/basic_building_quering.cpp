
/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define vvi            vector<vi>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

void build_parent(vvi& parent,int n,int m){
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            parent[j][i]=parent[parent[j][i-1]][i-1];
        }
    }

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         bug(j,i,parent[j][i]);
    //     }
    // }
}


int query(vvi& parent,int node,int par,int i){
    if(par==0){return node;}

    int ans=query(parent,node,par>>1,i+1);
    
    if(par&1){
        ans=parent[ans][i];
    }
    return ans;
}



int query_itr(vvi& parent,int node,int par){
    stack<int> stk;
    int i=0;
    while(par){
        if(par&1){
            stk.push(i);
            // bug(stk.top());
        }
        par >>= 1;
        i++;
    }

    while(!stk.empty()){
        int t=stk.top();
        stk.pop();
        node=parent[node][t];
    }


    return node;
}


int query_itr2(vvi& parent,int node,int par,int m){
    for(int i=m-1;i>-1;i--){
        if(par & (1<<i)){
            node=parent[node][i];
        }
    }
    return node;
}


void solve() {
    //code here
    int n,q;
    cin >> n >> q;

    int m,levels;
        
    levels=13;
    m=ceil(float(log2(levels)));
    // bug(levels,m);

    vector<vi> parent(n,vi(m,0));
    

    for(int i=0;i<n;i++){
        cin >> parent[i][0];
        // bug(i,parent[i][0]);
    }

    build_parent(parent,n,m);

    int a,b;
    while(q--){
        cin >> a >> b;
        // int ans = query(parent,a,b,0);
        // int ans = query_itr(parent,a,b);
        int ans = query_itr2(parent,a,b,m);
        cout << ans << endl;
    }

}

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif 
}

int32_t main()
{    
    init_code();
    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}





/*
consider a test case :

x               :0 1 2 3 4 5 6 
parent[x]       :0 0 0 1 3 2 3


*/
