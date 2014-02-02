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
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
int n,ans=1;
int check(int x,int p)
{
	int ret=0;
	while(x)
	{
		ret+=x/p;
		x/=p;
	}
	return ret;
}
int search(int p,int k)//素因数pがk回でてくるやつの最小値を求める
{
	int l=1,r=INF;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(check(mid,p)>=k)r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	cin >> n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i!=0)continue;
		int cnt=0;
		while(n%i==0)
		{
			n/=i;
			cnt++;
		}
		ans=max(ans,search(i,cnt));
	}
	if(n>1)ans=max(ans,search(n,1));
	cout << ans << endl;
	return 0;
}
