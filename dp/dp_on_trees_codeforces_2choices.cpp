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

const int mod = 1000000007;
// const int N = 3e5, M = N;
// vi g[N];
//=======================
//codeforces Parsa's Humongous Tree
int val[100000 + 5][2];
vector<vector<int> >g;
vector<vector<int>>dp;
int dfs(int u, int par, int choice)
{
	int temp = 0;
	if (dp[u][choice] != -1)
	{
		return dp[u][choice];
	}
	for (int v : g[u])
	{
		if (v == par) continue;
		int ans1 = abs(val[u][choice] - val[v][0]) + dfs(v, u, 0);
		int ans2 = abs(val[u][choice] - val[v][1]) + dfs(v, u, 1);;
		temp += max(ans1, ans2);
		/*dfs(v, u);*/
	}
	return dp[u][choice] = temp;
}
void sol()
{
	int n;
	cin >> n;
	int l, i, r;
	dp.resize(n, vector<int>(2));
	g.resize(n);
	fo(i, n)
	{
		cin >> l >> r;
		val[i][0] = l, val[i][1] = r;
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	fo(i, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[v].pb(u);
		g[u].pb(v);
	}
	int ans1 = dfs(0, -1, 0);
	int ans2 = dfs(0, -1, 1);
	cout << max(ans1, ans2) << endl;

}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(t)
	{
		g.clear();
		dp.clear();
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