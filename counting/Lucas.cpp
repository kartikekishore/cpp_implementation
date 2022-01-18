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
const int mod = 999983;
// const int N = 3e5, M = N;
// vi g[N];
//=======================
//Constructing binary strings hackerearth
//https://www.hackerearth.com/problem/algorithm/binary-string-construction-c31f511d/
int fact[1000005], fact_inv[1000005];
void pre()
{
	fact[0] = 1;
	fact_inv[0] = 1;
	for (int i = 1; i < 1000005; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		fact_inv[i] = mpow(fact[i], mod - 2);
	}
}
int ncr(int n, int r) {
	if (n < r) {return 0;}
	if (n == r || r == 0) {return 1;}
	return (((fact[n] * fact_inv[n - r]) % mod) * fact_inv[r]) % mod;
	//return x;
}
int ncr_lucas(int n, int r, int m)
{
	if (r == 0)return 1;
	return (ncr(n % m, r % m) * ncr_lucas(n / m, r / m, m)) % m;
}
void sol()
{

	int on, zr;
	cin >> zr >> on;
	if (zr > on)
	{
		cout << 0 << endl;
		return;
	}
	else
	{
		cout << (ncr_lucas(zr + on, on, 999983) -  ncr_lucas(zr + on, on + 1, 999983) + mod) % mod << endl;
	}

}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pre();
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

