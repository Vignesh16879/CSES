#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n = 0;
    cin >> n;
    if(n <= 3)
    {
        if(n > 1)
        {
            cout << "NO SOLUTION";
        }
        else
        {
            cout << "1   ";
        }
        
    }
    else if(n == 4)
    {
        cout << "2 4 1 3";
    }
    else
    {
        int x = 0;

        while(x != 1)
        {
            int static a = 2;
            cout << a << " ";
            if(a < n - 1)
            {
                a += 2;
            }
            else
            {
                x = 1;
            }
        }

        while(x != 2)
        {
            int static a = 1;
            cout << a << " ";
            if(a < n)
            {
                a += 2;
            }
            else
            {
                x = 2;
            }
        }
    }   
}