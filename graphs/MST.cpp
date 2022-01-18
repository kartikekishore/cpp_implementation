#include <bits/stdc++.h>

using namespace std;

#define fo(i,n)         for(i=0;i<n;i++)

int par[200000 + 4];//Do change the constraints as per question
int rnk[200000 + 4];
int totweigth = 0;
//MINIMUM SPANNING TREE
struct  graph
{
    int a, b, wt;

};
bool comp(graph g1, graph g2)
{
    return g1.wt < g2.wt;
}
void make_set(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        par[i] = i;
        rnk[i] = 1;
    }
}
int find_par(int n)
{
    if (par[n] == n )
    {
        return n;
    }
    return par[n] = find_par(par[n]);
}
void make_union(int a, int b, int wt)
{
    int p1 = find_par(a);
    int p2 = find_par(b);
    if (p2 == p1)
        return;

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
    totweigth += wt;
}
void sol()
{
    int n, i, m;
    cin >> n >> m;
    make_set(n);
    graph g[m];
    fo(i, m)
    {
        cin >> g[i].a >> g[i].b >> g[i].wt;


    }
    sort(g, g + m, comp);
    fo(i, m)
    {
        int a = g[i].a, b = g[i].b, wt = g[i].wt;
        make_union(a, b, wt);
    }
    cout << totweigth;


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sol();
    return 0;
}