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
#include <cassert>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
const int SIZE = 1<<19;
struct segtree{
	ll seg[SIZE*2],sum[SIZE*2];
	bool All[SIZE*2];
	segtree(){
		for(int i=0;i<SIZE*2;i++){
			seg[i]=0ll;
			sum[i]=0ll;
			All[i]=true;
		}
	}
	inline void lazy_evaluate(int k){
		if(!All[k])return;
		if(k<SIZE-1){
			seg[k*2+1]=seg[k];
			seg[k*2+2]=seg[k];
			sum[k*2+1]=sum[k]/2ll;
			sum[k*2+2]=sum[k]/2ll;
			All[k*2+1]=true;
			All[k*2+2]=true;
		}
	}
	void update(int a,int b,int k,int l,int r,ll x){
		if(r<=a||b<=l)return;
		lazy_evaluate(k);
		if(a<=l&&r<=b){
			if(All[k]){
				if(seg[k]>=x)return;
				else{
					seg[k]=x;
					sum[k]=x*(r-l);
					All[k]=true;
				}
			}else{
				if(seg[k]<=x){
					seg[k]=x;
					sum[k]=x*(r-l);
					All[k]=true;
				}else{
					update(a,b,k*2+1,l,(l+r)/2,x);
					update(a,b,k*2+2,(l+r)/2,r,x);
					sum[k]=sum[k*2+1]+sum[k*2+2];
					seg[k]=max(seg[k*2+1],seg[k*2+2]);
					if(All[k*2+1]&&All[k*2+2]&&seg[k*2+1]==seg[k*2+2])All[k]=true;
					else All[k]=false;
				}
			}
			return;
		}
		update(a,b,k*2+1,l,(l+r)/2,x);
		update(a,b,k*2+2,(l+r)/2,r,x);
		sum[k]=sum[k*2+1]+sum[k*2+2];
		seg[k]=max(seg[k*2+1],seg[k*2+2]);
		if(All[k*2+1]&&All[k*2+2]&&seg[k*2+1]==seg[k*2+2])All[k]=true;
		else All[k]=false;
	}
	void update(int a,int b,ll x){
		update(a,b,0,0,SIZE,x);
	}
	ll query(){
		return sum[0];
	}
}seg;
bool comp(T a,T b){
	if(a.fi!=b.fi)return a.fi > b.fi;
	else return a.sec < b.sec;
}
int N;
P fish[500100];
T event[500100];
int col[3][500100];
map<ll,ll> m;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char type;
		scanf("%d %c",&fish[i].fi,&type);
		if(type=='R')fish[i].sec = 0;
		else if(type=='G')fish[i].sec = 1;
		else fish[i].sec = 2;
	}
	sort(fish,fish+N);
	for(int i=0;i<N;i++){
		col[fish[i].sec][i]++;
	}
	for(int i=0;i<3;i++){
		for(int j=1;j<=N;j++){
			col[i][j]+=col[i][j-1];
		}
	}
	for(int i=0;i<N;i++){
		int k = lower_bound(fish,fish+N,P(fish[i].fi*2,0))-fish;
		int a = col[0][k-1]+1;
		int b = col[1][k-1]+1;
		int c = col[2][k-1]+1;
		if(i>0){
			a -= col[0][i-1];
			b -= col[1][i-1];
			c -= col[2][i-1];
		}
		event[i]=T(a,P(b,c));
	}
	sort(event,event+N,comp);
	event[N]=T(0,P(1,1));
	ll ans = 0ll;
	ll res = 0ll;
	m[INF]=0;
	m[0]=INF;
	for(int i=0;i<=N;i++){
		ll x = event[i].sec.fi;
		ll y = event[i].sec.sec;
		if(i>0&&event[i-1].fi!=event[i].fi){
			ans += res*(ll)(event[i-1].fi-event[i].fi);
		}
		map<ll,ll>::iterator it;
		it = m.lower_bound(x);
		ll cx = x;
		if((it->sec)>=y)continue;
		while(it!=m.begin()){
			ll ty = it->sec; 
			if(ty>=y)break;
			if(it->sec<=y&&it->fi<=x)m.erase(it--);
			else it--;
			ll tx = it->fi;
			res += (y-ty)*(cx-tx);
			cx = tx;
		}
		m[x]=y;
	}
	printf("%lld\n",ans-1ll);
	return 0;
}
