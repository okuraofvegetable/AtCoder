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
struct UnionFind{
  int par[100100];
  UnionFind(){
    for(int i=0;i<100100;i++){
      par[i] = i;
    }
  }
  int find(int x){
    if(par[x]==x)return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x,int y){
    if(find(x)==find(y))return;
    par[find(x)] = find(y);
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
}uf;
int N,M;
vector<int> talk[100100];
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    int K;
    cin >> K;
    for(int j=0;j<K;j++){
      int lang;
      cin >> lang;
      lang--;
      talk[lang].pb(i);
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j+1<talk[i].size();j++){
      uf.unite(talk[i][j],talk[i][j+1]);
    }
  }
  bool ans = true;
  for(int i=0;i<N;i++){
    if(!uf.same(0,i)){
      ans = false;
      break;
    }
  }
  if(ans)cout << "YES" << endl;
  else cout << "NO" << endl;
	return 0;
}
