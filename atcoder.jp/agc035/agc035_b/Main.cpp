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
template<class t,class u>
ostream& operator << (ostream& os,pair<t,u> p){
	return os << p.fi << ',' << p.sec;
}
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
template<class T>
void input(vector<T>& vec,int n){
	vec.resize(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}
}
void fastio(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
}
int N,M;
int A[100100],B[100100];
struct edge{
	int to,id;
	edge(){}
	edge(int to,int id):to(to),id(id){}
};
vector<edge> g[100100];
bool used[100100];
bool tree[100100];
int depth[100100];
int cnt[100100];
void add_edge(int f,int t,int id){
	g[f].pb(edge(t,id));
	g[t].pb(edge(f,id));
	return;
}
void dfs(int v,int p,int pe,int d){
	used[v] = true;
	depth[v] = d;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		if(e.to==p)continue;
		if(!used[e.to]){
			dfs(e.to,v,e.id,d+1);
			tree[e.id]=true;
		}else{
			if(depth[e.to]>depth[v])continue;
			cnt[v]++;
			if(B[e.id]!=e.to)swap(A[e.id],B[e.id]);
		}
	}
	if(cnt[v]%2==1){
		assert(pe!=-1);
		if(A[pe]!=v)swap(A[pe],B[pe]);
	}else{
		cnt[p]++;
		if(A[pe]!=p)swap(A[pe],B[pe]);
	}
	return;
}
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
		add_edge(A[i],B[i],i);
	}
	if(M%2==1){
		cout << -1 << endl;
		return 0;
	}
	dfs(0,-1,-1,0);
	for(int i=0;i<M;i++){
		cout << A[i]+1 << ' ' << B[i]+1 << endl;
	}
	return 0;
}
