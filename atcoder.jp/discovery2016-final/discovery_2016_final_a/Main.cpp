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
int N;
int id[1010];
int ans[1010];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&id[i]);
		id[i]--;
		if(i==0)ans[id[i]]=100000;
		else if(i==1)ans[id[i]]=50000;
		else if(i==2)ans[id[i]]=30000;
		else if(i==3)ans[id[i]]=20000;
		else if(i==4)ans[id[i]]=10000;
		else ans[id[i]]=0;
	}
	for(int i=0;i<N;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}