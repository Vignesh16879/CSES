#include<bits/stdc++.h>

#define ll long long

using namespace std;


void tower(ll n, char from, char to, char aux)
{
    if(n == 1)
    {
        cout << from << " " << to << "\n";

        return;
    }

    tower(n - 1, from, aux, to);
    cout << from << " " << to << "\n";
    tower(n - 1, aux, to, from);
}


ll main()
{
    ll n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    tower(n, '1', '3', '2');

    return 0;
}