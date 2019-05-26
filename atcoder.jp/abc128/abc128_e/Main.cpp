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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,Q;
int S[200100],T[200100],X[200100];
int D[200100];
vector<int> zip;
struct event{
	int type; // 0 in 1 out
	int time;
	int val;
	event(){}
	event(int type,int time,int val):type(type),time(time),val(val){}
	bool operator < (const event& a) const{
		return time < a.time;
	}
};
vector<event> es;
int mini[600100];
int main(){
	cin >> N >> Q;
	for(int i=0;i<N;i++){
		cin >> S[i] >> T[i] >> X[i];
		zip.pb(S[i]-X[i]);
		zip.pb(T[i]-X[i]);
	}
	for(int i=0;i<Q;i++){
		cin >> D[i];
		zip.pb(D[i]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	for(int i=0;i<N;i++){
		int in = lower_bound(all(zip),S[i]-X[i])-zip.begin();
		int out = lower_bound(all(zip),T[i]-X[i])-zip.begin();
		es.pb(event(0,in,X[i]));
		es.pb(event(1,out,X[i]));
	}
	sort(all(es));
	int idx = 0;
	multiset<int> ms;
	ms.insert(INF);
	for(int t=0;t<zip.size();t++){
		while(idx<es.size()&&es[idx].time==t){
			if(es[idx].type==0){
				ms.insert(es[idx].val);
			}else{
				multiset<int>::iterator it = ms.find(es[idx].val);
				ms.erase(it);
			}
			idx++;
		}
		mini[t]=*ms.begin();
	}
	for(int i=0;i<Q;i++){
		int tid = lower_bound(all(zip),D[i])-zip.begin();
		if(mini[tid]==INF)cout << -1 << endl;
		else cout << mini[tid] << endl;
	}
	return 0;
}