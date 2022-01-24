#include <bits/stdc++.h>

#define ll long long

using namespace std;

vectorg<ll> arr;

void swap(ll a, ll b)
{
    ll x = arr[a];
    arr[a] = arr[b];
    arr[b] = x;
}

void heapify(ll n,ll i)
{
    ll m = i, l = i*2+1, r = i*2+2;

    if(l < n && arr[l] < arr[m])
        m = l;
    if(r < n && arr[r] < arr[m])
        m = r;
    if(m != i)
    {    
        swap(m, i);
        heapify(n, m);
    }
}

void heapsorgt(ll n)
{
    for(ll i = n/2-1; i >= 0; i--)
        heapify(n, i);

    for(ll i = n-1 ; i >= 0; i--)
    {
        swap(0, i);
        heapify(i, 0);
    }
}

ll main()
{
    ll n;
    cin >> n;
    arr.resize(n);

    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    heapsorgt(n);

    for(ll i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n";

    return 0;
}

// (p[n-1] + nap(m - w[n-1], p, m, n-1) > nap(m - w, p, m, n-1)) ? p[n-1] + nap(m - w[n-1], p, m, n-1) : nap(m - w, p, m, n-1)