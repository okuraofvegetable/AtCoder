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
int N,M;
int X[100100];
int cnt[100100];
int sz[100100];
int sol[100100];
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> X[i];
    cnt[X[i]]++;
  }
  for(int i=0;i<=100000;i++){
    sz[i%M] += cnt[i];
    sol[i%M] += (cnt[i]%2);
  }
  int ans = 0;
  for(int i=1;i<(M+1)/2;i++){
    // cout << i << ' ' << M-i << endl;
    if(sz[i]>sz[M-i]){
      swap(sz[i],sz[M-i]);
      swap(sol[i],sol[M-i]);
    }
    ans += sz[i];
    int w = max(0,sol[M-i]-sz[i]);
    ans += (sz[M-i]-sz[i]-w)/2;
  }
  ans += sz[0]/2;
  if(M%2==0)ans += sz[M/2]/2;
  cout << ans << endl;
	return 0;
}
