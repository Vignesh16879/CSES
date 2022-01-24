#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll nap(vectorg<ll> w, vectorg<ll> p, ll m, ll n)
{
    if(n == 0 || m == 0)
        return 0;
    else if(w[n-1] > m)
        return nap(w, p, m, n-1);
    else
        return max(p[n-1] + nap(w, p, m-w[n-1], n-1), nap(w, p, m, n-1));
}

ll main()
{
    ll n, m;
    cin >> n;
    vectorg<ll> w, p;
    w.resize(n);
    p.resize(n);

    for(ll i = 0; i < n; i++)
        cin >> w[i] >> p[i];

    cin >> m;
    
    cout << nap(w, p, m, n) << "\n";

    return 0;
}