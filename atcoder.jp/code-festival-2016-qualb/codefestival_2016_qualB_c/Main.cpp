#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000
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
int W,H;
int p[100100],q[100100];
int main(){
	scanf("%d %d",&W,&H);
	for(int i=0;i<W;i++)scanf("%d",&p[i]);
	for(int i=0;i<H;i++)scanf("%d",&q[i]);
	sort(p,p+W);
	sort(q,q+H);
	int w = 0, h = 0;
	ll ans = 0ll;
	for(int i=0;i<H+W;i++){
		char type;
		if(w==W){
			type = 'h';
		}else if(h==H){
			type = 'w';
		}else{
			if(p[w]<q[h])type = 'w';
			else type = 'h';
		}
		if(type=='w'){
			ans += (ll)p[w]*(ll)(H+1-h);
			w++;
		}else{
			ans += (ll)q[h]*(ll)(W+1-w);
			h++;
		}
	}
	cout << ans << endl;
	return 0;
}