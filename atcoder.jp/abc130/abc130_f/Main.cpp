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
long double x[100100],y[100100];
char d[100100];
long double DINF = 1e18;
long double Umax,Umin;
long double Dmax,Dmin;
long double Lmax,Lmin;
long double Rmax,Rmin;
long double Ymin,Ymax;
long double Xmin,Xmax;
long double f(long double t){
	long double Y = max(Ymax,max(Umax+t,Dmax-t))-min(Ymin,min(Umin+t,Dmin-t));
	long double X = max(Xmax,max(Rmax+t,Lmax-t))-min(Xmin,min(Rmin+t,Lmin-t));
	//cout << t << ' ' << X << ' ' << Y << endl;
	return X*Y;
}
int main(){
	cin >> N;
	Umax = -DINF;
	Umin = DINF;
 
	Dmax = -DINF;
	Dmin = DINF;
 
	Lmax = -DINF;
	Lmin = DINF;
 
	Rmax = -DINF;
	Rmin = DINF;
 
	Xmax = -DINF;
	Xmin = DINF;
 
	Ymax = -DINF;
	Ymin = DINF;
	for(int i=0;i<N;i++){
		cin >> x[i] >> y[i] >> d[i];
		if(d[i]=='U'){
			Umax = max(Umax,y[i]);
			Umin = min(Umin,y[i]);
			Xmax = max(Xmax,x[i]);
			Xmin = min(Xmin,x[i]);
		}else if(d[i]=='D'){
			Dmax = max(Dmax,y[i]);
			Dmin = min(Dmin,y[i]);
			Xmax = max(Xmax,x[i]);
			Xmin = min(Xmin,x[i]);
		}else if(d[i]=='L'){
			Lmax = max(Lmax,x[i]);
			Lmin = min(Lmin,x[i]);
			Ymax = max(Ymax,y[i]);
			Ymin = min(Ymin,y[i]);
		}else{
			Rmax = max(Rmax,x[i]);
			Rmin = min(Rmin,x[i]);
			Ymax = max(Ymax,y[i]);
			Ymin = min(Ymin,y[i]);
		}
	}
	//cout << f(0.0) << endl;
  cout << fixed << setprecision(20);
  vector<long double> cand;

  cand.pb(0.0);

  cand.pb(Ymin-Umax);
  cand.pb(Ymax-Umax);
  cand.pb((Dmin-Umax)/2.0);
  cand.pb((Dmax-Umax)/2.0);
  cand.pb(Ymin-Umin);
  cand.pb(Ymax-Umin);
  cand.pb((Dmin-Umin)/2.0);
  cand.pb((Dmax-Umin)/2.0);
  cand.pb(Dmin-Ymax);
  cand.pb(Dmin-Ymin);
  cand.pb(Dmax-Ymax);
  cand.pb(Dmax-Ymin);
  
  cand.pb(Xmin-Rmax);
  cand.pb(Xmax-Rmax);
  cand.pb((Lmin-Rmax)/2.0);
  cand.pb((Lmax-Rmax)/2.0);
  cand.pb(Xmin-Rmin);
  cand.pb(Xmax-Rmin);
  cand.pb((Lmin-Rmin)/2.0);
  cand.pb((Lmax-Rmin)/2.0);
  cand.pb(Lmin-Xmax);
  cand.pb(Lmin-Xmin);
  cand.pb(Lmax-Xmax);
  cand.pb(Lmax-Xmin);

  long double ans = DINF;
  for(int i=0;i<cand.size();i++){
    if(cand[i]<0.0)continue;
    chmin(ans,f(cand[i]));
  }
  cout << ans << endl;
	return 0;
}
