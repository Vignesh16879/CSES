#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    
    for(int i = 2; i <= n; i+=2) 
        cout << i << " ";

    for(int i = 1; i <= n; i+=2) 
        cout << i << " ";

    cout << "\n";

    return 0;
}