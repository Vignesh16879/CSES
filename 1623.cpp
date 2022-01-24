#include<bits/stdc++.h>

#define ll long long

using namespace std;


ll fmr(ll a[], ll i, ll sum, ll sumtotal)
{
    if(i == 0)
    {
        return abs(sumtotal  - sum - sum);
    }

    return min(fmr(a, i - 1, sum + a[i - 1], sumtotal), fmr(a, i - 1, sum, sumtotal));
}


ll fm(ll a[], ll n)
{
    ll sumtotal = 0;

    for(ll i = 0; i < n; i++)
    {
        sumtotal += a[i];
    }

    return fmr(a, n, 0, sumtotal);
}


ll main()
{
    ll n;
    cin >> n;
    ll a[n];
    
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << fm(a, n) << "\n";

    return 0;
}