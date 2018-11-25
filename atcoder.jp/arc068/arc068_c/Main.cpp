#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
#define MAX_N 100100
struct BIT{
	ll bit[MAX_N+1];
	void add(int i,ll x){
		i++;
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		i++;
		ll res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
	ll sum(int l,int r){// [l,r]
		if(l==0)return sum(r);
		else return sum(r)-sum(l-1);
	}
}bit;
int N,M;
P range[300100];
int length(P a){
	return a.sec-a.fi;
}
bool comp(P a,P b){
	return (a.sec-a.fi) < (b.sec-b.fi);
}
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> range[i].fi >> range[i].sec;
	}
	sort(range,range+N,comp);
	int k = 0;
	for(int i=1;i<=M;i++){
		while(k<N&&length(range[k])<i){
			bit.add(range[k].fi,1);
			bit.add(range[k].sec+1,-1);
			k++;
		}
		int ans = N-k;
		for(int j=0;j<=M;j+=i){
			ans += bit.sum(j);
		}
		cout << ans << endl;
	}
	return 0;
}