#include<bits/stdc++.h>
using namespace std;
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
int a[1010];
int b[2][1010];
ll s[2],c[2];
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> a[i];
	for(int i=0;i<2;i++){
		for(int j=i;j<N;j+=2){
			if(a[j]>=0){
				b[i][j]=1;
				s[i]+=a[j];
				c[i]++;
			}
		}
	}
	if(c[0]==c[1]&&c[0]==0){
		int mx = -INF;
		int idx = -1;
		for(int i=0;i<N;i++){
			if(mx<a[i]){
				mx = a[i];
				idx = i;
			}
		}
		idx++;
		printf("%d\n",mx);
		printf("%d\n",N-1);
		for(int i=N;i>idx;i--)printf("%d\n",i);
		for(int i=1;i<idx;i++)printf("1\n");
		return 0;
	}
	int t;
	if(c[0]==0)t=1;
	else if(c[1]==0)t=0;
	else t = (s[0]<s[1])?1:0;
	vector<int> answer;
	int id;
	for(id=N-1;id>=0;id--){
		if(b[t][id]==1)break;
		answer.pb(id);
	}
	int cnt = 0;
	int res = id+1;
	for(;id>=0;id--){
		if(b[t][id]==1){
			cnt = 0;
		}else{
			cnt++;
			if(cnt==3){
				answer.pb(id+1);
				res-=2;
				cnt=1;
			}
		}
	}
	if(cnt==1){
		answer.pb(0);
		res--;
	}
	if(cnt==2){
		answer.pb(0);
		answer.pb(0);
		res-=2;
	}
	if(res%2==1)res--;
	for(int i=res-1;i>=0;i-=2){
		answer.pb(i);
	}
	printf("%lld\n",s[t]);
	printf("%d\n",(int)answer.size());
	for(int i=0;i<answer.size();i++){
		printf("%d\n",answer[i]+1);
	}
	return 0;
}