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
int N;
int S[100100],T[100100];
const int SIZE = 1<<18;
struct segtree
{
	int seg[SIZE*2];
	void update(int k)
	{
		k += SIZE-1;
		seg[k]++;
		while(k>0)
		{
			k = (k-1)/2;
			seg[k]=seg[k*2+1]+seg[k*2+2];
		}
	}
	int query(int a,int b,int k,int l,int r)
	{
		if(r<=a||b<=l)return 0;
		if(a<=l&&r<=b)return seg[k];
		else return query(a,b,k*2+1,l,(l+r)/2)+query(a,b,k*2+2,(l+r)/2,r);
	}
}seg;
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&S[i],&T[i]);
		seg.update(S[i]);
	}
	for(int i=0;i<N;i++)printf("%d\n",seg.query(S[i],T[i],0,0,SIZE)-1);
	return 0;
}
