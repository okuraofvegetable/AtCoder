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
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
int B[1000100];
int main(){
	scanf("%d",&N);
	int f = -1;
	for(int i=0;i<N-1;i++)scanf("%d",&B[i]);
	int mx = 0;
	for(int i=0;i<N-1;i++){
		if(B[i]>mx+2){
			printf("0\n");
			return 0;
		}else if(B[i]==mx+2){
			if(f!=-1){
				printf("0\n");
				return 0;
			}
			f = mx+1;
		}
		mx = max(mx,B[i]);
	}
	ll ans = 0ll;
	if(f!=-1){
		mx = 0;
		for(int i=0;i<N;i++){
			if(mx==f-1)ans++;
			mx = max(mx,B[i]);
		}
		printf("%lld\n",ans);
	}else{
		mx = 0;
		for(int i=0;i<N;i++){
			int ub = mx+1;
			ans += ub;
			mx = max(mx,B[i]);
		}
		ans -= N-1;
		printf("%lld\n",ans);
	}
	return 0;
}