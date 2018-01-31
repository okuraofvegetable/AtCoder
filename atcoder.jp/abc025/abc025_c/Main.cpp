#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
typedef long long ll;
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
int b[3][3];
int c[3][3];
P dfs(int d,vector<int> v){
	if(d==9){
		P q = P(0,0);
		for(int i=0;i<2;i++){
			for(int j=0;j<3;j++){
				if(v[i*3+j]==v[(i+1)*3+j])q.fi+=b[i][j];
				else q.sec+=b[i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<2;j++){
				if(v[i*3+j]==v[i*3+j+1])q.fi+=c[i][j];
				else q.sec+=c[i][j];
			}
		}
		return q;
	}
	P p = P(-INF,-INF);
	for(int i=0;i<9;i++){
		if(v[i]==-1){
			v[i]=(d%2==0);
			P a;
			a = dfs(d+1,v);
			v[i]=-1;
			//if(d==8)cout << a.fi << ' ' << a.sec << endl;
			if(d%2==0){
				if(p.fi<a.fi)p=a;
			}else{
				if(p.sec<a.sec)p=a;
			}
		}
	}
	return p;
}
int main(){
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cin >> b[i][j];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			cin >> c[i][j];
		}
	}
	vector<int> s(9,-1);
	/*s[0]=1;
	s[1]=0;
	s[2]=1;
	s[3]=0;
	s[4]=0;
	s[5]=1;
	s[6]=0;
	s[7]=1;*/
	P ans = dfs(0,s);
	cout << ans.fi << endl;
	cout << ans.sec << endl;
	return 0;
}