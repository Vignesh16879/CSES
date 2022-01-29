#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
long long sp(vector<ll> arr, int n) 
{
    ll int res = 1; // Initialize result
  
    sort(arr.begin(), arr.end());
 
    for (int i = 0; i < n && arr[i] <= res; i++)
        res = res + arr[i];
  
   return res;
}
 
 
int main()
{   
    ll n, m;
    vector<ll> c;
    ll ans;
    cin >> n;
	c.resize(n);
	
    for (ll &x : c)
    {
		cin >> x;
	}
 
    cout << sp(c, n) << "\n";
 
    return 0;
}