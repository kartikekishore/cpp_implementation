#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //Policy Based Data Structure
// using namespace __gnu_pbds;              //Policy Based Data Structure
using namespace std;
// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //Policy Based Data Structure
// #define gc              getchar_unlocked
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int, vi, greater<int> >
// #define mk(arr,n,type)  type *arr = new type[n]
#define fo(i,n)         for(i=0;i<n;i++)
#define Fo(i,k,n)       for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int             long long
#define endl            '\n'
#define w(t)            int t; cin>>t; while(t--)
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x,y)       cout << #x << "=" << x << "," << #y << "=" << y << endl
void print(bool n) {
    if (n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second
#define all(x)          x.begin(), x.end()
#define clr(x,val)      memset(x, val, sizeof(x))
#define sortall(x)      sort(all(x))
#define tr(it,a)        for(auto it = a.begin(); it != a.end(); it++)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define PI              3.1415926535897932384626
#define inf             1e18
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());  //Random Shuffler
typedef pair<int, int>   pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
typedef map<int, int>    mii;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
// const int N = 3e5, M = N;
// vi g[N];
// no of prime numbers in range : (70,19) , (1000,168), (100000,1229) , (sqrt(10^9),3409)
//=======================
//B. Multiplication and Sum Codeforces lazy Propagation!!
std::vector<int> a, seg;
std::vector<int> lazy;
int n, m;
void build(int id = 1, int l = 0, int r = n)
{
    if (r - l == 1)
    {
        seg[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid); //left child
    build(2 * id + 1, mid, r); //right child
    seg[id] = (seg[id * 2] + seg[id * 2 + 1]) % mod;
}
void upd(int id, int l, int r, int val)
{
    seg[id] *= val;
    seg[id] %= mod;
    lazy[id] *= val;
    lazy[id] %= mod;
}
void shift(int id, int l, int r)
{
    if (lazy[id] == 1)return ;
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, lazy[id]);
    upd(id * 2 + 1, mid, r, lazy[id]);
    lazy[id] = 1;
}
int query(int x, int y, int id = 1, int l = 0, int r = n)
{
    if (l >= x && r <= y)
    {
        //entirely inside
        return seg[id];
    }
    if (l >= y || r <= x)
    {
        //entirely outside
        return 0;
    }
    int mid = (l + r) / 2;
    shift(id, l, r);
    int l_ans = query(x, y, 2 * id, l, mid);
    int r_ans = query(x, y, 2 * id + 1, mid, r);
    return (l_ans + r_ans) % mod;

}
void increase(int x, int y, int val, int id = 1, int l = 0, int r = n)
{
    if (l >= x && r <= y)
    {
        //entirely inside
        // seg[id] *= val;
        // lazy[id] *= val;
        upd(id, l, r, val);
        return;
    }
    if (l >= y || r <= x)
    {
        //entirely outside
        return ;
    }
    shift(id, l, r);
    int mid = (l + r) / 2;
    increase( x, y, val, 2 * id, l, mid);
    increase( x, y, val, 2 * id + 1,  mid, r);
    seg[id] = (seg[id * 2] + seg[id * 2 + 1]) % mod;

}



void sol()
{

    cin >> n >> m;
    a.resize(n);
    a.assign(n, 1);
    // cout << a[4];
    lazy.resize(4 * n + 1);
    lazy.assign(4 * n + 1, 1);
    seg.resize(4 * n + 1);

    build();
    while (m--)
    {
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            increase(l, r, v);
        }
        else
        {
            int  l, r;
            cin >> l >> r;
            cout << query(l, r) % mod << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    sol();

    return 0;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// void ipgraph(int n, int m){
//     int i, u, v;
//     while(m--){
//         cin>>u>>v;
//         g[u-1].pb(v-1);
//         g[v-1].pb(u-1);
//     }
// }
//
// void dfs(int u, int par){
//     for(int v:g[u]){
//         if (v == par) continue;
//         dfs(v, u);
//     }
// }