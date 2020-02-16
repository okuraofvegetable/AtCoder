#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000 //2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define dmp(x) cerr << #x << ": " << x << endl;

template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T,vector<T>,greater<T>>;
template<class T> vector<T> vect(int len,T elem){ return vector<T>(len,elem); }

template<class T,class U>
ostream& operator << (ostream& os,const pair<T,U>& p){
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
namespace Util{
  template<class T>
  vector<pair<T,int>> runLength(vector<T> v){
    vector<pair<T,int>> res;
    for(int i=0;i<v.size();i++){
      if(res.empty()||res.back().first!=v[i])res.push_back(make_pair(v[i],1));
      else res.back().second++;
    }
    return res;
  }
  template<class T>
  void compress(vector<T> &v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
  }
}

// X ika
ll check(ll X,vector<ll>& A){
  ll res = 0ll;
  for(int i=1;i<A.size();i++){
    if(A[i]>0ll){
      ll c = X/A[i]-10;
      while(A[i]*c<=X)c++; // kakete X yori dai
      //dmp(c);
      int k = lower_bound(A.begin(),A.begin()+i,c)-A.begin();
      //dmp(k);
      res += k;
    }else if(A[i]==0ll){
      if(X>=0ll)res += i;
    }else{
      ll c = X/A[i]-10;
      while(A[i]*c>X)c++;
      //dmp(c);
      int k = A.begin()+i-lower_bound(A.begin(),A.begin()+i,c);
      //dmp(k);
      res += k;
    }
  }
  return res;
}

void solve(){
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  cin >> A;
  sort(all(A));
  // dmp(check(-8,A));
  // dmp(check(-6,A));
  // dmp(check(8,A));
  // dmp(check(9,A));
  //return ;

  ll l = -LLINF, r = LLINF;
  while(r-l>1ll){
    ll mid = (l+r)/2;
    if(check(mid,A)<K)l = mid;
    else r = mid;
  }
  cout << r << endl;
  return ;
}
 
signed main(){
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
