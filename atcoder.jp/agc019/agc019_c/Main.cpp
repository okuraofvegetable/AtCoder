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
const int SIZE = 1<<18;
struct segtree{
	int seg[SIZE*2];
	void init(){
		for(int i=0;i<SIZE*2;i++)seg[i]=0;
	}
	void update(int k,int x){
		k+=SIZE-1;
		seg[k]=max(seg[k],x);
		while(k){
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k=0,int l=0,int r=SIZE){
		if(r<=a||b<=l)return -INF;
		else if(a<=l&&r<=b)return seg[k];
		else{
			int lch = query(a,b,k*2+1,l,(l+r)/2);
			int rch = query(a,b,k*2+2,(l+r)/2,r);
			return max(lch,rch);
		}
	}
}seg;
P s,t;
int N;
vector<P> vec;
vector<int> zipx;
bool comp(const P& a,const P& b){
	return a.sec<b.sec;
}
int main(){
	seg.init();
	cin >> s.fi >> s.sec;
	cin >> t.fi >> t.sec;
	if(s.fi>t.fi)swap(s,t);
	int limit = min(abs(s.fi-t.fi),abs(s.sec-t.sec))+1;
	double ans = (double)(abs(s.fi-t.fi)+abs(s.sec-t.sec))*(double)100.0;
	zipx.pb(s.fi);zipx.pb(t.fi);
	cin >> N;
	vec.resize(N);
	for(int i=0;i<N;i++){
		cin >> vec[i].fi >> vec[i].sec;
		zipx.pb(vec[i].fi);
	}
	/*if(s.fi==t.fi){
		double add = 10.0*M_PI-20.0;
		for(int i=0;i<N;i++){
			if(vec[i].fi==s.fi&&vec[i].sec>min(s.sec,t.sec)&&vec[i].sec<max(s.sec,t.sec)){
				ans += add;
			}
		}
		printf("%.15f\n",ans);
		return 0;
	}
	if(s.sec==t.sec){
		double add = 10.0*M_PI-20.0;
		for(int i=0;i<N;i++){
			if(vec[i].sec==s.sec&&vec[i].fi>min(s.fi,t.fi)&&vec[i].fi<max(s.fi,t.fi)){
				ans += add;
			}
		}
		printf("%.15f\n",ans);
		return 0;
	}*/
	if(s.sec>t.sec){
		for(int i=0;i<N;i++)vec[i].sec*=-1;
		s.sec*=-1;
		t.sec*=-1;
	}
	sort(all(zipx));
	zipx.erase(unique(all(zipx)),zipx.end());
	for(int i=0;i<N;i++)vec[i].fi=lower_bound(all(zipx),vec[i].fi)-zipx.begin();
	s.fi = lower_bound(all(zipx),s.fi)-zipx.begin();
	t.fi = lower_bound(all(zipx),t.fi)-zipx.begin();
	sort(all(vec),comp);
	vector<int> zipy;
	for(int i=0;i<vec.size();i++)zipy.pb(vec[i].sec);
	/*for(int i=0;i<vec.size();i++){
		cout << vec[i].fi << ' ' << vec[i].sec << endl;
	}*/
	int S = lower_bound(all(zipy),s.sec)-zipy.begin();
	int T = upper_bound(all(zipy),t.sec)-zipy.begin();
	for(int i=S;i<T;i++){
		int upd = seg.query(s.fi,vec[i].fi+1)+1;
		seg.update(vec[i].fi,upd);
	}
	int ma = seg.query(s.fi,t.fi+1);
	if(ma<limit){
		double add = 5.0*M_PI-20.0;
		ans += add*ma;
		printf("%.15f\n",ans);
	}else{
		double add = 5.0*M_PI-20.0;
		double add2 = 10.0*M_PI-20.0;
		ans += add*(ma-1);
		ans += add2;
		printf("%.15f\n",ans);
	}
	return 0;
}