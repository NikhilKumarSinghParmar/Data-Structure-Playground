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

// fenwick tree
// user handling 0 based indexing
// fenwick will convert it into 1 based index on its own
struct fenwick {
    vi fn;
    int n;

    void init(int n) {
        this->n = n + 2;
        fn.resize(this->n, 0);
    }

    void add(int x, int y) {
        x++; // shift to 1-based
        while (x < n) {
            fn[x] += y;
            x += (x & -x);
        }
    }

    int sum(int x) {
        x++; // shift to 1-based
        int ans = 0;
        while (x > 0) {
            ans += fn[x];
            x -= (x & (-x));
        }
        return ans;
    }

    void sum(int l, int r) {
        int lans,rans;
        rans = sum(r);
        lans = sum(l - 1);
        cout << rans - (l > 0 ? lans : 0) << endl;
    }
};



void solve() {
    // user handling 0 based indexing
    // fenwick will convert it into 1 based index on its own
    int n, m;
    cin >> n >> m;

    vi v(n);
    fenwick tree;
    tree.init(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        tree.add(i, v[i]); // 0-based
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            tree.sum(b, c);  //  0-based
        } else {
            tree.add(b, c);  //  0-based
        }
    }
}



int32_t main() {
    fast_io;
    solve();
    return 0;
}




// input :
// 10 2
// 1 2 3 4 5 6 7 8 9 10
// 1 2 6
// 1 3 6



// output:
// 25
// 22
