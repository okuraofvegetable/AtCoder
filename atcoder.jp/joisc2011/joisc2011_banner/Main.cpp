#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,char> P;
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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int H,W;
int col[405][405];
int pre[10];
vector<int> ok[10];
void show(){
	printf("---------------\n");
	for(int i=0;i<3;i++){
		for(int j=i;j<3;j++){
			printf("%d %d %d\n",i,j,pre[3*i+j]);
		}
	}
	printf("---------------\n");
}
int main(){
	scanf("%d %d",&H,&W);
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			scanf("%d",&col[i][j]);
		}
	}
	for(int i=0;i<3;i++){
		for(int j=i;j<3;j++){
			for(int k=0;k<3;k++){
				for(int l=k;l<3;l++){
					if(i!=0&&j!=0&&k!=0&&l!=0)continue;
					if(i!=1&&j!=1&&k!=1&&l!=1)continue;
					if(i!=2&&j!=2&&k!=2&&l!=2)continue;	
					ok[3*i+j].pb(3*k+l);
				}
			}
		}
	}
	ll ans = 0;
	for(int j=0;j<W;j++){
		for(int k=j+1;k<W;k++){
			memset(pre,0,sizeof(pre));
			for(int i=H-1;i>=0;i--){
				int a = col[i][j],b = col[i][k];
				if(a>b)swap(a,b);
				int id = 3*a+b;
				for(int l=0;l<ok[id].size();l++){
					ans += pre[ok[id][l]];
				}
				pre[id]++;
			}
			//show();
		}
	}
	printf("%lld\n",ans);
	return 0;
}