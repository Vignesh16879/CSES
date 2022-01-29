#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
 
 
int main()
{
    ll n;
	cin >> n;
	vector<ll> arr(n);
	
    for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
    ll i = 0, j = 0, max_len = 0, curr_len = 0;
	map<ll, ll> freq;
	
    while (j < n)
	{
		if (freq.find(arr[j]) == freq.end() || freq[arr[j]] == 0)
		{
			freq[arr[j]]++;
			curr_len++;
			max_len = max(max_len, curr_len);
			j++;
		}
		else
		{
			curr_len--;
			freq[arr[i]]--;
			i++;
		}
	}
 
	cout << max_len << "\n";
    
    return 0;
}