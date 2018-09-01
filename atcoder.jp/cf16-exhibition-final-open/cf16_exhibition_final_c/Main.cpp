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
int N;
int a[100100];
int b,s;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		b |= (a[i]&(-a[i]));
		s ^= a[i];
	}
	int ans = 0;
	for(int i=30;i>=0;i--){
		int a = ((s>>i)&1)^(ans&1);
		if(a==1){
			if((b>>i)&1){
				ans++;
			}else{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}