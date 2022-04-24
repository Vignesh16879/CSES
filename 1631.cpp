#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n, m=0, s=0;
    cin >> n;

    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        m = max(m, x);
        s += x;
    }

    cout << max(2*m, s) << "\n";

    return 0;
}