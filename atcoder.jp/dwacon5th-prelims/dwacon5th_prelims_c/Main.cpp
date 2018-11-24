#include <bits/stdc++.h>
using namespace std;
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
int N;
string S;
int Q;
ll Crui[2000100];
ll pre[2000100]; // previous M
ll preC[2000100]; // previous M only at M
void print(ll *a){
	for(int i=0;i<=N;i++)printf("%lld ",a[i]);
	printf("\n");
}
int main(){
	cin >> N;
	cin >> S;
	for(int i=0;i<S.size();i++){
		if(S[i]=='C'){
			Crui[i+1]=1;
		}
		if(S[i]=='M'){
			pre[i+1]=1;
		}
	}
	for(int i=1;i<=2*N;i++){
		pre[i+1]+=pre[i];
		Crui[i+1]+=Crui[i];
	}
	for(int i=0;i<N;i++){
		if(S[i]=='C'){
			preC[i+1]=pre[i+1];
		}
	}
	for(int i=1;i<=2*N;i++){
		preC[i+1]+=preC[i];
	}
	/*printf("\n");
	for(int i=0;i<=2*N;i++)printf("%d ",i);
	printf("\n");
	print(pre);
	print(Crui);
	print(preC);*/
	cin >> Q;
	for(int i=0;i<Q;i++){
		int k;
		cin >> k;
		ll ans = 0ll;
		for(int j=0;j<N;j++){
			if(S[j]=='D'){
				ans += (preC[j+k]-preC[j])-pre[j+1]*(Crui[j+k]-Crui[j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}