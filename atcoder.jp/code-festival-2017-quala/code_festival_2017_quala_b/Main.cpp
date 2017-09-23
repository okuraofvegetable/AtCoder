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
int main(){
	int N,M,K;
	cin >> N >> M >> K;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			//cout << i*M+j*N-i*j*2 << ' ';
			if(i*M+j*N-i*j*2==K){
				printf("Yes\n");
				return 0;
			}
		}
		//cout << endl;
	}
	printf("No\n");
	return 0;
}