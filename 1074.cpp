#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
 
int main()
{   
    int n, m;
    vector<int> p;
    ll ans;
    cin >> n;
	p.resize(n);
	
    for (int &x : p)
    {
		cin >> x;
	}
	
    sort(p.begin(), p.end());
	m = p[n/2];
	
    for (const int &x : p)
    {
		ans += abs(m - x); 
	}
 
	cout << ans << "\n";
 
    return 0;
}