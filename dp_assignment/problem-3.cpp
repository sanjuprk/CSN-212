#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*https://www.codechef.com/problems/D2/*/

// Binary search 
int Check(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) 
    {
    	int m = l + (r-l)/2;
    	if (v[m] >= key)
        r = m;
    	else
        l = m;
    }
    return r;
}
 
int LIS(std::vector<int> &v) {
    if (v.size() == 0)
        return 0;
    vector<int> tail(v.size(), 0);
    int length = 1; 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i];
        else
            tail[Check(tail, -1, length-1, v[i])] = v[i];
    }
    return length;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[2*n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			a[n+i]=a[i];
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			vector <int> v(a+i,a+i+n);
			ans=max(ans,LIS(v));
		}
		cout<<ans<<endl;
	}
	return 0;
}
