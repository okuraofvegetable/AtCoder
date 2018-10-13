#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef pair<ll,P> T;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
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
int H,W;
int N,M;
string s[1010];
vector<int> zx,zy;
int imos[2010][2010];
void add(int a,int b,int c,int d){
	a = lower_bound(all(zx),a)-zx.begin();
	b = lower_bound(all(zy),b)-zy.begin();
	c = lower_bound(all(zx),c)-zx.begin();
	d = lower_bound(all(zy),d)-zy.begin();
	imos[a][b]++;
	imos[a][d]--;
	imos[c][b]--;
	imos[c][d]++;
}
int main(){
	scanf("%d %d",&H,&W);
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		cin >> s[i];
	}
	zx.pb(0);zx.pb(H);
	zy.pb(0);zy.pb(W);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(s[i][j]=='#'){
				zx.pb(i);zx.pb(H-N+i+1);
				zy.pb(j);zy.pb(W-M+j+1);
			}
		}
	}
	sort(all(zx));
	sort(all(zy));
	zx.erase(unique(all(zx)),zx.end());
	zy.erase(unique(all(zy)),zy.end());
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(s[i][j]=='#'){
				add(i,j,H-N+i+1,W-M+j+1);
			}
		}
	}
	for(int i=0;i<zx.size();i++){
		for(int j=1;j<zy.size();j++){
			imos[i][j]+=imos[i][j-1];
		}
	}
	for(int i=1;i<zx.size();i++){
		for(int j=0;j<zy.size();j++){
			imos[i][j]+=imos[i-1][j];
		}
	}
	ll ans = 0ll;
	for(int i=0;i<zx.size()-1;i++){
		for(int j=0;j<zy.size()-1;j++){
			if(imos[i][j]>0){
				ans += (ll)(zx[i+1]-zx[i])*(ll)(zy[j+1]-zy[j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}