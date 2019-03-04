#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
const int SIZE = 1<<18;
struct segtree{
	int seg[SIZE*2];
	void update(int k,int x){
		k += SIZE-1;
		seg[k]=x;
		while(k>0){
			k = (k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return INF;
		else if(a<=l&&r<=b)return seg[k];
		else return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	}
	int query(int a,int b){
		return query(a,b,0,0,SIZE);
	}
}seg[2];
int N;
int p[200100];
int pos[200100];
vector<int> child[200100];
int idx=0;
ll M = 1000000ll;
ll val[200100];
int dfs(int l,int r){
	if(r<=l)return -1;
	int id = idx++;
	int S = seg[l%2].query(l,r);
	int T = seg[(l+1)%2].query(pos[S],r);
	val[id]=S*M+T;
	child[id].pb(dfs(l,pos[S]));
	child[id].pb(dfs(pos[S]+1,pos[T]));
	child[id].pb(dfs(pos[T]+1,r));
	return id;
}
void print(vector<int> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> p[i];
		pos[p[i]]=i;
	}
	for(int i=0;i<SIZE;i++){
		seg[0].update(i,INF);
		seg[1].update(i,INF);
	}
	for(int i=0;i<N;i++){
		seg[i%2].update(i,p[i]);
	}
	dfs(0,N);
	/*for(int i=0;i<idx;i++){
		cout << val[i] << endl;
	}*/
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(val[0],0));
	vector<int> ans;
	while(!q.empty()){
		P a = q.top();
		q.pop();
		int v = a.sec;
		ans.pb((a.fi)/M);
		ans.pb((a.fi)%M);
		for(int i=0;i<child[v].size();i++){
			int u = child[v][i];
			if(u==-1)continue;
			q.push(P(val[u],u));
		}
	}
	print(ans);
	return 0;
}