#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

int count(int coins[], int sum)
{
    int n = 3; //size of array
    int dp[n + 1][sum + 1];
    int infin = INT_MAX - 1;
    for (int i = 0; i <= sum; i++)
        dp[0][i] = infin;

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= sum; i++)
    {
        if (i % coins[0] == 0)
            dp[1][i] = i / coins[0];
        else
            dp[1][i] = infin;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
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