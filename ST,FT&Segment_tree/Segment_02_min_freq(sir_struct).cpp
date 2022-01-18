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
//sir method
//minimum in the range, also its count(freq) and modify a[pos] to val
std::vector<int> a;

int n;
struct seg
{
	int mini;
	int cnt;
};
std::vector<seg> st;
seg create(int val)
{
	seg temp;
	temp.mini = val;
	temp.cnt = 1;
	return temp;
}
seg combine(seg x, seg y)
{
	seg temp;
	if (x.mini == y.mini)
	{
		temp.cnt = (x.cnt + y.cnt);
		temp.mini = x.mini;
		return temp;
	}
	if (x.mini < y.mini)
	{
		temp.cnt = (x.cnt);
		temp.mini = x.mini;
		return temp;
	}
	else
	{
		temp.cnt = (y.cnt);
		temp.mini = y.mini;
		return temp;
	}
}
void build(int id = 1, int l = 0, int r = n)
{
	if (r - l == 1)
	{
		st[id] = create(a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid); //left child
	build(2 * id + 1, mid, r); //right child
	st[id] = combine(st[id * 2], st[id * 2 + 1]);
}
seg query(int x, int y, int id = 1, int l = 0, int r = n)
{
	if (l >= x && r <= y)
	{
		//entirely inside
		return st[id];
	}
	if (l >= y || r <= x)
	{
		//entirely outside
		return create(inf);
	}
	int mid = (l + r) / 2;
	seg l_ans = query(x, y, 2 * id, l, mid);
	seg r_ans = query(x, y, 2 * id + 1, mid, r);
	return combine(l_ans, r_ans);

}
void modify(int pos, int val, int id = 1, int l = 0, int r = n)
{
	if (r - l == 1)
	{
		a[pos] = val;
		st[id].mini = val;
		return;
	}
	int mid = (l + r) / 2;
	if (pos < mid)
		modify(pos, val, id * 2, l, mid);
	else
		modify(pos, val, id * 2 + 1, mid, r);
	st[id] = combine(st[2 * id], st[2 * id + 1]);
}
void sol()
{
	int m;
	cin >> n >> m;
	a.resize(n);
	st.resize(4 * n + 1);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	build();
	while (m--)
	{
		int c;
		cin >> c;
		if (c == 1)
		{
			int p, val;
			cin >> p >> val;
			modify(p, val);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			seg p = query(l, r);
			cout << p.mini << " " << p.cnt << endl;
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