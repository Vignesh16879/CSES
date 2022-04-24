#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
 
int main()
{
    ll n;
    cin >> n;
    stack<pair<ll, ll>> st;
    st.push({0, 0});

    for(ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;

        while(!st.empty() && st.top().first >= a)
            st.pop();

        cout << st.top().second << " ";
        st.push({a, i+1});
    }   
  
    cout << "\n";
    
    return 0;
}