#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-15
#define INF 1000000000
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
int A[305][305];
int B[305][305];
ll ans = 0;
int used[305][305];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&A[i][j]);
		}
	}
	memset(used,false,sizeof(used));
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(k==i||k==j)continue;
				if(A[i][k]+A[k][j]==A[i][j]){
					used[i][j]=true;
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			B[i][j]=A[i][j];
			if(used[i][j])B[i][j]=INF;
			else ans += (ll)B[i][j];
			//cout << B[i][j] << ' ';
		}
		//cout << endl;
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				chmin(B[i][j],B[i][k]+B[k][j]);
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if((A[i][j]!=B[i][j])||(i==j&&B[i][j]!=0)){
				printf("-1\n");
				return 0;
			}
		}
	}
	cout << ans/2 << endl;
	return 0;
}