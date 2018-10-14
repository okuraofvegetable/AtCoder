#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
int N;
int a[5]={1,3,0,2,4};
int b[1010][1010];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(j%5==a[i%5])b[i][j]=1;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int f = b[i][j];
			for(int d=0;d<4;d++){
				int ni = i+dx[d];
				int nj = j+dy[d];
				if(ni<0||ni>=N||nj<0||nj>=N)continue;
				f |= b[ni][nj];
			}
			if(!f)b[i][j]=1;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%c",(b[i][j]==1)?'X':'.');
		}
		printf("\n");
	}
	return 0;
}