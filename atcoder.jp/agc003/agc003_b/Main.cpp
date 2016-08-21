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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
int A[100100];
ll ans = 0ll;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<N;i++){
		if(A[i]%2==1){
			ans += A[i]/2;
			A[i]=1;
		}
		if(A[i]%2==0&&A[i]>0){
			ans += A[i]/2-1;
			A[i]=2;
		}
	}
	if(A[0]==2){
		A[0]=0;
		ans++;
	}
	for(int i=1;i<N;i++){
		if(A[i]==0)continue;
		if(A[i-1]==1){
			A[i]--;
			A[i-1]--;
			ans++;
		}else{
			if(A[i]==2){
				ans++;
				A[i]=0;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}