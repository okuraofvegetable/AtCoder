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
using T = tuple<ll,ll,ll>;
int X,Y,Z;
int N;
T h[100100];
ll bsum[100100];
ll cb[100100];
ll asum[100100];
ll ca[100100];
priority_queue<ll> q;
int main(){
  cin >> X >> Y >> Z;
  N = X+Y+Z;
  for(int i=0;i<N;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    h[i] = make_tuple(a,b,c);
  }
  sort(h,h+N,[](T a,T b){return get<0>(a)-get<1>(a) < get<0>(b)-get<1>(b);});
  // for(int i=0;i<N;i++){
  //   ll a,b,c;
  //   tie(a,b,c) = h[i];
  //   cout << a << ' ' << b << ' ' << c << endl;
  // }
  ll bs = 0ll;
  for(int i=0;i<Y;i++){
    bs += get<1>(h[i]);
    ll d = get<2>(h[i])-get<1>(h[i]);
    q.push(d);
  }
  bsum[Y-1] = bs;
  cb[Y-1] = 0ll;
  for(int i=0;i<Z;i++){
    bsum[Y+i] = bsum[Y+i-1]+get<1>(h[Y+i]);
    ll d = get<2>(h[Y+i])-get<1>(h[Y+i]);
    q.push(d);
    cb[Y+i] = cb[Y+i-1]+q.top();
    q.pop();
  }
  while(!q.empty()){q.pop();}

  ll as = 0ll;
  for(int i=0;i<X;i++){
    as += get<0>(h[N-1-i]);
    ll d = get<2>(h[N-1-i])-get<0>(h[N-1-i]);
    q.push(d);
  }
  asum[N-X] = as;
  cb[N-X] = 0ll;
  for(int i=0;i<Z;i++){
    asum[N-X-1-i] = asum[N-X-i]+get<0>(h[N-X-1-i]);
    ll d = get<2>(h[N-X-1-i])-get<0>(h[N-X-1-i]);
    q.push(d);
    ca[N-X-1-i] = ca[N-X-i]+q.top();
    q.pop();
  }
  // for(int i=0;i<5;i++){
  //   cout << asum[i] << ' ';
  // }
  // cout << endl;
  // for(int i=0;i<5;i++){
  //   cout << bsum[i] << ' ';
  // }
  // cout << endl;
  // for(int i=0;i<5;i++){
  //   cout << cb[i] << ' ';
  // }
  // cout << endl;
  // for(int i=0;i<5;i++){
  //   cout << ca[i] << ' ';
  // }
  // cout << endl;
  ll ans = 0ll;
  for(int i=Y-1;i<N-X;i++){
    ans = max(ans,bsum[i]+cb[i]+asum[i+1]+ca[i+1]);
  }
  cout << ans << endl;
	return 0;
}
