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
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
vector<int> g[2][2010];
vector<int> euler[2];
int beg[2][2010],end[2][2010];
int root[2];
int k,idx;
void dfs(int v){
	beg[k][v]=idx++;
	for(int i=0;i<g[k][v].size();i++){
		dfs(g[k][v][i]);
	}
	end[k][v]=idx++;
}
int N,M;
int cnt[4010][4010];
void add(int a,int b,int c,int d){
	cnt[a][c]++;
	cnt[a][d]--;
	cnt[b][c]--;
	cnt[b][d]++;
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		int p,q;
		scanf("%d %d",&p,&q);
		p--;q--;
		if(p>=0)g[0][p].pb(i);
		else root[0]=i;
		if(q>=0)g[1][q].pb(i);
		else root[1]=i;
	}
	for(k=0;k<2;k++){
		idx=0;
		dfs(root[k]);
	}
	/*for(int i=0;i<2;i++){
		for(int j=0;j<N;j++){
			printf("%d %d\n",beg[i][j],end[i][j]);
		}
	}*/
	for(int i=0;i<M;i++){
		int r,s;
		scanf("%d %d",&r,&s);
		r--;s--;
		add(beg[0][r],end[0][r],beg[1][s],end[1][s]);
	}
	for(int i=1;i<4010;i++){
		for(int j=0;j<4010;j++){
			cnt[i][j]+=cnt[i-1][j];
		}
	}
	for(int j=1;j<4010;j++){
		for(int i=0;i<4010;i++){
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	for(int i=0;i<N;i++)printf("%d\n",cnt[beg[0][i]][beg[1][i]]);
	return 0;
}