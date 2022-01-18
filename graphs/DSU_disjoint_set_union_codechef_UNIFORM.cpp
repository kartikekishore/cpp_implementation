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
const int mod = 998244353;
// const int N = 3e5, M = N;
// vi g[N];
//=======================
//codechef UNIFORM lunch time question_
//DSU c groupps finding the no. of disjoint grps
//https://www.codechef.com/LTIME94A/problems/UNICOLOR
int par[100005], rnk[100005];
void make_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rnk[i] = 1;
    }
}
int find_par(int x)
{
    if (par[x] == x)
        return  x;

    par[x] = find_par(par[x]);
    return par[x];
}
void union_set(int a, int b)
{
    int p1 = find_par(a);
    int p2 = find_par(b);
    //cout << " l" << p1 << p2 << " di";
    if ( p1 == p2) {
        return;
    }
    if (rnk[p1] > rnk[p2])
    {
        par[p2] = p1;
        rnk[p1] = rnk[p1] + rnk[p2];
    } else
    {
        par[p1] = p2;
        rnk[p2]  = rnk[p1] + rnk[p2];
    }
}
void sol()
{
    int c, n, m;
    cin >> c >> n >> m;
    std::vector<pair<int, pii> > v;

    make_set(c);
    for (int i = 0; i < c; ++i)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int l, r;
            cin >> l >> r;
            v.pb({l, {r, i}});
        }
    }
    sortall(v);
    int prev_r = 0, res = 0, prev_l = 0, pre_club;

    for (int i = 0; i < v.size(); ++i)
    {
        int l = v[i].F, r = v[i].S.F;
        int clb = v[i].S.S;
        if (prev_r >= l)
        {
            union_set(clb, pre_club);
            prev_r = max(prev_r, r);
        }
        else
        {
            res += (l - prev_r - 1);
            pre_club = clb; prev_r = r, prev_l = l;
        }

    }
    res += (n - prev_r );
    set<int>st;
    for (int i = 0; i < c; i++)
    {
        st.insert(par[i]);
        //cout << par[i] << " ";
    }
    cout << mpow(m, st.size() + res) << endl;



}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(t)
    {

        sol();
    }

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