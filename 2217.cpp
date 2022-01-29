#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
 
int main()
{   
    int n,m; cin>>n>>m;
    int l = 1;
    int arr[n+2] = {0}, a[n+1] = {0};
    
    arr[n+1] = n+1;
 
    for (int i = 1; i <= n; i++) 
    {
		int x; cin>>x;
		arr[x] = i;
		a[i] = x;
    }
    
    int c = 1;
    
    for (int i = 1; i <= n; i++) 
    {
		if (l > arr[i]) 
	    	c++;
		
        l = arr[i];
    }
 
    while(m--) {
		int x,y; cin>>x>>y;
		int r = a[x], s = a[y];
		swap(a[x], a[y]);
		if (arr[r-1] <= arr[r] && arr[r-1] > y) 
            c++;
		if (arr[r-1] > arr[r] && arr[r-1] <= y) 
            c--;
		if (arr[r] <= arr[r+1] && y > arr[r+1]) 
            c++;
		if (arr[r] > arr[r+1] && y <= arr[r+1]) 
            c--;	arr[r] = y;
		if (arr[s-1] <= arr[s] && arr[s-1] > x) 
            c++;
		if (arr[s-1] > arr[s] && arr[s-1] <= x) 
            c--;
		if (arr[s] <= arr[s+1] && x > arr[s+1]) 
            c++;
		if (arr[s] > arr[s+1] && x <= arr[s+1]) 
            c--;	
		
        arr[s] = x;
		
        cout << c << endl;
    }
 
    return 0;
}