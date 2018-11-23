#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
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
int N,Q;
int x[100100];
int nxt[18][100100];
int L;
int solve(int a,int b){
	if(a>b)swap(a,b);
	int res = 0;
	for(int i=17;i>=0;i--){
		if(nxt[i][a]<b){
			res |= (1<<i);
			a = nxt[i][a];
		}
		if(a==b)break;
	}
	return res+1;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> x[i];
	cin >> L;
	for(int i=0;i<N;i++){
		nxt[0][i]=upper_bound(x,x+N,x[i]+L)-x-1;
	}
	for(int i=0;i<17;i++){
		for(int j=0;j<N;j++){
			nxt[i+1][j]=nxt[i][nxt[i][j]];
		}
		//for(int j=0;j<N;j++)printf("%d ",nxt[i][j]);
		//printf("\n");
	}
	cin >> Q;
	for(int i=0;i<Q;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		cout << solve(a,b) << endl;
	}
	return 0;
}
