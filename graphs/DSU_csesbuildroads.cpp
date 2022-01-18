#include<bits/stdc++.h>

using namespace std;

//cses contructing road
struct str
{
	int cost;
	int a1, b1;

};
int par[100000 + 5];
int rnk[100000 + 5];
long long cnt = 0;
long long sum = 0; //one based index
void make_set(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		par[i] = i;
		rnk[i] = 1;
	}
}
int find_par(int a)
{
	if (par[a] == a)
		return a;
	return par[a] = find_par(par[a]);
}
void make_union(int a, int b, int wt)
{
	int p1 = find_par(a);
	int p2 = find_par(b);
	//cout << p1 << " " << p2 << endl;
	if (p1 == p2)
	{
		return ;
	}
	if (rnk[p1] > rnk[p2])
	{
		par[p2] = p1;
		rnk[p1] += rnk[p2];
	}
	else

	{
		par[p1] = p2;
		rnk[p2] += rnk[p1];
	}
	sum += wt;
	cnt++;

}
bool comp(str s1, str s2)
{
	return s1.cost < s2.cost;
}
void sol()
{
	int n, m, i, a, b, c;
	cin >> n >> m;
	str v[m];
	make_set(n);
	int mx = 1, ty = m;
	for (ty = 0; ty < m; ty++)
	{
		cin >> a >> b >> c;
		v[ty].cost = c;
		v[ty].a1 = a;
		v[ty].b1 = b;

	}
	sort(v, v + m, comp);
	/*fo(i, m)
	cout << v[i].cost;*/
	for ( i = 0; i < m; ++i)
	{
		a = v[i].a1;

		b = v[i].b1; int wt = v[i].cost;
		/*cout << a << " " << b << " " << wt << endl;*/
		make_union(a, b, wt);
		if (cnt == n - 1)
			break;
		//cout << cnt << endl;
	}

	if (cnt == n - 1)
	{
		cout << sum; return;
	}
	cout << "IMPOSSIBLE";
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
