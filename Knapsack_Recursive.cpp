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

int knapSack(int W, vi wt, vi val, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
    else
    {
        return knapSack(W, wt, val, n - 1);
    }
}
int main()
{
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

    cout << "Maximum value of bag is: " << knapSack(maxweight, weight, value, n - 1);
}