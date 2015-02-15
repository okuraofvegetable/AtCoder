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
typedef long long ll;
typedef pair<int,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int m,M;
int a[20100],A[20100];
ll l[20100],L[20100];
int dig[80100];
ll num[80100];
int main()
{
	scanf("%d",&m);
	rep(i,m)scanf("%d %lld",&a[i],&l[i]);
	scanf("%d",&M);
	rep(i,M)scanf("%d %lld",&A[i],&L[i]);
	reverse(l,l+m);
	reverse(a,a+m);
	reverse(A,A+M);
	reverse(L,L+M);
	l[m]=INF;
	L[M]=INF;
	int cnt1=0,cnt2=0,k=0,ans_id=0;
	while(cnt1<m||cnt2<M)
	{
		int p = min(l[cnt1],L[cnt2]);
		if(k&&a[cnt1]+A[cnt2]+k<10)
		{
			dig[ans_id]=a[cnt1]+A[cnt2]+k;
			num[ans_id++]=1;
			l[cnt1]--;
			L[cnt2]--;
			if(l[cnt1]==0)cnt1++;
			if(L[cnt2]==0)cnt2++;
			k=0;
		}
		else if(k&&a[cnt1]+A[cnt2]+k>=10)
		{
			dig[ans_id]=(a[cnt1]+A[cnt2]+k)%10;
			num[ans_id++]=min(l[cnt1],L[cnt2]);
			l[cnt1]-=p;
			L[cnt2]-=p;
			if(l[cnt1]==0)cnt1++;
			if(L[cnt2]==0)cnt2++;
			k=1;
		}
		else if(a[cnt1]+A[cnt2]<10)
		{
			dig[ans_id]=a[cnt1]+A[cnt2];
			num[ans_id++]=min(l[cnt1],L[cnt2]);
			l[cnt1]-=p;
			L[cnt2]-=p;
			if(l[cnt1]==0)cnt1++;
			if(L[cnt2]==0)cnt2++;
		}
		else //a[cnt1]+A[cnt2]>=10
		{
			dig[ans_id]=(a[cnt1]+A[cnt2])%10;
			num[ans_id++]=1;
			dig[ans_id]=(a[cnt1]+A[cnt2]+1)%10;
			num[ans_id++]=p-1;
			l[cnt1]-=p;
			L[cnt2]-=p;
			if(l[cnt1]==0)cnt1++;
			if(L[cnt2]==0)cnt2++;
			k=1;
		}
		//printf("%d %d\n",cnt1,cnt2);
	}
	if(k)
	{
		dig[ans_id]=1;
		num[ans_id++]=1;
	}
	vector<P> ans;
	rep(i,ans_id)
	{
		if(num[i]==0)continue;
		if(!ans.empty()&&dig[i]==ans.back().fi)ans[(int)ans.size()-1].sec+=num[i];
		else ans.pb(P(dig[i],num[i]));
	}
	while(!ans.empty()&&ans.back().fi==0)ans.pop_back();
	reverse(all(ans));
	printf("%d\n",(int)ans.size());
	rep(i,ans.size())printf("%d %lld\n",ans[i].fi,ans[i].sec);
	return 0;
}