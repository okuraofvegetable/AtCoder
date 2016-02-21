#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
struct star{
	int X,Y,C;
	star(){}
	star(int X,int Y,int C):X(X),Y(Y),C(C){}
};
star st[3010];
P vec[3010];
double argu[6010];
ll cnt[3],cnt2[3];
star center;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&st[i].X,&st[i].Y,&st[i].C);
	}
	int M = N-1;
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		center = st[i];
		int idx = 0;
		for(int j=0;j<N;j++){
			if(i!=j)vec[idx++]=P(atan2(st[j].Y-center.Y,st[j].X-center.X),st[j].C);
		}
		sort(vec,vec+M);
		for(int j=0;j<M;j++){
			argu[j]=vec[j].fi;
			argu[j+M]=argu[j]+2.0*M_PI;
		}
		int border = lower_bound(argu,argu+M,argu[0]+M_PI)-argu;
		for(int j=0;j<3;j++)cnt[j]=0,cnt2[j]=0;
		for(int j=0;j<border;j++)cnt[vec[j].sec]++;
		for(int j=border;j<M;j++)cnt2[vec[j].sec]++;
		for(int j=0;j<M;j++){
			cnt[vec[j].sec]--;
			while(border<2*M&&argu[border]<=argu[j]+M_PI){
				cnt2[vec[border%M].sec]--;
				cnt[vec[border%M].sec]++;
				border++;
			}
			ll pro = 1ll;
			for(int k=0;k<3;k++)if(k!=center.C)pro*=cnt[k];
			for(int k=0;k<3;k++)if(k!=vec[j].sec)pro*=cnt2[k];
			ans += pro;
			cnt2[vec[j].sec]++;
		}
	}
	printf("%lld\n",ans/2ll);
	return 0;
}