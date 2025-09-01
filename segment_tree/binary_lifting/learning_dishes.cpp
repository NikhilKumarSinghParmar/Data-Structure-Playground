

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
        for(int j=1;j<=n;j++){
            parent[j][i]=parent[parent[j][i-1]][i-1];
        }
    }

    // for(int i=0;i<m;i++){
    //     for(int j=1;j<=n;j++){
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



void check_query(vvi& parent,int m){
    int a,b;
    a=5,b=2;


    for(int i=0;i<5;i++){
        int ans=query_itr2(parent,a,i,m);
        cout <<  ans << endl;
    }
}


int find_depth(vvi& parent,vi& depth,int node){
    if(parent[node][0]==node){
        return 1;
    }

    depth[node]=find_depth(parent,depth,parent[node][0])+1;
    // bug(node,depth[node]);
    return depth[node];
}



pii update_weight_and_count(vvi& parent,vi& weight,vi& count,int node){
    if(parent[node][0]==node || count[node]!=-1){
        if(parent[node][0]==node) {
            count[node]=1;
        }
        return {weight[node],count[node]};
    }

    pii p=update_weight_and_count(parent,weight,count,parent[node][0]);
    int w,cnt;
    w=p.F;
    cnt=p.S;

    if(w < weight[node]){
        count[node]=cnt+1;
    }else{
        weight[node]=w;
        count[node]=cnt;
    }
    
    return {weight[node],count[node]};
}


int learning_dishes(vvi& parent,vi& weight,vi& count,vi&depth,int m,int node,int wght){
    int left,right,mid,res_level=-1;
    int ans=-1;
    left=1;
    right=depth[node];
    // bug(node,left,right);


    // finding the first greatest number 
    while(left <= right){
        mid=(left+right)/2;

        int par,temp;

        par=depth[node]-mid;
        temp=query_itr2(parent,node,par,m);

        // bug(depth[node],mid,par,temp);
        // bug(left,mid,right);
        // bug(temp,weight[temp],count[temp]);


        if(left==right){
            if(weight[temp] > wght){
                res_level=left;
                ans=temp;
            }
            break;
        }

        if(weight[temp] > wght){
            ans=temp;
            res_level=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
        // bug(ans,res_level);
    }
    // bug(ans,res_level);

    if(ans!=-1){
        return count[node]-count[ans]+1;
    }

    return 0;
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

    vector<vi> parent(n+1,vi(m,0));
    vi depth(n+1,0);    
    vector<bool> placed(n+1,false);
    vi weight(n+1,0);
    vi count(n+1,-1);

    for(int i=0;i<n;i++){
        int a,b,w;
        cin >> a >> b >> w;
        parent[a][0]=b;
        weight[a]=w;
        // bug(a,b,w);
        // bug(a,parent[a][0],weight[a]);
    }


    for(int i=1;i<=n;i++){
        int dpth=find_depth(parent,depth,i);
        depth[i]=dpth;
        // bug(i,dpth);
        // bug(i,depth[i]);
        

        pii p=update_weight_and_count(parent,weight,count,i);
        weight[i]=p.F;
        count[i]=p.S;
        // bug(i,weight[i],count[i]);

        // bug(i,parent[i][0]);
    }

    build_parent(parent,n,m);

    // check_query(parent,m);

    cin >> q;
    int a=-1,b=-1,ans=-1;
    while(q--){
        cin >> a >> b;
        // bug(q,a,b);

        ans = learning_dishes(parent,weight,count,depth,m,a,b);
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

node    : 1 2 3 4 5
parent  : 1 1 2 2 3
weight  : 2 3 4 4 5
consider a test case :

input1:
5
1 1 2
2 1 3
3 2 4
4 2 4
5 3 5


5
5 4
3 1
4 1
4 2
5 0

output1:
1
3
3
2
4




input2:
5
1 1 2
2 1 3
3 2 4
4 2 4
5 3 5


3
5 0
3 0
4 0

output2:

4
3
3



*/
