#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 4000000000000000000LL
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
int K,N;
ll x[55],y[55];
vector<ll> zx,zy;
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> x[i] >> y[i];
		zx.pb(x[i]);
		zy.pb(y[i]);
	}
	sort(all(zx));
	sort(all(zy));
	zx.erase(unique(all(zx)),zx.end());
	zy.erase(unique(all(zy)),zy.end());
	ll ans = LLINF;
	//cout << ans << endl;
	for(int i=0;i<zx.size();i++){
		for(int j=i;j<zx.size();j++){
			for(int k=0;k<zy.size();k++){
				for(int l=k;l<zy.size();l++){
					int c=0;
					for(int d=0;d<N;d++){
						if(zx[i]<=x[d]&&x[d]<=zx[j]&&zy[k]<=y[d]&&y[d]<=zy[l]){
							c++;
						}
					}
					if(c>=K)ans = min(ans,(zx[j]-zx[i])*(zy[l]-zy[k]));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}