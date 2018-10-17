#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
struct vertex{
	double x,y,r;
	int type; //1:circle 0:point
	vertex(){}
	vertex(double x,double y,double r,int t):x(x),y(y),r(r),type(t){}
};
double D(vertex a,vertex b){
	int s = a.type+b.type;
	double k = sqrt(sq(a.x-b.x)+sq(a.y-b.y));
	if(s==0){
		return k;
	}else if(s==1){
		if(a.type<b.type)swap(a,b);
		return max(0.0,k-a.r);
	}else{
		return max(0.0,k-a.r-b.r);
	}
}
int N;
vertex v[1010];
double dist[1010];
bool used[1010];
int main(){
	for(int i=0;i<2;i++){
		scanf("%lf %lf",&v[i].x,&v[i].y);
		v[i].r = -1;
		v[i].type = 0;
	}
	scanf("%d",&N);
	for(int i=2;i<N+2;i++){
		scanf("%lf %lf %lf",&v[i].x,&v[i].y,&v[i].r);
		v[i].type = 1;
	}
	N+=2;
	for(int i=0;i<N;i++)dist[i]=1e50;
	dist[0]=0.0;
	for(int i=0;i<N;i++){
		int id = -1;
		double val = 1e50;
		for(int j=0;j<N;j++){
			if(!used[j]&&dist[j]<val){
				val = dist[j];
				id = j;
			}
		}
		used[id]=true;
		for(int j=0;j<N;j++){
			double d = D(v[id],v[j]);
			if(dist[j]>dist[id]+d){
				dist[j] = dist[id]+d;
			}
		}
	}
	printf("%.12f\n",dist[1]);
	return 0;
}