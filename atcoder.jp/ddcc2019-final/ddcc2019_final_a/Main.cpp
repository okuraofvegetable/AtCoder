#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
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
int N;
string S;
int pre[100100];
int main(){
	cin >> N;
	cin >> S;
	double base = 0.0;
	int k=0;
	for(int i=0;i<N;i++){
		pre[i]=k;
		if(S[i]=='-'){
			base+=1.0;
			k=0;
		}else{
			base+=1.0/(double)(k+2.0);
			k++;
		}
	}
	int mx = 0;
	for(int i=0;i<N;i++){
		if(S[i]=='-'){
			mx = max(mx,pre[i]);
		}
	}
	printf("%.12f\n",base-1.0+1.0/(double)(mx+2.0));
	return 0;
}