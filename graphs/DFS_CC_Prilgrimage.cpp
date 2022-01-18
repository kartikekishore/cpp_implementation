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
#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second
#define all(x)          x.begin(), x.end()
#define clr(x)          memset(x, 0, sizeof(x))
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
//=======================
int prig_Energy[100005];
int depth[100005];
int cst[100005];
vector<std::vector<pii>>adj(100005);
//DFS codechef Pilgrimage
void dfs(int u, int par)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        int child = adj[u][i].F;
        if (child == par) continue;

        depth[child] = depth[u] + 1;
        // cout << "par->" << u << " " << "ch->" << child << endl;
        int tmp = (int)(depth[u] * (adj[u][i].S));

        cst[child] = min(cst[child], cst[u] + tmp);
        dfs(child, u);
    }
}
void sol()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    int i; fo(i, m)cin >> prig_Energy[i];
    std::vector<int> coming(n, 0);
    fo(i, n - 1)
    {
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        coming[u]++; coming[v]++;
        adj[u].pb({v, k});
        adj[v].pb({u, k});
    }


    cst[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cst[i] = inf;
    }
    depth[0] = 1;
    dfs(0, -1);
    std::vector<int> costans;
    for (int i = 1; i < n; i++)
    {
        if (coming[i] == 1)
        {

            costans.pb(cst[i]);
        }
    }
    sort(costans.rbegin(), costans.rend());
    sort(prig_Energy, prig_Energy + m);
    reverse(prig_Energy, prig_Energy + m);
    i = 0; int j = 0;
    int ans = 0;
    for (i = 0; i < costans.size(); i++)
    {
        if (j < m && prig_Energy[j] >= costans[i])
        {
            j++;
            ans++;
        }
    }
    cout << ans << endl;
    adj.clear();



}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(t)
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
