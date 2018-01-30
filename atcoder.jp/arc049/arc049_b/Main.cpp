#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000.0
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
priority_queue<P,vector<P>,greater<P> > q;
int N;
int x[100100],y[100100],c[100100];
bool check(double X){
	P rX = P(-INF,INF);
	P rY = P(-INF,INF);
	for(int i=0;i<N;i++){
		double r = X/(double)c[i];
		P rx = P(x[i]-r,x[i]+r);
		P ry = P(y[i]-r,y[i]+r);
		chmax(rX.fi,rx.fi);
		chmin(rX.sec,rx.sec);
		chmax(rY.fi,ry.fi);
		chmin(rY.sec,ry.sec);
	}
	if(rX.fi>rX.sec||rY.fi>rY.sec)return false;
	return true;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&x[i],&y[i],&c[i]);
	}
	double l = 0,r = INF;
	for(int i=0;i<100;i++){
		double mid = (l+r)/2.0;
		if(check(mid))r = mid;
		else l = mid;
	}
	printf("%.12f\n",r);
	return 0;
}