#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;

ll count(int coins[], int sum)
{
    ll n = 3;//size of array
    ll dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}
int main()
{
    int coin[] = {1, 2, 3};
    int sum = 5;
    cout << count(coin, sum) << endl;
}