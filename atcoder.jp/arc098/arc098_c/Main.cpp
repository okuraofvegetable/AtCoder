#include <bits/stdc++.h>
using namespace std;
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,K,Q;
int A[2010];
vector<int> v;
int main(){
	scanf("%d %d %d",&N,&K,&Q);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		v.pb(A[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	int ans = INF;
	for(int i=0;i<v.size();i++){
		int cnt = 0;
		int pc = 0;
		priority_queue<int,vector<int>,greater<int> >p,q;
		for(int j=0;j<N;j++){
			if(A[j]<v[i]){
				if(cnt>=K){
					for(int k=0;k<=cnt-K;k++){
						p.push(q.top());
						q.pop();
					}
					pc += cnt-K+1;
				}
				while(!q.empty())q.pop();
				cnt = 0;
			}else{
				q.push(A[j]);
				cnt++;
			}
		}
		if(cnt>=K){
			for(int j=0;j<=cnt-K;j++){
				p.push(q.top());
				q.pop();
			}
			pc += cnt-K+1;
		}
		if(pc<Q)continue;
		for(int j=0;j<Q-1;j++)p.pop();
		//cout << v[i] << ' ' << p.top() << endl; 
		ans = min(ans,p.top()-v[i]);
	}
	cout << ans << endl;
	return 0;
}