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
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl;
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
template<class T,class U>
ostream& operator << (ostream& os,pair<T,U>& p){
	os << p.fi << ',' << p.sec; return os;
}
template<class T,class U>
istream& operator >> (istream& is,pair<T,U>& p){
	is >> p.fi >> p.sec; return is;
}
template<class T>
ostream& operator << (ostream &os,const vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		os << vec[i];
		if(i+1<vec.size())os << ' ';
	}
	return os;
}
template<class T>
istream& operator >> (istream &is,vector<T>& vec){
	for(int i=0;i<vec.size();i++)is >> vec[i];
	return is;
}
void fastio(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
}
const int SIZE = 1<<18;
struct segtree{
	ll minimum[SIZE*2],lazy[SIZE*2];
	void lazy_evaluate(int k){
		minimum[k]+=lazy[k];
    // k isn't leaf of SegmentTree
		if(k<SIZE-1){
			lazy[2*k+1]+=lazy[k];
			lazy[2*k+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void update(int a,int b,int k,int l,int r,ll x){
		lazy_evaluate(k);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			lazy[k]+=x;
			lazy_evaluate(k);
		}else{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			minimum[k] = max(minimum[k*2+1],minimum[k*2+2]);
			return;
		}
	}
	ll query(int a,int b,int k,int l,int r){
		lazy_evaluate(k);
		if(r<=a||b<=l)return -LLINF; // min,max henkouji chuui !!!!!!!
		if(a<=l&&r<=b)return minimum[k];
		else{
			ll lch = query(a,b,k*2+1,l,(l+r)/2);
			ll rch = query(a,b,k*2+2,(l+r)/2,r);
			return max(lch,rch);
		}
	}
}seg;
int N,M;
int l[200100],r[200100];
ll a[200100];
vector<int> id[200100];
int main(){
  cin >> N >> M;
  for(int i=0;i<M;i++){
    cin >> l[i] >> r[i] >> a[i];
    id[r[i]].pb(i);
  }
  for(int i=1;i<=N;i++){
    ll x = seg.query(0,i,0,0,SIZE);
    for(int j=0;j<id[i].size();j++){
      int idx = id[i][j];
      x += a[idx];
      seg.update(l[idx],r[idx],0,0,SIZE,a[idx]);
    }
    seg.update(i,i+1,0,0,SIZE,x);
  } 
  ll ans = 0ll;
  for(int i=0;i<=N;i++){
    chmax(ans,seg.query(i,i+1,0,0,SIZE));
  }
  cout << ans << endl;
	return 0;
}
