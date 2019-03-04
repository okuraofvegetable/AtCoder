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
int N;
vector<int> G[200100];
vector<int> rG[200100];
bool used[200100];
vector<int> vec;
int cmp[200100];
int sz[200100];
int loop_idx;
vector<int> loop;
vector<int> root_val;
void add_edge(int a,int b){
	G[a].pb(b);
	rG[b].pb(a);
}
void dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vec.pb(v);
}
void rdfs(int v,int k){
	used[v]=true;
	cmp[v]=k;
	sz[k]++;
	for(int i=0;i<rG[v].size();i++){
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}
void find_loop(int v,int k){
	used[v]=true;
	loop.pb(v);
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]]&&cmp[G[v][i]]==k)find_loop(G[v][i],k);
	}
}
void print(vector<int> &vect){
	for(int i=0;i<vect.size();i++){
		cout << vect[i];
		if(i+1<vect.size())cout << ' ';
		else cout << endl;
	}
	return;
}
int rec(int v){
	vector<int> s;
	for(int i=0;i<G[v].size();i++){
		if(cmp[G[v][i]]==loop_idx)continue;
		s.pb(rec(G[v][i]));
	}
	sort(all(s));
	s.erase(unique(all(s)),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]!=i)return i;
	}
	return (int)s.size();
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		int p;
		cin >> p;
		p--;
		add_edge(p,i);
	}
	for(int i=0;i<N;i++){
		if(!used[i])dfs(i);
	}
	reverse(all(vec));
	int k=0;
	memset(used,false,sizeof(used));
	int l=-1;
	for(int i=0;i<vec.size();i++){
		if(!used[vec[i]]){
			rdfs(vec[i],k);
			if(sz[k]>1){
				l=vec[i];
				loop_idx=k;
			}
			k++;
		}
	}
	memset(used,false,sizeof(used));
	find_loop(l,loop_idx);
	for(int i=0;i<loop.size();i++){
		root_val.pb(rec(loop[i]));
		if(root_val.back()==-1){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	//print(root_val);
	vector<int> tmp = root_val;
	int M = root_val.size();
	for(int i=M-1;i>0;i--){
		if(tmp[(i+1)%M]==tmp[i])tmp[i]++;
	}
	if(tmp[0]!=tmp[1]){
		cout << "POSSIBLE" << endl;
		return 0;
	}
	tmp = root_val;
	tmp[0]++;
	for(int i=M-1;i>0;i--){
		if(tmp[(i+1)%M]==tmp[i])tmp[i]++;
	}
	if(tmp[1]==tmp[0]-1){
		cout << "POSSIBLE" << endl;
		return 0;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}