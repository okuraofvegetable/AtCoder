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
int N;
struct block{
  int w,s;
  ll v;
  block(){}
  block(int w,int s,ll v):w(w),s(s),v(v){}
  bool operator < (const block& a) const {
    return w+s < a.w+a.s;
  }
};
block bs[1010];
ll dp[1010][20010];
int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> bs[i].w >> bs[i].s >> bs[i].v;
  }
  sort(bs,bs+N);
  for(int i=0;i<=N;i++){
    for(int j=0;j<=10000;j++){
      dp[i][j] = -LLINF;
    }
  }
  dp[0][0] = 0ll;
  for(int i=0;i<N;i++){
    for(int j=0;j<=10000;j++){
      if(dp[i][j]==-LLINF)continue;
      chmax(dp[i+1][j],dp[i][j]);
      if(bs[i].s>=j)chmax(dp[i+1][j+bs[i].w],dp[i][j]+bs[i].v);
    }
  }
  ll ans = -LLINF;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=20000;j++){
      if(dp[i][j]==-LLINF)continue;
      chmax(ans,dp[i][j]);
    }
  }
  cout << ans << endl;
	return 0;
}
