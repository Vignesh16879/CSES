#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;


ll main()
{
    ll n, c=1, l=1; 
    cin >> n;
    vectorg<ll> arr(n);

    for (ll i = 1; i <= n; i++) 
    {
    	ll x; 
        cin >> x;
    	arr[x] = i;
    }

    
    for (ll i = 1; i <= n; i++) 
    {
    	if (l > arr[i]) 
    		c++;

    	l = arr[i];
    }

    cout << c << "\n";

    return 0;
}