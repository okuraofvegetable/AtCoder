#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#define EQ(a,b) (abs((a)-(b))<eps)
int N=20,Q;
int SIZE;
struct segtree
{
	int seg[1<<21];
	ll sum[30];
	segtree()
	{
		for(int i=0;i<(1<<21);i++)seg[i]=0;
		for(int i=0;i<=N;i++)sum[i]=1<<i;
	}
	void update(int k)
	{
		k+=SIZE-1;
		int x = (seg[k]==0)?1:-1;
		seg[k] += x;
		int d = N-1;
		while(k>0)
		{
			k = (k-1)/2;
			if(seg[k]==(1<<(N-d))||seg[k]==0)sum[d]--;
			seg[k]+=x;
			if(seg[k]==(1<<(N-d))||seg[k]==0)sum[d]++;
			d--;
		}
	}
};
segtree h,w;
int main()
{
	scanf("%d %d",&N,&Q);
	SIZE = 1<<N;
	ll S = ((1ll<<(2*N+2))-1)/3;
	for(int i=0;i<Q;i++)
	{
		int t,x;
		scanf("%d %d",&t,&x);
		if(t==0)h.update(x-1);
		else w.update(x-1);
		ll ans=S;
		for(int j=0;j<=N;j++)ans-=h.sum[j]*w.sum[j];
		ans = ans*4+1;
		printf("%lld\n",ans);
	}
	return 0;
}
