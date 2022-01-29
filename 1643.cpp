#include<iostream>
 
using namespace std;
 
#define ll long long 
 
 
ll MSAS(ll a[], ll n)
{
    ll m = a[0];
    ll c = a[0];
 
    for (ll i = 1; i < n; i++)
    {
        c = max(a[i], c + a[i]);
        m = max(m, c);
    }
 
    return m;
}
 
 
int main()
{
    ll n;
    ll a[900000];
    cin >> n;
 
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
 
    ll m = MSAS(a, n);
 
    cout << m;
 
    return 0;
}