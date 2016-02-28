#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
typedef pair<P,P> Seg;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define sq(x) ((x)*(x))
#define EQ(a,b) (abs((a)-(b))<eps)
bool intersect(Seg a,Seg b){
	double x1,x2,x3,x4,y1,y2,y3,y4,ta,tb;
	x1 = a.fi.fi; x2 = a.sec.fi; x3 = b.fi.fi; x4 = b.sec.fi;
	y1 = a.fi.sec;y2 = a.sec.sec;y3 = b.fi.sec;y4 = b.sec.sec;
	ta = (x1-x2)*(y3-y1)+(y1-y2)*(x1-x3);
	tb = (x1-x2)*(y4-y1)+(y1-y2)*(x1-x4);
	if(ta*tb>0.0)return false;
	swap(a,b);
	x1 = a.fi.fi; x2 = a.sec.fi; x3 = b.fi.fi; x4 = b.sec.fi;
	y1 = a.fi.sec;y2 = a.sec.sec;y3 = b.fi.sec;y4 = b.sec.sec;
	ta = (x1-x2)*(y3-y1)+(y1-y2)*(x1-x3);
	tb = (x1-x2)*(y4-y1)+(y1-y2)*(x1-x4);
	if(ta*tb>0.0)return false;
	return true;
}
double dist(P a,P b){
	return sqrt(sq(b.fi-a.fi)+sq(b.sec-a.sec));
}
vector<Seg> wall;
bool check(P a,P b){
	Seg s = Seg(a,b);
	for(int i=0;i<wall.size();i++){
		if(intersect(wall[i],s))return false;
	}
	return true;
}
vector<P> pos;
int a,b,c,w,h;
double d[250][250];
int main(){
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d",&w,&h);
	for(int i=0;i<a;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		pos.pb(P(x,y));
	}
	for(int i=0;i<b;i++){
		double s,t,u,v;
		scanf("%lf %lf %lf %lf",&s,&t,&u,&v);
		pos.pb(P(s,t));
		pos.pb(P(s,v));
		pos.pb(P(u,v));
		pos.pb(P(u,t));
		s+=eps;
		t+=eps;
		u-=eps;
		v-=eps;
		P st = P(s,t);
		P sv = P(s,v);
		P uv = P(u,v);
		P ut = P(u,t);
		wall.pb(Seg(st,sv));
		wall.pb(Seg(sv,uv));
		wall.pb(Seg(uv,ut));
		wall.pb(Seg(ut,st));
	}
	for(int i=0;i<c;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		pos.pb(P(x,y));
	}
	int ps = pos.size();
	for(int i=0;i<ps;i++){
		for(int j=0;j<ps;j++){
			d[i][j]=1000000000.0;
			if(i==j)d[i][j]=0.0;
			else if(check(pos[i],pos[j]))d[i][j]=dist(pos[i],pos[j]);
		}
	}
	for(int k=0;k<ps;k++){
		for(int i=0;i<ps;i++){
			for(int j=0;j<ps;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);	
			}
		}
	}
	double ans = 0.0;
	for(int i=0;i<c;i++){
		double res = 1000000000.0;
		for(int j=0;j<a;j++){
			res = min(res,d[ps-i-1][j]);
		}
		ans += res;
		//cout << res << endl;
	}
	ans*=2.0;
	printf("%.3f\n",ans);
	return 0;
}