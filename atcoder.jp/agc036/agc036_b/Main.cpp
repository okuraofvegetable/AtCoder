#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define dump(X) cout << #X << ' ' << X << endl
#define pe(X) cout << X << endl
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
ll K;
int A[200100];
vector<int> vec[200100];
ll nxt[200100];
ll cost[200100];
int main(){
	cin >> N >> K;
	vector<int> zip;
	for(int i=0;i<N;i++){
		cin >> A[i];
		zip.pb(A[i]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	for(int i=0;i<N;i++){
		A[i] = lower_bound(all(zip),A[i])-zip.begin();
		vec[A[i]].pb(i);
		vec[A[i]].pb(i+N);
	}
	for(int i=0;i<zip.size();i++)sort(all(vec[i]));
	for(int i=0;i<N;i++){
		nxt[i] = (*upper_bound(all(vec[A[i]]),i))+1;
		cost[i] = nxt[i]-i;
		while(nxt[i]>=N)nxt[i]-=N;
	}
	/*for(int i=0;i<N;i++){
		cout << i << ' ' << nxt[i] << ' ' << cost[i] << endl; 
	}*/
	ll now = 0;
	ll sum = 0;
	do{
		sum += cost[now];
		now = nxt[now];
	}while(now!=0);
	//cout << now << ' ' << sum << endl;
	ll rem =  K*((ll)N)%((ll)sum);
	now = 0;
	while(rem>cost[now]){
		rem -= cost[now];
		now = nxt[now]; 
	}
	vector<int> ans;
	vector<int> cnt(zip.size(),0);
	for(int i=0;i<rem;i++){
		int idx = (now+i)%N;
		if(cnt[A[idx]]>0){
			while(cnt[A[idx]]>0){
				int k = ans.back();
				ans.pop_back();
				cnt[k]--;
			}
		}else{
			cnt[A[idx]]++;
			ans.pb(A[idx]);
		}
	}
	for(int i=0;i<ans.size();i++){
		cout << zip[ans[i]];
		if(i+1<ans.size())cout << ' ';
		else cout << endl;
	}
	return 0;
}