#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //Policy Based Data Structure
// using namespace __gnu_pbds;              //Policy Based Data Structure
using namespace std;

const int MAX = 100005;
int par[100005];
int rnk[100005];
//hackerrankging commmunitiess
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
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
	int n, q;
	cin >> n >> q;
	make_set(n);
	while (q--)
	{
		char ch;
		cin >> ch;
		if (ch == 'M')
		{
			int a, b;
			cin >> a >> b;
			union_set(a, b);
		}
		else {
			int a;
			cin >> a;
			int representative = find_par(a);
			cout << rnk[representative] << '\n';
		}
	}
}
int main() {

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	sol();

	return 0;
}