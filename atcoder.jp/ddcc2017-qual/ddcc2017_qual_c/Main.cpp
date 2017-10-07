#include<bits/stdc++.h>
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,C;
int L[100100];
int main(){
	cin >> N >> C;
	for(int i=0;i<N;i++)cin >> L[i];
	sort(L,L+N);
	int p = 0;
	int cnt = 0;
	for(int i=N-1;i>=0;i--){
		if(i<=p)break;
		if(L[p]>C-L[i]-1)continue;
		cnt++;
		p++;
	}
	cout << N-cnt << endl;
	return 0;
}