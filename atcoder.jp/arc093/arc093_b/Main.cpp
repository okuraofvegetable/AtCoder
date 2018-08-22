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
#define LLINF 1000000000000000
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
int f[100][100];
int A,B;
char str[3]=".#";
int main(){
	cin >> A >> B;
	for(int i=0;i<47;i++){
		for(int j=47;j<94;j++){
			f[i][j]=1;
		}
	}
	for(int i=0;i<B-1;i++){
		int a = i/23;
		int b = i%23;
		f[2*a+1][2*b+1]=1;
	}
	for(int i=0;i<A-1;i++){
		int a = i/23;
		int b = i%23;
		f[2*a+1][2*b+1+47]=0;
	}
	cout << 47 << ' ' << 94 << endl;
	for(int i=0;i<47;i++){
		for(int j=0;j<94;j++){
			printf("%c",str[f[i][j]]);
		}
		printf("\n");
	}
	return 0;
}