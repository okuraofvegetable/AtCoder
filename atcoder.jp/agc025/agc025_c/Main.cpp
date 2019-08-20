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
ll L[100100],R[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> L[i] >> R[i];
	}
	sort(L,L+N);
	reverse(L,L+N);
	sort(R,R+N);
	int r = 0;
	ll now = 0ll;
	ll ans = 0ll;
	for(int l=0;l<=N;l++){
		if(l>0)now += 2ll*L[l-1];
		while(r<l-1){
			now += -2ll*R[r];
			r++;
		}
		while(r<l+1&&r<N){
			if(R[r]<0){
				now += -2*R[r];
				r++;
			}else{
				break;
			}
		}
		ans = max(ans,now);
	}
	cout << ans << endl;
	return 0;
}