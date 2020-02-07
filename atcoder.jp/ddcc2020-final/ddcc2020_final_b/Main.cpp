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
#define LLINF 100000000000000000ll // 1e17
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

// matrix class
// constructor of T : T(1),T(0) must be unit of T
template <class T>
struct Matrix{
  int H,W;
  vector<vector<T>> elem;
  Matrix(int H,int W,T val = T(0)):H(H),W(W){
    elem.resize(H);
    for(int i=0;i<H;i++)elem[i].assign(W,val);
  }
  Matrix(const vector<vector<T>> &m) : H(m.size()), W(m.size() ? m[0].size() : 0) {
    elem.resize(H);
    for(int i=0;i<H;i++)elem[i].resize(W);
    for(int i=0;i<H;i++) elem[i] = m[i];
  }
  vector<T>& operator [] (int h) {
    return elem[h];
  }
  static Matrix identity(int N) {
    Matrix a(N,N);
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(i==j)a.elem[i][i] = T(1);
        else a.elem[i][j] = T(0);
      }
    }
    return a;
  }
  Matrix operator + (const Matrix &m) const {
    assert( H==m.H && W==m.W );
    Matrix a(H,W);
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        a.elem[i][j] = this->elem[i][j] + m.elem[i][j];
      }
    }
    return a;
  }
  Matrix operator - (const Matrix &m) const {
    assert( H==m.H && W==m.W );
    Matrix a(H,W);
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        a.elem[i][j] = this->elem[i][j] - m.elem[i][j];
      }
    }
    return a;
  }
  Matrix operator * (const Matrix &m) const {
    assert( W == m.H );
    Matrix a(H,m.W);
    for(int i=0;i<H;i++){
      for(int j=0;j<m.W;j++){
        for(int k=0;k<W;k++){
          a.elem[i][j] = a.elem[i][j] + (this->elem[i][k] * m.elem[k][j]);
        }
      }
    }
    return a;
  }
  Matrix &operator+= (const Matrix &m) { return *this = *this + m; }
  Matrix &operator-= (const Matrix &m) { return *this = *this - m; }
  Matrix &operator*= (const Matrix &m) { return *this = *this * m; }
  Matrix pow(long long x) const {
    Matrix a = identity(H);
    Matrix b = *this;
    while(x){
      if(x&1)a *= b;
      b *= b;
      x >>= 1;
    }
    return a;
  }
  friend ostream & operator << (ostream &os, const Matrix &x) {
    for(int i=0;i<x.H;i++){
      for(int j=0;j<x.W;j++){
        os << x.elem[i][j];
        if(j+1<x.W)cout << ' ';
      }
      if(i+1<x.H)cout << endl;
    }
    return os;
  }
  friend istream & operator >> (istream &is, Matrix &x) {
    for(auto &v : x.elem) is >> v;
    return is;
  }
};

struct Data{
  ll a,b; // max(x+a,b)
  Data(){}
  Data(ll a,ll b):a(a),b(b){}
  Data(ll u){
    if(u==0){
      a = -LLINF;
      b = -LLINF;
    }else if(u==1){
      a = 0;
      b = -LLINF;
    }else{
      assert(false);
    }
  }
  Data operator + (const Data& d) const { 
    return Data(max(a,d.a),max(b,d.b));
  }
  Data operator * (const Data& d) const { 
    if(d.a==-LLINF && d.b==-LLINF)return Data(0);
    if(d.a==0 && d.b==-LLINF)return Data(a,b);
    if(a==-LLINF && a==-LLINF)return Data(0);
    if(a==0 && b==-LLINF)return d;
    return Data(a+d.a,max(b+d.a,d.b));
  }
  friend ostream & operator << (ostream &os, const Data &x) {
    os << x.a << ',' << x.b;
    return os;
  }
};

signed main(){
  fastio();
  int N,M,S,K;
  ll W;
  cin >> N >> M >> W >> S >> K;
  S--;
  Matrix<Data> m(N,N,Data(0));
  for(int i=0;i<M;i++){
    int u,v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    m.elem[u][v] = Data(w,0);
  }
  auto powm = m.pow(K);
  ll ans = -1ll;
  for(int j=0;j<N;j++){
    chmax(ans,max(powm[S][j].a+W,powm[S][j].b));
  }
  cout << ans << endl;
  return 0;
}
