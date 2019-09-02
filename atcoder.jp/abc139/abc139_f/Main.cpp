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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
struct data{
	double x,y;
	data(){}
	data(double x,double y):x(x),y(y){}
	bool operator < (const data& a) const{
		return atan2(x,y) < atan2(a.x,a.y);
	}
};
vector<data> A;
int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		double x,y;
		cin >> x >> y;
		if(EQ(x,0.0)&&EQ(y,0.0))continue;
		A.pb(data(x,y));
	}
	sort(all(A));
	double ans = 0.0;
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A.size();j++){
			double xs = 0.0;
			double ys = 0.0;
			for(int k=i;;k=(k+1)%A.size()){
				xs += A[k].x;
				ys += A[k].y;
				if(k==j)break;
			}
			chmax(ans,sqrt(sq(xs)+sq(ys)));
		}
	}
	printf("%.15f\n",ans);
	return 0;
}
