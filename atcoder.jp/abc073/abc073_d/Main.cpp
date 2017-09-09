#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
#define MAX_N 200000
int N,M,R;
vector<int> r;
int d[205][205];
int main(){
	scanf("%d %d %d",&N,&M,&R);
	r.resize(R);
	for(int i=0;i<R;i++){
		cin >> r[i];
		r[i]--;
	}
	sort(all(r));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)d[i][j]=INF;
	}
	for(int i=0;i<N;i++)d[i][i]=0;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		d[a][b]=d[b][a]=c;
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	int ans = INF;
	do{
		int ret = 0;
		for(int i=1;i<R;i++){
			ret+=d[r[i]][r[i-1]];
		}
		chmin(ans,ret);
	}while(next_permutation(r.begin(),r.end()));
	cout << ans << endl;
	return 0;
}