#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int N,res;
int pred[105];
int ans[105];
vector<int> rem;
vector<int> idx;
void print(){
	for(int i=0;i<N;i++)printf("%d\n",pred[i]);
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)pred[i]=1;
	int f = 1;
	for(int i=2;i<=N;i++){
		pred[0]=i;
		print();
		fflush(stdout);
		scanf("%d",&res);
		if(res==0){
			f=1;
			break;
		}else if(res==2){
			f = i;
			break;
		}
	}
	//printf("f:%d\n",f);
	ans[0]=f;
	for(int i=1;i<=N;i++)if(i!=f)rem.pb(i);
	for(int i=1;i<N;i++)idx.pb(i);
	for(int i=0;i<rem.size();i++){
		int s = rem[i];
		int l = 0,r = sz(idx);
		while(r-l>1){
			int mid = (l+r)/2;
			for(int j=0;j<idx[mid];j++)pred[j]=f;
			for(int j=idx[mid];j<N;j++)pred[j]=s;
			print();
			fflush(stdout);
			scanf("%d",&res);
			assert(res==1||res==2);
			if(res==1)r = mid;
			else l = mid;
		}
		/*for(int i=0;i<idx.size();i++)printf("%d ",idx[i]);
		printf("\n");
		printf("l %d s %d\n",l,s);*/
		ans[idx[l]]=s;
		vector<int>::iterator it = lower_bound(all(idx),idx[l]);
		idx.erase(it);
	}
	for(int i=0;i<N;i++)printf("%d\n",ans[i]);
	fflush(stdout);
	scanf("%d",&res);
	assert(res==N);
	return 0;
}