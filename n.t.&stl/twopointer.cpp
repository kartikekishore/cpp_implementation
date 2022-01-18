#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //Policy Based Data Structure
// using namesumace __gnu_pbds;              //Policy Based Data Structure
using namespace std;
// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //Policy Based Data Structure
// #define gc              getchar_unlocked
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int, vi, greater<int> >
// #define mk(arr,n,type)  type *arr = new type[n]
#define fo(i,n)         for(i=0;i<n;i++)
#define Fo(i,k,n)       for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
typedef long long ll;
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
//D. Cleaning the Phone codeforces
//use lowerbound
void sol()
{	ll n, m;
	cin >> n >> m;
	vector<int>a(n);
	vector<int>b(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	if (sum < m) {
		cout << -1 << "\n";
		return;
	}
	vector<int>c, d;
	for (int i = 0; i < n; i++) {
		if (b[i] == 1) c.push_back(a[i]);
		else d.push_back(a[i]);
	}
	// a has for 1s value and b has for 2s value
	sort(c.rbegin(), c.rend());
	sort(d.rbegin(), d.rend());
	ll ans = 1e9;
	int x = c.size();
	int y = d.size();
	vector<ll>ok(y + 1);
	for (int i = 0; i < y; i++) {
		ok[i + 1] = ok[i] + d[i];
	}
	ll total = 0;
	int pos = lower_bound(ok.begin(), ok.end(), m) - ok.begin();
	if (pos < y + 1) {
		ans = min(ans, pos * 2LL);
	}
	for (int i = 0; i < x; i++) {
		ll count = i + 1;
		total += c[i];
		ll left = m - total;
		if (left > 0) {
			pos = lower_bound(ok.begin(), ok.end(), left) - ok.begin();
			if (pos >= y + 1) continue;
			count += (pos * 2);
		}
		ans = min(ans, count);
	}
	cout << ans << "\n";
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
// void dfs(int u, int par){
//     for(int v:g[u]){
//         if (v == par) continue;
//         dfs(v, u);
//     }
// }