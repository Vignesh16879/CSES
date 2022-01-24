#include <bits/stdc++.h>

using namespace std;

ll main()
{
    ll n, m;
    cin >> n >> m;
    ll a[200000], b[200000];
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }   
    for(ll i = 0; i < m; i++)
    {
        ll k = -1;
        for(ll j = 0; j < n; j++)
        {
            if(b[i] > a[j] && k <a[j])
            {
                k = a[j];
            }
        }                
        cout << k << " ";                        
    } 
}