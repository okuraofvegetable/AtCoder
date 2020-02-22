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

template<class Cost>
struct edge{
  int from,to;
  Cost cost;
  int id;
  edge(){}
  edge(int from,int to,Cost cost,int id):from(from),to(to),cost(cost),id(id){}

  // for debug
  friend ostream& operator << (ostream& os,const edge& e) {
    os << e.from << " -> " << e.to << " : " << e.cost << ", ";
    return os;
  }
};

template<class Cost>
struct Graph{
  int V;
  vector<vector<edge<Cost>>> G;
  Graph(){}
  Graph(int V):V(V){
    G.resize(V);
  }
  void add_edge(int a,int b,Cost cost = Cost(0)){
    G[a].push_back(edge<Cost>(a,b,cost));
  }
  void add_edge_undirected(int a, int b, Cost cost,int id){
    G[a].push_back(edge<Cost>(a,b,cost,id));
    G[b].push_back(edge<Cost>(b,a,cost,id));
  }
  size_t size() const { return G.size(); }
  const vector<edge<Cost>>& operator [] (int id) const {
    return G[id];
  }

  // verified https://atcoder.jp/contests/dwacon6th-final-open/submissions/10023433
  vector<Cost> dijkstra(int s){
    assert(0<=s&&s<G.size());
    vector<Cost> dist;
    dist.assign(G.size(),numeric_limits<Cost>::max());
    dist[s] = Cost(0);
    MinHeap<pair<Cost,int>> q;    
    q.push(make_pair(Cost(0),s));
    while(!q.empty()){
      auto a = q.top();
      q.pop();
      int v = a.second;
      if(dist[v]<a.first)continue;
      for(auto e : G[v]){
        if(dist[e.to] > dist[v]+e.cost){
          dist[e.to] = dist[v]+e.cost;
          q.push(make_pair(dist[e.to],e.to));
        }
      }
    }
    return dist;
  }

  // for debug
  friend ostream& operator << (ostream& os, const Graph g) {
    for(int i=0;i<g.size();i++){
      os << g[i];
      if(i+1<g.size())os << endl;
    }
    return os;
  }
};


void solve(){
  int N,M;
  cin >> N >> M;
  vector<int> p(M),y(M);
  auto g = vect(N+1,vect(0,0));
  for(int i=0;i<M;i++){
    cin >> p[i] >> y[i];
    g[p[i]].push_back(y[i]);
  }
  for(int i=0;i<=N;i++)sort(all(g[i]));
  for(int i=0;i<M;i++){
    int k = lower_bound(all(g[p[i]]),y[i])-g[p[i]].begin()+1;
    string S = to_string(p[i]);
    string T = to_string(k);
    while(S.size()<6)S = "0"+S;
    while(T.size()<6)T = "0"+T;
    cout << S << T << endl;
  }
  return ;
}
 
signed main(){
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
