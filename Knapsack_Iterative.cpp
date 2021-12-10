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

int t[101][1001];
int knapSack(int W, vi wt, vi val, int n)
{
    int dp[n + 1][W + 1];

    //initialisation condition
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < W + 1; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max((val[i - 1] + dp[i - 1][j - wt[i - 1]]), dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    memset(t, -1, sizeof(t));
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> weight(n), value(n);

    cout << "enter weights: " << endl;
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "enter values: " << endl;
    for (int i = 0; i < n; i++)
        cin >> value[i];

    int maxweight(0);

    cout << "Enter maximum capacity of knapsack: ";
    cin >> maxweight;

    cout << "Maximum value of bag is: " << knapSack(maxweight, weight, value, n);
}