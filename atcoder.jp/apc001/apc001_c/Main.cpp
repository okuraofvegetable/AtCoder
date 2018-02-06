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
int N;
int col[100100];
int Query(int x){
	printf("%d\n",x);
	fflush(stdout);
	string res;
	cin >> res;
	if(res=="Male")return 0;
	else if(res=="Female")return 1;
	else{
		exit(0);
	}
}
int main(){
	scanf("%d",&N);
	int l=0,r=N;
	col[0]=col[N]=Query(0);
	while(1){
		int mid = (l+r)/2;
		col[mid]=Query(mid);
		if((mid-l)%2==1){
			if(col[mid]==col[l])r=mid;
			else l=mid;
		}else{
			if(col[mid]==col[l])l=mid;
			else r=mid;
		}
	}
	return 0;
}