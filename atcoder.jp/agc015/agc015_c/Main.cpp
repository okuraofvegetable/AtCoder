#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,M,Q;
string s[2010];
struct imos2D{
	vector<vector<int> > f;
	vector<vector<int> > rui;
	imos2D(){}
	imos2D(int H,int W){
		f.resize(H);
		for(int i=0;i<H;i++)f[i].resize(W);
	}
	void set(int x,int y,int v){
		assert(x<f.size()&&y<f[0].size());
		f[x][y]=v;
	}
	void calc(){
		rui = f;
		for(int i=0;i<f.size();i++){
			for(int j=1;j<f[0].size();j++){
				rui[i][j]+=rui[i][j-1];
			}
		}
		for(int i=1;i<f.size();i++){
			for(int j=0;j<f[0].size();j++){
				rui[i][j]+=rui[i-1][j];
			}
		}
	}
	int get(int a,int b,int c,int d){
		if(c<0||d<0)return 0;
		if(c<a||d<b)return 0;
		int res = rui[c][d];
		if(a>0)res -= rui[a-1][d];
		if(b>0)res -= rui[c][b-1];
		if(a>0&&b>0)res += rui[a-1][b-1];
		return res;
	}
};
int main(){
	cin >> N >> M >> Q;
	for(int i=0;i<N;i++){
		cin >> s[i];
	}
	imos2D V(N,M);
	imos2D E(N,M);
	imos2D F(N,M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(s[i][j]=='1'){
				V.set(i,j,1);
				if(i+1<N&&s[i+1][j]=='1')E.set(i,j,1);
				if(j+1<M&&s[i][j+1]=='1')F.set(i,j,1);
			}
		}
	}
	V.calc();
	E.calc();
	F.calc();
	for(int i=0;i<Q;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		a--;b--;c--;d--;
		int ans = V.get(a,b,c,d)-E.get(a,b,c-1,d)-F.get(a,b,c,d-1);
		cout << ans << endl;
	}
	return 0;
}