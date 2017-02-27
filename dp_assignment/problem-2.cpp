#include<cstdio> 
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
 
using namespace std;
 
 
typedef long long ll;
typedef double D;
typedef vector<int> VI;
typedef vector<ll> VL;
 
 
#define sd(x)   scanf("%d",&x)
#define sd2(x,y)   scanf("%d %d",&x,&y)
#define slld(x)   scanf("%lld",&x)
#define slld2(x,y)   scanf("%lld %lld",&x,&y)
#define pd(y)   printf("%d\n",y)
#define plld(y)   printf("%lld\n",y)
 
 
#define fre(i,a,b) for(int i=a;i<=b;i++)
#define fr(i,a,b) for(int i=a;i<b;i++)
 
 
#define mp make_pair
#define pb push_back
 
#define MOD 1000000007
 
 
 
 
 
struct avoid_roads{
ll numWays(int width, int height, vector <string> bad)
{
    ll dp[101][101];
	long cnt=1,block[101][101],i,j,v,p,q;
	vector<long> t;
	string s,r;
 
    memset(block,0,sizeof(block));
	for(i=0;i<bad.size();i++)
	{
		s=bad[i];
		r="";
		for(j=0;j<s.length();j++)
		{
			if(s[j]!=' ')
			{
				r+=s[j];
			}
			else
			{
				t.pb(atoi(r.c_str()));
				r="";
			}
		}
		t.pb(atoi(r.c_str()));
		if(!block[t[0]][t[1]] && !block[t[2]][t[3]])
            block[t[0]][t[1]]=block[t[2]][t[3]]=cnt++;
        else if(block[t[0]][t[1]])
        {
            if(!block[t[2]][t[3]])
                block[t[2]][t[3]]=block[t[0]][t[1]];
            else
            {
                v=block[t[2]][t[3]];
                for(p=0;p<=width;p++)
                for(q=0;q<=height;q++)
                if(block[p][q]==v)
                block[p][q]=block[t[0]][t[1]];
            }
        }
        else if(block[t[2]][t[3]])
            block[t[0]][t[1]]=block[t[2]][t[3]];
		t.clear();
	}
 
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<=width;i++)
	{
		for(j=0;j<=height;j++)
		{
			if(i>0 && ((block[i][j]==0 && block[i-1][j]==0) || block[i][j]!=block[i-1][j]))
				dp[i][j]+=dp[i-1][j];
			if(j>0 && ((block[i][j]==0 && block[i][j-1]==0) || block[i][j]!=block[i][j-1]))
				dp[i][j]+=dp[i][j-1];
		}
	}
    return dp[width][height];
}
 
 
};
