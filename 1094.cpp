#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long curr, prev = 0;
    long long ans = 0;
    
    cin >> curr;
    prev = curr;
    for(int i = 1; i < n; i++)
    {
        cin >> curr;
        if(prev > curr)
        {
            ans += prev - curr;
            curr = prev;
        }
        
        prev = curr;
    }
    
    cout << ans << "\n";

    return 0;
}