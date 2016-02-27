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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int a[5];
int ABS(int x){
	if(x>=0)return x;
	else return -x;
}
int main(){
	scanf("%d %d %d",&a[0],&a[1],&a[2]);
	int mi = INF,ma = -1;
	for(int i=0;i<8;i++){
		int ret = 0;
		for(int j=0;j<3;j++){
			if((i>>j)&1)ret+=a[j];
			else ret-=a[j];
		}
		if(ret<0)continue;
		mi = min(mi,ret);
		ma = max(ma,ret);
	}
	if(a[0]+a[1]>=a[2]&&a[0]+a[2]>=a[1]&&a[1]+a[2]>=a[0])mi = 0;
	double r = (double)(ma*ma-mi*mi);
	r *= M_PI;
	printf("%.12f\n",r);
	return 0;
}