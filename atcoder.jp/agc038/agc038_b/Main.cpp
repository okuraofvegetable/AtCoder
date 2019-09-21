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
int N,K;
int a[200100];
set<int> s;
int rmi[200100],rmx[200100];
bool sorted[200100];
int main(){
  cin >> N >> K;
  for(int i=0;i<N;i++){
    cin >>a[i];
  }
  int ans = 0;
  for(int i=0;i<K;i++)s.insert(a[i]);
  for(int i=K-1;i<N;i++){
    rmi[i] = *s.begin();
    rmx[i] = *s.rbegin();
    s.erase(a[i-K+1]);
    if(i+1<N)s.insert(a[i+1]);
  }
  int cnt = 1;
  for(int i=1;i<N;i++){
    if(a[i]>a[i-1])cnt++;
    else cnt = 1;
    if(cnt>=K)sorted[i] = true;
  }
  // for(int i=0;i<N;i++){
  //   cout << rmi[i] << ' ' << rmx[i] << endl;
  // }
  int s = 0;
  if(sorted[K-1])s = 1;
  else ans = 1;
  for(int i=K;i<N;i++){
    if(sorted[i]){
      s = max(1,s);
      continue;
    }
    if(rmi[i-1]!=a[i-K]||rmx[i]!=a[i])ans++;
  }
  cout << ans+s << endl;
	return 0;
}
