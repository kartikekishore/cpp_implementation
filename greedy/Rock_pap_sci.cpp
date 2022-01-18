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
// greedy question
// i have used an ans string to store answers first and checked if it is filled
// if not filled i have stored any randon value...
// B. Restricted RPS   no.of max wins...

void sol()
{
	w(t)
	{
		int n, r, p, i, s;
		cin >> n >> r >> p >> s; // R P S
		char str[n];
		fo(i, n)cin >> str[i];
		int wins = 0;
		int r1, p1, s1;
		r1 = r; p1 = p; s1 = s;
		fo(i, n)
		{
			if (str[i] == 'R' && p > 0)
			{
				wins++;
				p--;
			}

			if (str[i] == 'S' && r > 0)
			{
				r--;
				wins++;
			}
			if (str[i] == 'P' && s > 0)
			{
				s--;
				wins++;
			}

		}

		if (wins < (n + 1) / 2)
		{
			cout << "NO" << '\n';
		}
		else
		{
			std::vector<char> ans(n, ' ');
			cout << "YES" << '\n'; s = s1; r = r1; p = p1;
			bool check[n] = {false};
			fo(i, n)
			{
				if (str[i] == 'R' && p > 0)
				{
					p--; ans[i] = 'P'; check[i] = true;

				}
				else if (str[i] == 'S' && r > 0)
				{
					r--;
					ans[i] = 'R'; check[i] = true;
				}
				else if (str[i] == 'P' && s > 0)
				{
					s--;
					ans[i] = 'S'; check[i] = true;
				}


			}
			fo(i, n)
			{
				if (check[i] == false)
				{
					if (r > 0) {
						ans[i] = 'R'; r--;
					}
					else if (p > 0)
					{
						ans[i] = 'P'; p--;
					}
					else
					{
						ans[i] = 'S'; s--;
					}
				}
			}
			fo(i, n)cout << ans[i];
			cout << '\n';

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
/*w(t)
	{
		int n, r, p, s, i, wins = 0;

		cin >> n >> r >> p >> s; cout << r << p << s;
		char str[n];
		fo(i, n)
		cin >> str[i];
		int r1 = r, p1 = p, s1 = s; int pwins = 0, rwins = 0, swins = 0;
		wins = 0;
		fo(i, n)
		{
			char ch = str[i];
			if (ch == 'R' && p > 0)
			{

				p--; wins++; pwins++;



			}
			else if (ch == 'p' && s > 0)
			{

				s--; wins++; swins++;


			}
			else//s
			{
				if (r > 0)
				{
					r--; wins++; rwins++;
				}


			}

		} cout << wins;
		int tri = (n % 2 == 0 ? n / 2 : (n + 1) / 2);
		if (wins < tri)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
			fo(i, n)
			{
				char ch = str[i];
				if (ch == 'R')
				{
					if (p1 > 0)
					{
						cout << "P" << " ";
						p1--; pwins--;
					}
					else if (rwins == 0 && r1 > 0)
					{
						cout << "R" << " "; r1--;

					}
					else if (swins == 0 && s1 > 0)
					{
						cout << "S" << " "; s1--;

					}
					else if (r1 > 0)
					{
						cout << "R" << " "; r1--;
					}
					else
						cout << "S" << " "; s1--;




				}
				else if (ch == 'p')
				{
					if (s1 > 0)
					{
						cout << "S" << " ";
						s1--; swins--;
					}
					else if (pwins == 0 && p1 > 0)
					{
						cout << "P" << " "; p1--;

					}
					else if (rwins == 0 && r1 > 0)
					{
						cout << "R" << " "; r1--;

					}
					else if (p1 > 0)
					{
						cout << "P" << " "; p1--;
					}
					else
						cout << "R" << " "; r1--;

				}
				else//s
				{
					if (r1 > 0)
					{
						cout << "R" << " ";
						r1--; rwins--;
					}
					else if (pwins == 0 && p1 > 0)
					{
						cout << "P" << " "; p1--;

					}
					else if (swins == 0 && s1 > 0)
					{
						cout << "S" << " "; s1--;

					}
					else if (p1 > 0)
					{
						cout << "P" << " "; p1--;
					}
					else
						cout << "S" << " "; s1--;


				}


			} cout << '\n';

		}
	}*/