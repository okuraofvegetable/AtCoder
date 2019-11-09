#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T,vector<T>,greater<T> >;
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
ll d[600100];
int V; // kanarazu dainyuu !
struct edge{
	int to;
  ll cost;
	edge(int to,ll cost):to(to),cost(cost){}
};
vector<edge> g[600100];
int mu[600000],md[600000];
void dijkstra(int s){
    fill(d,d+V+1,LLINF);
    priority_queue<P,vector<P>,greater<P> > q;
    d[s]=0;
    q.push(P(0ll,s));
    while(!q.empty()){
        P a=q.top();
        q.pop();
        if(d[a.sec]<a.fi)continue;
        for(int i=0;i<g[a.sec].size();i++){
            edge e=g[a.sec][i];
            if(d[e.to]>d[a.sec]+e.cost){
                d[e.to]=d[a.sec]+e.cost;
                q.push(P(d[e.to],e.to));
            }
        }
    }
    return;
}
void add_edge(int s,int t,ll c){
  //cout << s << ' ' << t << ' ' << c << endl;
  g[s].pb(edge(t,c));
}
int A;
int N,M;
int n;
int L[100100],R[100100],C[100100];

int construct(int l,int r,int k,bool flag){
  if(l+1==r){
    if(flag)mu[k]=l;
    else md[k]=l;
    return l;
  }
  int mid = (l+r)/2;
  int to1 = construct(l,mid,k*2+1,flag);
  int to2 = construct(mid,r,k*2+2,flag);
  int self = A;
  if(flag)mu[k]=A++;
  else md[k]=A++;
  if(flag){
    add_edge(self,to1,0ll);
    add_edge(self,to2,0ll);
  }else{
    add_edge(to1,self,0ll);
    add_edge(to2,self,0ll);
  }
  return self;
}

void range_to_vec(int a,int b,int l,int r,int k,bool flag,vector<int>& v){
  if(r<=a||b<=l)return;
  if(a<=l&&r<=b){
    if(flag)v.pb(mu[k]);
    else v.pb(md[k]);
  }else{
    int mid = (l+r)/2;
    range_to_vec(a,b,l,mid,k*2+1,flag,v);
    range_to_vec(a,b,mid,r,k*2+2,flag,v);
  }
}

int main(){
  fastio();
  cin >> N >> M;
  n = 1;
  A = N;
  while(n<N)n*=2; 
  construct(0,n,0,true);
  construct(0,n,0,false);
  for(int i=0;i<M;i++){
    cin >> L[i] >> R[i] >> C[i];
    L[i]--;
    vector<int> s,t;
    range_to_vec(L[i],R[i],0,n,0,true,s);
    range_to_vec(L[i],R[i],0,n,0,false,t);
    for(int j=0;j<t.size();j++){
      add_edge(t[j],A,0);
    }
    for(int j=0;j<s.size();j++){
      add_edge(A+1,s[j],0);
    }
    add_edge(A,A+1,C[i]);
    A += 2;
  }
  V = A;
  dijkstra(0);
  if(d[N-1]==LLINF)cout << -1 << endl;
  else cout << d[N-1] << endl;
  return 0;
}
