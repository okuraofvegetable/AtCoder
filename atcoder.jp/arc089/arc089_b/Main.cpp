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
struct Imos2D{
	int v[1015][1015];
	void set(int i,int j){
		i++; j++;
		v[i][j]++;
	}
	void calc(){
		for(int i=0;i<1010;i++){
			for(int j=0;j<1010;j++){
				v[i][j+1] += v[i][j];
			}
		}
		for(int i=0;i<1010;i++){
			for(int j=0;j<1010;j++){
				v[i+1][j] += v[i][j];
			}
		}
	}
	int rect(int a,int b,int c,int d){ //[a,c][b,d]
		a++; b++; c++; d++;
		if(a>c||b>d)return 0;
		return v[c][d]-v[a-1][d]-v[c][b-1]+v[a-1][b-1];
	}
};
int N,K;
int x[100100],y[100100];
char c[100100];
Imos2D A[2];
int main(){
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d %d %c",&x[i],&y[i],&c[i]);
	}
	for(int i=0;i<N;i++){
		int X = x[i]%K;
		int Y = y[i]%K;
		int d = (x[i]/K+y[i]/K)%2;
		if(c[i]=='B')A[d].set(X,Y);
		else A[!d].set(X,Y);
	}
	for(int i=0;i<2;i++)A[i].calc();
	int ans = 0;
	for(int i=0;i<=K;i++){
		for(int j=0;j<=K;j++){
			int res = A[0].rect(0,0,i-1,j-1)+A[0].rect(i,j,K-1,K-1);
			res += A[1].rect(0,j,i-1,K-1)+A[1].rect(i,0,K-1,j-1);
			ans = max(ans,res);
			ans = max(ans,N-res);
		}
	}
	printf("%d\n",ans);
	return 0;
}