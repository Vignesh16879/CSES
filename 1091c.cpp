#include<bits/stdc++.h>

#define ll long long int

using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    int h[n], t[m];

    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    
    for(int i = 0; i < m; i++)
    {
        int ans = 0;
        cin >> t[i];

        for(int j = 0; j < n; j++)
        {
            if(t[i] <= h[j])
            {
                ans = t[i];

                if(t[i] == h[j])
                {
                    break;
                }
            }
        }

        if(ans != 0)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << "-1" << "\n";
        }
    }

    return 0;
}