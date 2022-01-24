#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    string s;
    cin >> s;
    ll m = 1;
    ll k = 1;

    for(ll i =1; i < s.length(); i++)
    {
        if(s[i] == s[i - 1])
        {
            k++;
        }
        else
        {
            k = 1;
        }

        if(m < k)
        {
            m = k;
        }
    }

    cout << m;

    return 0;
}
