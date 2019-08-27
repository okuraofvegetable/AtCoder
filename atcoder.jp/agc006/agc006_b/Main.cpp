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
int N,x,M;
vector<int> ans;
void solve1(int y){
	ans[N-1] = y+1;
	ans[N] = y;
	ans[N+1] = y-1;
	ans[N+2] = y+2;
	int idx = 1;
	for(int i=1;i<=M;i++){
		if(i>=y-1&&i<=y+2)continue;
		while(idx<=M&&ans[idx]!=0)idx++;
		ans[idx] = i;
	}
	return;
}

void solve2(int y){
	ans[N-1] = y-1;
	ans[N] = y;
	ans[N+1] = y+1;
	ans[N+2] = y-2;
	int idx = 1;
	for(int i=1;i<=M;i++){
		if(i>=y-2&&i<=y+1)continue;
		while(idx<=M&&ans[idx]!=0)idx++;
		ans[idx] = i;
	}
	return;
}

int main(){
	cin >> N >> x;
	M = 2*N-1;
	ans.resize(M+1,0);
	if(x==1||x==M){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if(N==2){
		cout << "1\n2\n3" << endl;
		return 0;
	}
	if(x==2)solve1(x);
	else solve2(x);
	for(int i=1;i<=M;i++){
		cout << ans[i] << endl;
	}
	return 0;
}

