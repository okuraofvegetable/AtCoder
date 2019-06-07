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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
int A[200100];
multiset<int> s;
vector<int> zip;
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
		s.insert(A[i]);
		zip.pb(A[i]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	int ans = 0;
	for(int i=30;i>0;i--){
		for(int j=0;j<zip.size();j++){
			int a = zip[j];
			int b = (1<<i)-a;
			if(a==b){
				int cnt = s.count(a);
				ans += cnt/2;
				int del = (cnt/2)*2;
				for(int k=0;k<del;k++){
					auto it = s.find(a);
					s.erase(it);
				}
			}else{
				int cnta = s.count(a);
				int cntb = s.count(b);
				ans += min(cnta,cntb);
				for(int k=0;k<min(cnta,cntb);k++){
					auto ita = s.find(a);
					auto itb = s.find(b);
					s.erase(ita);
					s.erase(itb);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}