// Problem : Range Update Queries
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1651
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp> */ // Including tree_order_statistics_node_update
#define int long long
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define db1(x) cout << #x << "=" << x << endl
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z)                                                       \
  cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define dbp(x) \
  cout << #x << "= {" << (x.first) << ", " << (x.second) << "}" << endl;
#define dbv(v)                         \
  {                                    \
    cout << #v << " : ";               \
    for (auto x : v) cout << x << ' '; \
    cout << endl;                      \
  }
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, a, b) for (int i = a; i >= b; i--)
#define die(x) return cout << x << '\n', 0;


using namespace std;



typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

vi bit;
int n;

void upd(int i, int val) {
  while (i <= n) {
    bit[i] += val;
    i += i & (-i);
  }
}

void upd(int l, int r, int val) {
  upd(l, val);
  upd(r + 1, -val);
}

void build(const vi& vec) {
  bit.assign(n + 2, 0);
  rep(i, 1, n) { upd(i, i, vec[i]); }
}

int query(int x) {
  int ans = 0;
  while (x > 0) {
    ans += bit[x];
    x -= x & (-x);
  }
  return ans;
}

int32_t main() {
  fastio;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int testcases;
  testcases = 1;
  // cin >> testcases;

  while (testcases--) {
    int q;
    cin >> n >> q;
    vi vec(n + 1);
    rep(i, 1, n) cin >> vec[i];
    build(vec);
    int type, l, r, k;
    while (q--) {
      cin >> type;
      if (type == 1) {
        cin >> l >> r >> k;
        upd(l, r, k);
      } else {
        cin >> k;
        cout << query(k) << '\n';
      }
    }
  }

  return 0;
}