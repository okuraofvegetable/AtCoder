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
struct Point{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	Point operator + (Point a){
		return Point(x+a.x,y+a.y);
	}
	Point operator - (Point a){
		return Point(x-a.x,y-a.y);
	}
	double dot(Point a){
		return x*a.x+y*a.y;
	}
	double det(Point a){
		return x*a.y-y*a.x;
	}
	double norm(){
		return sqrt(x*x+y*y);
	}
	double norm2(){
		return x*x+y*y;
	}
	void dump(){
		printf("x:%.12f y:%.12f\n",x,y);
	}
};
typedef Point Vector;
double f(double x){
	return x/(sqrt(1.0+x*x)-1.0);
}
double tan(Vector a,Vector b){
	if(abs(a.dot(b))<eps)return 1.0;
	return abs(f(a.det(b)/a.dot(b)));
}
Point v[3];
double solve(){
	Vector ab = v[1]-v[0];
	Vector ac = v[2]-v[0];
	Vector ba = v[0]-v[1];
	Vector bc = v[2]-v[1];
	return ab.norm()/(tan(ab,ac)+tan(ba,bc)+2.0);
}
void rotate(){
	Point tmp = v[2];
	for(int i=1;i>=0;i--)v[i+1]=v[i];
	v[0] = tmp;
}
int main(){
	for(int i=0;i<3;i++){
		int x,y;
		cin >> x >> y;
		v[i] = Point(x,y);
	}
	double ans = 0.0;
	for(int i=0;i<3;i++){
		ans = max(ans,solve());
		rotate();
	}
	printf("%.12f\n",ans);
	return 0;
}