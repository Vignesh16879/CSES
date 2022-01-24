#include<bits/stdc++.h>

#define ll long long

using namespace std;


bool ld[15], rd[15], row[7];
ll c = 0;
char a[8][8];


void chesecond(ll j)
{
    if(j == 8)
    {
        c++;
        return;
    }

    for(ll i = 0; i < 8; i++)
    {
        if(a[i][j] == '.' && ld[i-j+7] == 0 && rd[i+j] == 0 && row[i] == 0)
        {
            ld[i-j+7] = 1, rd[i+j] = 1, row[i] = 1;
            chesecond(j + 1);
            ld[i-j+7] = 0, rd[i+j] = 0, row[i] = 0;
        }
    }
}


ll main()
{
    ll g = 8;

    for(ll i = 0; i < g; i++)
    {
        for(ll j = 0; j < g; j++)
        {
            cin >> a[i][j];
        }
    }

    chesecond(0);

    cout << c << "\n";

    return 0;
}