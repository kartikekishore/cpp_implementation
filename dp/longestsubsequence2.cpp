#include <bits/stdc++.h>

using namespace std;
//Longest subsequence dp problem codechef!!
void sol()
{
	int n, i;
	cin >> n;
	int height[n], iq[n];
	std::vector<int> dp(n);
	for (i = 0; i < n; i++)cin >> height[i];
	for (i = 0; i < n; i++)cin >> iq[i];
	int ans = 1;
	dp[0] = 1;
	for (i = 0; i < n; i++)
	{
		int tmepans = 0;
		int prev_height = height[i], prev_iq = iq[i];
		for (int j = 0; j < i; j++)
		{
			if (height[j] < prev_height && iq[j] > prev_iq)
			{
				tmepans = max(tmepans, dp[j]);

			}

		}
		dp[i] = tmepans + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
		sol();
	return 0;
}