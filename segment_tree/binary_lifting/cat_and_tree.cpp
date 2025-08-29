

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
    // bug(n,m);
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



int find_depth(vvi& parent,vi& depth,int node){
    if(parent[node][0]==node){
        return 1;
    }

    depth[node]=find_depth(parent,depth,parent[node][0])+1;
    // bug(node,depth[node]);
    return depth[node];
}




int lca(vvi& parent,vi& depth,int n,int m,int node1,int node2){
    int d1=depth[node1];
    int d2=depth[node2];

    int left,right,mid;
    right=min(d1,d2);
    left=1;
    mid=(left+right)/2;

    node1=query_itr2(parent,node1,d1-right,m);
    node2=query_itr2(parent,node2,d2-right,m);
    int ans=-1;
    // bug(left,mid,right,node1,node2);

    if(node1==node2){return node1;}

    while(left <= right){
        mid=(left+right)/2;
        // bug(left,mid,right);         

        int t1,t2;
        t1=query_itr2(parent,node1,depth[node1]-mid,m);
        t2=query_itr2(parent,node2,depth[node2]-mid,m);

        if(left==right){
            if(t1==t2){
                ans=t1;
            }
            break;
        }
        if(t1==t2){
            left=mid+1;
            ans=t1;
        }else{
            right=mid-1;
            int dpth=depth[node1];
            node1=query_itr2(parent,node1,dpth-right,m);
            node2=query_itr2(parent,node2,dpth-right,m);
        }
        // bug(t1,t2);
        // bug(node1,depth[node1]);
        // bug(node2,depth[node2]);
    }

    return ans;
}



int put_cat_and_move(vvi& parent,vi& depth,vector<bool>& placed,int n,int m,int node){
    if(placed[node]){return 0;}

    int top,bottom,mid,res_dpth,tnode;
    top=1;
    bottom=depth[node];
    res_dpth=bottom;
    tnode=node;
    // bug(node,top,bottom);

    while(top <= bottom){
        mid=(top+bottom)/2;
        int par=depth[tnode]-mid;
        int temp=query_itr2(parent,tnode,par,m);

        // bug(top,mid,bottom,temp);
        if(top==bottom){
            if(placed[temp]==false){
                res_dpth=bottom;
                tnode=temp;
                // bug(res_dpth,bottom,tnode);
            }
            // bug("breaking");
            break;
        }
        if(placed[temp]){
            top=mid+1;
        }
        else{
            bottom=mid-1;
            res_dpth=mid;
            tnode=temp;
        }
        // bug(tnode,res_dpth);
    }
    placed[tnode]=true;
    // bug(node,tnode,res_dpth,depth[node]);

    return depth[node]-res_dpth+1;
}



void solve() {
    //code here
    int n,q;
    cin >> n;
    // bug(n,q);

    int m,levels;
        
    levels=7;
    m=ceil(float(log2(levels)))+1;
    // bug(levels,m);

    vector<vi> parent(n,vi(m,0));
    vi depth(n,0);    
    vector<bool> placed(n,false);

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        parent[a][0]=b;
        // bug(a,b);
        // bug(a,b,parent[a][0]);
    }


    for(int i=0;i<n;i++){
        int dpth=find_depth(parent,depth,i);
        depth[i]=dpth;
        // bug(i,dpth);
        // bug(i,depth[i]);
        // bug(i,parent[i][0]);
    }

    build_parent(parent,n,m);

    cin >> q;
    int a=-1,b=-1,ans=-1;
    while(q--){
        cin >> a;
        // bug(q,a,b);

        ans = put_cat_and_move(parent,depth,placed,n,m,a);
        // cout << "ans : " << ans << endl << endl;
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

considering that the root is the parent of itself

node    : 0 1 2 3 4 5 6 7 8 9 10 
parent  : 0 0 1 2 3 3 1 6 6 6 1 
consider a test case :

input1:
11 
0 0
1 0
2 1 
3 2
4 3
5 3
6 1
7 6
8 6
9 6
10 1


5
7 7 7 7 7

output1:
4
3
2
1
0



input2:
11 
0 0
1 0
2 1 
3 2
4 3
5 3
6 1
7 6
8 6
9 6
10 1


5
4 2 9 6 7

output2:
5
2
2
0
1


*/
