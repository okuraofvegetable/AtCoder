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
#define MOD 1000000007
int N;
int x[105],y[105];
double dist(int a,int b){
	return sqrt(sq(x[a]-x[b])+sq(y[a]-y[b]));
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	double ans=0.0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			chmax(ans,dist(i,j));
		}
	}
	printf("%.12f\n",ans);
	return 0;
}