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
const int SIZE = 1<<17;
int seg[SIZE*2];
int ans[100100];
int h[100100];
int query(int a,int b,int k,int l,int r)
{
	if(r<=a||b<=l)return 0;
	else if(a<=l&&r<=b)return seg[k];
	else return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
}
int N;
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&seg[i+SIZE-1]);
		h[i]=seg[i+SIZE-1];
	}
	h[N+1]=seg[N+SIZE]=INF;
	h[0]=seg[SIZE-1]=INF;
	for(int i=SIZE-2;i>=0;i--)seg[i]=max(seg[i*2+1],seg[i*2+2]);
	for(int i=1;i<=N;i++)
	{
		int l=i,r=N+1;
		while(r-l>1)
		{
			int mid = (l+r)/2;
			if(query(i,mid+1,0,0,SIZE)<=h[i])l=mid;
			else r=mid;
		}
		ans[i]+=l-i;
		l=0,r=i;
		while(r-l>1)
		{
			int mid = (l+r)/2;
			if(query(mid,i+1,0,0,SIZE)<=h[i])r=mid;
			else l=mid;
		}
		ans[i]+=i-r;
	}
	for(int i=1;i<=N;i++)printf("%d\n",ans[i]);
	return 0;
}
