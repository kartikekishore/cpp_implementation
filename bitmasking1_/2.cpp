//ⓀⒶⓇⓎ
#include <bits/stdc++.h>

using namespace std;
long long int a[25][25];

long long int n, m;
long long int dp[1 << 20 + 1];
long long int fun( long long int mask)
{
   if ( __builtin_popcount(mask) >= n)return 1;
   long long int i = __builtin_popcount(mask) ;
   if (dp[mask] != -1)return dp[mask];
   long long int ans = 0;
   for (long long int j = 0; j < n; j++)
   {
      if (a[j][i] == 1)
      {
         long long int reqmask = (mask & 1 << j);
         if (reqmask == 0)
         {
            ans += fun( mask | (1 << j));
         }
      }
   }
   return dp[mask] = ans;
}
void sol()
{

   cin >> n ;
   for (long long int i = 0; i < n; i++)
   {
      for (long long int j = 0; j < n; j++)
      {
         cin >> a[i][j];

      }
   }
   for (long long int j = 0; j <= (1 << 20); j++)
      dp[j] = -1;


   cout << fun( 0) << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int t = 1;
   cin >> t;
   while (t--)
      sol();
   return 0;
}