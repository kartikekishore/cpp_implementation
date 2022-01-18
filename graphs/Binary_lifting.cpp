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
//cses company queries and BINARY LIFTING
std::vector<std::vector<int> > g;
int parent[200000][30 + 1];
void binary_lifting(int i, int par)
{

	parent[i][0] = par;
	for (int j = 1; j <= 30; j++)
	{
		parent[i][j] = parent[parent[i][j - 1]][j - 1];
	}
	for (int j = 0; j < g[i].size(); j++)
	{
		if (g[i][j] != par)
			binary_lifting(g[i][j], i);
	}

}
int find_par(int i, int pr)
{

	for (int j = 30; j >= 0; j--)
	{
		if (i == -1)
			return -2;
		if (pr <= 0)
			return i;
		if ((1 << j)&pr)
		{
			i = parent[i][j];
			pr -= (1 << j);
		}
	}


	return i;
}
std::vector<int> depth;
void dfs(int i, int par)
{
	for (int j = 0; j < g[i].size(); j++)
	{


		if (g[i][j] != par)
		{
			depth[g[i][j]] = depth[i] + 1;
			dfs(g[i][j], i);
		}
	}
}
void sol()
{
	memset(parent, -1, sizeof(parent));
	int n, q;
	cin >> n >> q;
	int m = n - 1;
	g.resize(n ); depth.assign(n, 0);
	int i;
	for (i = 1; i <= n - 1; i++)
	{
		int u = i , v;
		cin >> v; v--;

		g[u].pb(v);
		g[v].pb(u);
	}
	depth[0] = 0;
	dfs(0, -1);


	binary_lifting(0, -1);
	/*fo(i, n)cout << depth[i];*/
	while (q--)
	{

		int u, pt;
		cin >> u >> pt;
		u--;
		if (depth[u] < pt) {
			cout << -1 << endl; continue;
		}
		cout << find_par(u, pt) + 1 << endl;
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