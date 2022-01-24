#include<bits/stdc++.h>

#define ll long long ll

using namespace std;


ll main()
{
    ll n, x;
    ll p[n];

    cin >> n >> x;
    
    for(ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }


    sorgt(p, p + n);
    
    ll i = 0, j = n - 1, ans = 0;

    for(j; i <= j; j--)
    {
        if(p[i] + p[j] <= x)
        {
            ans++;
            i++;
        }
        else
        {
            ans++;
        }
    }

    cout << ans << "\n";
    
    return 0;
}