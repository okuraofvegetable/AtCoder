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
double add(double a,double b){
	if(abs(a+b)<eps*(abs(a)+abs(b)))return 0;
	return a+b;
}
struct P{
	double x,y;
	int id;
	P() {}
	P(double x,double y):x(x),y(y){}
	P operator +(P p){
		return P(add(x,p.x),add(y,p.y));
	}
	P operator -(P p){
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator *(double d){
		return P(d*x,d*y);
	}
	double dot(P p){
		return add(x*p.x,y*p.y);
	}
	double det(P p){
		return add(x*p.y,-y*p.x);
	}
	double norm(){
		return sqrt(sq(x)+sq(y));
	}
	bool operator < (const P& p) const{
		if(x!=p.x)return x<p.x;
		else return y<p.y;
	}
};
vector<P> convex_hull(P* ps,int n)
{
	sort(ps,ps+n);
	int k=0;
	vector<P> qs(2*n);
	for(int i=0;i<n;i++)
	{
		while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0)k--;
		qs[k++]=ps[i];
	}
	for(int i=n-2,t=k;i>=0;i--)
	{
		while(k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0)k--;
		qs[k++]=ps[i];
	}
	qs.resize(k-1);
	return qs;
}
P normal(P a){
	return P(a.y,-a.x);
}
double calc(P a,P b){
	return acos(a.dot(b)/a.norm()/b.norm())/2.0/M_PI;
}
int N;
P v[105];
double ans[105];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		scanf("%lf %lf",&v[i].x,&v[i].y);
		v[i].id=i;
	}
	if(N==2){
		printf("0.5\n0.5\n");
		return 0;
	}
	vector<P> cv = convex_hull(v,N);
	int M = cv.size();
	for(int i=0;i<M;i++){
		int idx = cv[i].id;
		if(M==2)ans[idx]=0.5;
		else ans[idx] = calc(normal(cv[i]-cv[(i+M-1)%M]),normal(cv[(i+1)%M]-cv[i]));
	}
	for(int i=0;i<N;i++)printf("%.16f\n",ans[i]);
	return 0;
}