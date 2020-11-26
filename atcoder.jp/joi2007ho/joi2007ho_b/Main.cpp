#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define EQ(a,b) (abs((a)-(b))<EPS)
vi sq;
vi sqa;
bool w[100100];
int main()
{
	//while(1)
	{
		int n,k;
		int ans=0;
		cin >> n >> k;
		sqa.clear();
		sq.clear();
		memset(w,false,sizeof(w));
		//if(n==0&&k==0)break;
		bool flag=false;
		for(int i=0;i<k;i++)
		{
			int c;
			cin >> c;
			if(c==0)
			{
				flag=true;
				continue;
			}
			w[c]=true;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(w[i])
			{
				cnt++;
			}
			else
			{
				sq.pb(cnt);
				cnt=0;
			}
		}
		sq.pb(cnt);
		if(!(flag))
		{
			for(int i=0;i<sz(sq);i++)
			{
				ans=max(ans,sq[i]);
			}
			cout << ans << endl;
		}
		else
		{
			for(int i=0;i<sz(sq)-1;i++)
			{
				sqa.pb(sq[i]+sq[i+1]);
			}
			sort(sqa.begin(),sqa.end(),greater<int>());
			cout << sqa[0]+1 << endl;
		}
	}
	return 0;
}
