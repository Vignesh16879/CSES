#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main()
{
    ll n, arr[900000];
    cin >> n;

    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        ll x = i - 1;
        
        while (x >= 0 && arr[x] >= arr[i])
            x--;

        cout << x + 1 << " ";
    }
  
    cout << "\n";
    
    return 0;
}