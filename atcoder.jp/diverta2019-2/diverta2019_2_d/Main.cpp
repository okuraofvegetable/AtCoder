#include<bits/stdc++.h>
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
ll g[2][3];
ll a[3],b[3];
int main(){
	cin >> N;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cin >> g[i][j];
		}
	}
	int cnt = 0;
	for(int i=0;i<3;i++){
		a[i] = min(g[0][i],g[1][i]);
		b[i] = max(g[0][i],g[1][i]);
		if(g[0][i]<g[1][i])cnt++;
		//cout << a[i] << ' ' << b[i] << endl;
	}
	if(cnt==0||cnt==3){
		ll ans = N;
		for(int i=0;i<=N;i++){
			for(int j=0;i+j<=N;j++){
				int p = i;
				int q = j;
				int r = N-q-p;
				//cout << p << q << r << endl;
				ll res = 0;
				ll rem = 0;
				res += (p/a[0])*b[0];
				res += (q/a[1])*b[1];
				res += (r/a[2])*b[2];
				rem += p%a[0];
				rem += q%a[1];
				rem += r%a[2];
				ans = max(ans,res+rem);
			}
		}
		cout << ans << endl;
	}else if(cnt==1){
		ll M=N;
		for(int i=0;i<3;i++){
			if(g[0][i]>=g[1][i])continue;
			M = max(M,(N/a[i])*b[i]+(N%a[i]));
		}
		//cout << M << endl;
		ll ans = M;
		for(int i=0;i<=M;i++){
			ll p[2];
			p[0] = i;
			p[1] = M-i;
			ll res = 0;
			int cnt = 0;
			for(int j=0;j<3;j++){
				if(g[0][j]<g[1][j])continue;
				//cout << j << endl;
				res += ((p[cnt]/a[j])*b[j])+(p[cnt]%a[j]);
				cnt++;
			}
			assert(cnt==2);
			ans = max(ans,res);
		}
		cout << ans << endl;
	}else{
		ll M = N;
		for(int i=0;i<=N;i++){
			ll p[2];
			p[0] = i;
			p[1] = N-i;
			ll res = 0;
			int cnt = 0;
			for(int j=0;j<3;j++){
				if(g[0][j]>=g[1][j])continue;
				res += ((p[cnt]/a[j])*b[j])+(p[cnt]%a[j]);
				cnt++;
			}
			assert(cnt==2);
			M = max(M,res);
		}
		ll ans = M;
		for(int i=0;i<3;i++){
			if(g[0][i]<g[1][i])continue;
			ans = max(ans,(M/a[i])*b[i]+(M%a[i]));
		}
		cout << ans << endl;
	}
	return 0;
}