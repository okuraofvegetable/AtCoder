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

void solve(){
  int k,q;
  cin >> k >> q;
  vector<ll> d(k);
  cin >> d;
  for(int i=0;i<q;i++){
    ll n,x,m;
    cin >> n >> x >> m;
    n--;
    x %= m;
    vector<ll> v = d;
    for(int j=0;j<k;j++){
      v[j]%=m;
      if(v[j]==0)v[j] = m;
    }
    ll Sv = accumulate(all(v),0ll);
    ll s = x + Sv * (n/k) + accumulate(v.begin(),v.begin()+(n%k),0ll);
    cout << n-s/m << endl;
  }
  return ;
}
 
signed main(){
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
