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
int n, q;
//CSES Subtree Queries
//really good problem
//first tree to array using dfs and pushback with cnt array
//then fenwick tree or bit application!!

std::vector<std::vector<int> > adj;
std::vector<int> vec, cnt;
int a[200000 + 5], bit[200000 + 5];
void update(int k, int val)
{
	while (k <= n)
	{
		bit[k] +=  val ;
		k += (k & (-k));

	}
}
int sum(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += (bit[x]);
		x -= (x & (-x));
	}
	return res;
}
int query(int l, int r)
{
	return  sum(r) - sum(l - 1) ;
}
void dfs(int node, int par)
{
	cnt[node] = 1;
	vec.pb(node);
	for (int i = 0; i < adj[node].size(); i++)
	{
		int child = adj[node][i];
		if (child == par) continue;
		dfs(child, node);
		cnt[node] += cnt[child];
	}
}
void sol()
{

	cin >> n >> q; adj.resize(n), cnt.assign(n, 0);
	clr(bit);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0, 0);
	/*	for (int i = 0; i < vec.size(); ++i)
		{
			//node number				value				count
			cout << vec[i] + 1 << " " << a[vec[i]] << " " << cnt[vec[i]] << endl;
		}*/
	int pos[vec.size()];//position of that node in vec


	for (int i = 1; i <= n; i++)
	{
		pos[vec[i - 1]] = i - 1;
		update(i, a[vec[i - 1]]);
	}
	/*	for (int i = 1; i <= n; i++)
		{
			//bit is built right
			cout << bit[i] << " ";
		} cout << "\n\n";*/
	while (q--)
	{
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			int node, val;
			cin >> node >> val; node--;
			//pos of node-1 and its value in vec
			int position = pos[node ];// cout << a[position] << endl;
			update(position + 1, val - a[node]);
			a[node] = val;
		}
		else
		{
			int node;
			cin >> node; node--;
			int position = pos[node ];
			//cout << a[position] << endl;
			cout << query(position + 1 , position + cnt[node] ) << endl;

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
