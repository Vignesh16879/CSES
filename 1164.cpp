#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> arr;

    for(ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, 0, i});
        arr.push_back({b, 1, i});
    }

    sort(arr.begin(), arr.end());

    ll c = 0;
    vector<ll> av, ans(n);

    for(auto [x, y, i] : arr)
        if(y == 0)
        {
            c++;

            if(av.empty())
                ans[i] = c;
            else
            {
                ans[i] = av.back();
                av.pop_back();
            }
        }
        else
        {
            c--;
            av.push_back(ans[i]);
        }

    cout << *max_element(ans.begin(), ans.begin() + n) << "\n";

    for(ll i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";

    return 0;
}

// void solve()
// {
//     // good implementation
//     int n;
//     see(n);
//     vc<tuple<int, int, int>> v;
//     rep(i, 0, n)
//     {
//         int x, y;
//         see(x, y);
//         v.pb({x, 0, i});
//         v.pb({y, 1, i});
//     }
//     sort(all(v));
//     int c = 0;
//     int ans[n];
//     vi av;
//     for (auto [x, y, i] : v)
//     {
//         if (y == 0)
//         { // entry
//             c++;
//             if (av.empty())
//                 ans[i] = c;
//             else
//             {
//                 ans[i] = av.back();
//                 av.pop_back();
//             }
//         }
//         else
//         {
//             c--;
//             av.pb(ans[i]);
//         }
//     }
//     putl(*max_element(ans, ans + n));
//     rep(i, 0, n) put(ans[i]);
// }
// signed main()
// {
//     IOS;
// #ifndef ONLINE_JUDGE
// // freopen("input.txt", "r" , stdin);
// // freopen("output.txt", "w", stdout);
// #endif
//     int t = 1;
//     // cin>>t;
//     while (t--)
//     {
//         solve();
//         // cout<<'\n';
//     }
// #ifndef ONLINE_JUDGE
//     clock_t tStart = clock();
//     cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
// #endif
// }