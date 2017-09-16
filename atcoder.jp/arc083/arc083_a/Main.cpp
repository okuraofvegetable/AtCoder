#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-15
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int A,B,C,D,E,F;
int dp[3010];
int main(){
	scanf("%d %d %d %d %d %d",&A,&B,&C,&D,&E,&F);
	if(C<D)swap(C,D);
	dp[0]=1;
	for(int i=1;i<=3000;i++){
		if(i>=C&&dp[i-C]==1)dp[i]=1;
		if(i>=D&&dp[i-D]==1)dp[i]=1;
	}
	int aw=0,as=0;
	for(int a=0;a<=30;a++){
		for(int b=0;b<=30;b++){
			int w = 100*(a*A+b*B);
			if(w==0)continue;
			if(w>F)continue;
			int mx = (a*A+b*B)*E;
			chmin(mx,F-w);
			int s = mx;
			while(dp[s]==0)s--;
			if((aw+as==0)||as*(s+w)<s*(aw+as)){
				as = s;
				aw = w;
			}
		}
	}
	cout << aw+as << ' ' << as << endl;
	return 0;
}