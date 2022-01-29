#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
 
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr;
 
    for(ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        arr.push_back(a);
        vector<ll>::iterator upper1;
        upper1 = upper_bound(arr.begin(), arr.end(), arr[i]);
        cout << (upper1 - arr.begin()) << " ";
    }
  
    cout << "\n";
    
    return 0;
}