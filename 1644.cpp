#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    
    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    ll pre[n+1] = {0};

    for(ll i = 1; i <= n; i++)
        pre[i] = pre[i-1] + arr[i-1];

    ll s=0, len=a;    
    set<pair<ll, ll>> st;

    for(ll i = 0; i < a; i++)
        s += arr[i];

    st.insert({pre[1], 0});
    ll mx = s;

    for(ll i = a; i < n; i++)
    {
        ll z = pre[i+1] - pre[i+1-a];
        if (len == b)
        {
            auto it = st.begin();
            s = max(z, s+arr[i] - (it->first-pre[i-len]));

            if(s == z)
            {    
                len = a;
                st.clear();
            }
            else
            {
                for (ll k = i-b; k <= it->second; k++)
                    st.erase({pre[k+1], k});

                len = i-it->second;
            }

            st.insert({pre[i-a+2], i-a+1});
        }
        else
        {
            s = max(z, s+arr[i]);

            if(s == z)
            {    
                len = a;
                st.clear();
            }
            else
                len++;
            
            st.insert({pre[i-a+2], i-a+1});
        }

        mx = max(mx, s);
    }

    cout << mx << "\n";

    return 0;
}