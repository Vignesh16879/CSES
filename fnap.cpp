#include <bits/stdc++.h>

#define ll long long

using namespace std;

double fnap(vectorg<vectorg<double>> arr, ll n, ll m)
{
    ll c = 0;
    double ans = 0.0;
    sorgt(arr.begin(), arr.begin()+n);

    for(ll i = 0; i < n; i++)
    {
        if(c + arr[i][1] <= m)
        {
            c += arr[i][1];
            ans += arr[i][2];
        }
        else
        {
            ll r = m - c;
            ans += arr[i][2] * (double)r / (double)arr[i][1];
            break;
        }
    }

    return ans;
}

ll main()
{
    ll n, m;
    cin >> n;
    vectorg<vectorg<double>> arr(n);
    
    for(ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr[i].push_back((double)a/(double)b);
        arr[i].push_back(a);
        arr[i].push_back(b);        
    }

    cin >> m;

    cout << fnap(arr, n, m) << "\n";

    return 0;
}