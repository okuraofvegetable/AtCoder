#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll N,A,B;
int main(){
	cin >> N >> A >> B;
	if(!(A+B-1<=N&&N<=A*B)){
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans;
	for(int i=B;i>=1;i--)ans.pb(i);
	int M = B;
	if(A>1){
		int k = (N-B)/(A-1);
		int rem = (N-B)%(A-1);
		for(int i=0;i<rem;i++){
			for(int j=k+1;j>=1;j--){
				ans.pb(M+j);
			}
			M += k+1;
		}
		for(int i=0;i<A-1-rem;i++){
			for(int j=k;j>=1;j--){
				ans.pb(M+j);
			}
			M+=k;
		}
	}
	for(int i=0;i<ans.size();i++){
		printf("%d%c",ans[i],(i+1==ans.size())?'\n':' ');
	}
	return 0;
}