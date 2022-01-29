#include <bits/stdc++.h>

using namespace std;

#define intlo long long int

int main()
{
	intlo n
    cin >> n;
    vector<pair<intlo,bool>> v;
    intlo x, y;

    while(n--)
    {
    	cin >> x >> y;
    	v.push_back(make_pair(x,true));
    	v.push_back(make_pair(y,false));
    }
   	
    sort(v.begin(),v.end());
   	intlo ans =0, maxx =0;
   	
    for(intlo i = 0; i < v.size(); i++)
    {
   		if(v[i].second == true)
        {
   			ans++;
   			maxx = max(ans, maxx);
   		}
        else
        {
   			ans--;
   		}
   	}

   	cout << maxx << endl;

	return 0;
}