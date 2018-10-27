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
vector<int> ans[1000];
int main(){
	cin >> N;
	int l = 1,r = 10000;
	while(r-l>1){
		int mid = (l+r)/2;
		if(mid*(mid+1)<=2*N)l=mid;
		else r = mid;
	}
	if(l*(l+1)==2*N){
		printf("Yes\n");
		printf("%d\n",l+1);
		int cnt = 0;
		for(int i=0;i<l+1;i++){
			for(int j=i+1;j<l+1;j++){
				ans[i].pb(cnt);
				ans[j].pb(cnt);
				cnt++;
			}
		}
		for(int i=0;i<l+1;i++){
			printf("%d ",l);
			for(int j=0;j<l;j++){
				printf("%d",ans[i][j]+1);
				if(j<l-1)printf(" ");
			}
			printf("\n");
		}
	}else{
		printf("No\n");
	}
	return 0;
}