#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    for( int i = 0;i < n-1 ;i++)
    {
        ll a;
        cin >> a;
        sum -= a;
    }
    cout<< sum;
}