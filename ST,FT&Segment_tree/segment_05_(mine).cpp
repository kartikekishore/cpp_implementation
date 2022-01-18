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
//segment tree
//
std::vector<int> a;
std::vector<int > st, lazy;
int n; int k;
void upd(int id, int l, int r, int val)
{
	st[id] += val;
	lazy[id] += val;
}
void shift(int id, int l, int r)
{
	if (lazy[id] == 0)return;

	int mid = (l + r) / 2;
	upd(id * 2, l, mid, lazy[id]);
	upd(id * 2 + 1, mid, r, lazy[id]);
	lazy[id] = 0;
}
void build(int id = 1, int l = 0, int r = n)
{
	if (r - l == 1)
	{
		st[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}
int query(int x, int y, int id = 1, int l = 0, int r = n)
{
	if (l >= y || r <= x)
	{
		return inf;
	}
	if (l >= x && r <= y)
	{
		return st[id] ;
	}
	int mid = (l + r) / 2;
	shift(id, l, r);
	int l_ans = query(x, y, id * 2, l, mid);
	int r_ans = query(x, y, id * 2 + 1, mid, r);
	return min(r_ans , l_ans) ;
}
void increase(int x, int y, int val, int id = 1, int l = 0, int r = n)
{
	if (l >= y || r <= x)return ;

	if (l >= x && r <= y)
	{
		upd(id, l, r, val);
		return ;
	}
	int mid = (l + r) / 2;
	shift(id, l, r);
	increase(x, y, val, id * 2, l, mid);
	increase(x, y, val, id * 2 + 1, mid, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}
void sol()
{
	int m;
	cin >> n >> m;
	a.assign(n + 1, 0);
	st.resize(4 * n + 1); lazy.resize(4 * n + 1);
	build();
	while (m--)
	{
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			int l, r, val;
			cin >> l >> r >> val;
			increase(l, r, val);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << endl;
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