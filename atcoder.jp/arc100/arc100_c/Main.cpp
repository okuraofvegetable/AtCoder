#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
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
int N;
int A[1<<19];
P f[1<<19];
P merge(P a,int x){
	if(a.fi<x){
		a.sec = a.fi;
		a.fi = x;
	}else if(a.sec < x){
		a.sec = x;
	}
	return a;
}
P merge(P a,P b){
	return merge(merge(a,b.fi),b.sec);
}
int ans[1<<18];
int main(){
	cin >> N;
	for(int i=0;i<(1<<N);i++){
		cin >> A[i];
		f[i]=P(A[i],-INF);
	}
	for(int j=0;j<N;j++){
		for(int i=0;i<(1<<N);i++){
			if((i>>j)&1)f[i]=merge(f[i],f[i&~(1<<j)]);
		}
	}
	for(int i=1;i<(1<<N);i++){
		ans[i]=f[i].fi+f[i].sec;
	}
	for(int i=2;i<(1<<N);i++){
		ans[i]=max(ans[i-1],ans[i]);
	}
	for(int i=1;i<(1<<N);i++){
		cout << ans[i] << endl;
	}
}
#include <bits/stdc++.h>