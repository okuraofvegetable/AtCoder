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
typedef pair<P,int> T;
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
#define MOD 1000000007ll
ll mpow(ll a,ll x){
	ll res = 1ll;
	while(x){
		if(x&1)res = (res*a)%MOD;
		a = (a*a)%MOD;
		x >>= 1;
	}
	return res;
}
int N;
struct star{
	int X,Y,C,id;
	star():X(0),Y(0),C(0),id(0){}
	bool operator < (const star& a) const{
		if(X!=a.X)return X < a.X;
		else return Y < a.Y;
	}
};
star S[100100];
star conv[100100];
bool used[100100];
bool ccw(star a,star b,star c){
	ll A = b.X-a.X,B = b.Y-a.Y;
	ll C = c.X-b.X,D = c.Y-b.Y;
	return (A*D-B*C)>0;
}
int cnt[3];
int zip[100100];
int k=0;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&S[i].X,&S[i].Y,&S[i].C);
		cnt[S[i].C]++;
	}
	sort(S,S+N);
	for(int i=0;i<N;i++)S[i].id=i;
	for(int i=0;i<N;i++){
		while(k>1&&!ccw(conv[k-2],conv[k-1],S[i]))k--;
		conv[k++]=S[i];
	}
	int u = k;
	for(int i=N-2;i>=0;i--){
		while(k>u&&!ccw(conv[k-2],conv[k-1],S[i]))k--;
		conv[k++]=S[i];
	}
	k--;
	/*for(int i=0;i<k;i++){
		printf("%d %d\n",conv[i].X,conv[i].Y);
	}*/
	vector<int> v;
	vector<P> vec;
	for(int i=0;i<k;i++){
		if(conv[i].C>0){
			v.pb(conv[i].C);
			vec.pb(P(conv[i].C,i));
		}
		used[conv[i].id]=true;
	}
	v.erase(unique(all(v)),v.end());
	if(v.size()>3){
		printf("0\n");
		return 0;
	}
	ll side;
	if(v.size()==0)side = ((ll)k*(ll)(k-1)+2)%MOD;
	if(v.size()==1){
		int len = vec[sz(vec)-1].sec-vec[0].sec+1;
		int rem = k-len;
		if(rem%2==0)side=((ll)(rem+1)*(ll)(rem/2)+1)%MOD;
		else side=((ll)((rem+1)/2)*(ll)rem+1)%MOD;
		for(int i=1;i<vec.size();i++){
			rem = vec[i].sec-vec[i-1].sec-1;
			ll add;
			if(rem%2==0)add=(ll)(rem+1)*(ll)(rem/2)%MOD;
			else add=(ll)((rem+1)/2)*(ll)rem%MOD;
			side = (side+add)%MOD;
		}
	}
	if(v.size()==2){
		int len = vec[sz(vec)-1].sec-vec[0].sec+1;
		int rem = k-len;
		int rem2;
		for(int i=1;i<vec.size();i++){
			if(vec[i-1].fi!=vec[i].fi){
				rem2 = vec[i].sec-vec[i-1].sec-1;
				break;
			}
		}
		side = (ll)(rem+1)*(ll)(rem2+1)%MOD;
	}
	if(v.size()==3){
		side = 1;
		for(int i=1;i<vec.size();i++){
			if(vec[i-1].fi!=vec[i].fi){
				int rem = vec[i].sec-vec[i-1].sec-1;
				side = side*(ll)(rem+1)%MOD;
			}
		}
	}
	int free=0;
	for(int i=0;i<N;i++)if(!used[i]&&S[i].C==0)free++;
	ll All = 0;
	if(cnt[1]==0||cnt[2]==0)All=1;
	if(cnt[0]==N)All=2;
	//printf("%lld %d\n",side,free);
	ll ans = (mpow(2,free)*side+MOD-All)%MOD;
	printf("%lld\n",ans);
	return 0;
}