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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,Q;
const int SQR = 200;
ll X[100100];
ll es[1000][1000];
ll cnt[100100];
vector<ll> vs;
vector<int> appear[100100];
int main()
{
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&X[i]);
		vs.pb(X[i]);
	}
	sort(all(vs));
	vs.erase(unique(all(vs)),vs.end());
	for(int i=0;i<N;i++)X[i]=lower_bound(all(vs),X[i])-vs.begin();
	for(int i=0;i<N;i++)appear[X[i]].pb(i);
	for(int i=0;i<N/SQR;i++)
	{
		ll MX = 0ll;
		memset(cnt,0,sizeof(cnt));
		for(int j=SQR*i;j<(N/SQR)*SQR;j++)
		{
			cnt[X[j]]++;
			MX = max(MX,cnt[X[j]]*vs[X[j]]);
			if((j+1)%SQR==0)es[i][(j+1)/SQR]=MX;
		}
	}
	for(int i=0;i<Q;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		l--;r--;
		ll ans = 0ll;
		int L = l/SQR+1,R = r/SQR;
		if(L>=R)
		{
			for(int i=l;i<=r;i++)
			{
				int k = upper_bound(all(appear[X[i]]),r)-lower_bound(all(appear[X[i]]),l);
				ans = max(ans,vs[X[i]]*(ll)k);
			}
			printf("%lld\n",ans);
		}
		else
		{
			ans = es[L][R];
			for(int i=l;i<SQR*L;i++)
			{
				int k = upper_bound(all(appear[X[i]]),r)-lower_bound(all(appear[X[i]]),l);
				ans = max(ans,vs[X[i]]*(ll)k);
			}
			for(int i=SQR*R;i<=r;i++)
			{
				int k = upper_bound(all(appear[X[i]]),r)-lower_bound(all(appear[X[i]]),l);
				ans = max(ans,vs[X[i]]*(ll)k);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
