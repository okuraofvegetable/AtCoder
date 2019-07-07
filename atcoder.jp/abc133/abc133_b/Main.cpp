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
#define dump(X) cout << #X << ' ' << X << endl
#define pe(X) cout << X << endl
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,D;
int x[13][13];
bool check(int a,int b){
	int sum = 0;
	for(int i=0;i<D;i++){
		sum += sq(x[a][i]-x[b][i]);
	}
	int k = (int)sqrt(sum);
	if(k*k==sum)return true;
	if(sq(k-1)==sum)return true;
	if(sq(k+1)==sum)return true;
	return false;
}
int main(){
	cin >> N >> D;
	for(int i=0;i<N;i++){
		for(int j=0;j<D;j++){
			cin >> x[i][j];
		}
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(check(i,j))ans++;
		}
	}
	cout << ans << endl;
	return 0;
}