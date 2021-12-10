#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
#define maxi 1000000000000000000

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef unordered_map<ll, ll> unmap;
typedef vector<vl> vll;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for (ll i = a; i < (b); i++)
#define repdec(i, a, b) for (ll i = (a)-1; i >= b; i--)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

bool subset(int arr[], int n, int sum)
{
    // code here

    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;
    for (int i = 1; i < sum + 1; i++)
        dp[0][i] = false;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    int arr[5] = {2, 3, 7, 8, 10};
    for (int i = 1; i <= 15; i++)
        cout << i << '\t' << subset(arr, 5, i) << endl;

    // 1 and 0 will be printed respectively for 1 o 15
    // 1->Subset sum is possible
    // 0->Subset sum isn't possible
    return 0;
}
