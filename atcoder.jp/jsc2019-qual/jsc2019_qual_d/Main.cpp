#include <bits/stdc++.h>
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
int N;
int a[505][505];
void f(vector<int> vs,int d){
	vector<int> p[2];
	for(int i=0;i<vs.size();i++){
		p[i%2].pb(vs[i]);
	}
	for(int i=0;i<p[0].size();i++){
		for(int j=0;j<p[1].size();j++){
			int u = p[0][i];
			int v = p[1][j];
			if(u>v)swap(u,v);
			a[u][v] = d;
		}
	}
	if(p[0].size()>1)f(p[0],d+1);
	if(p[1].size()>1)f(p[1],d+1);
	return;
}
int main(){
	cin >> N;
	vector<int> vec;
	for(int i=0;i<N;i++)vec.pb(i);
	f(vec,1);
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			cout << a[i][j];
			if(j+1<N)cout << ' ';
			else cout << endl;
		}
	}
	return 0;
}

