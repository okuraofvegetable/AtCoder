#include <bits/stdc++.h>
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
int main(){
	int N;
	cin >> N;
	vi p(N);
	for(int i=0;i<N;i++){
		cin >> p[i];
	}
	for(int i=0;i<N;i++){
		if(p[i]!=i+1){
			goto n;
		}
	}
	cout << "YES" << endl;
	return 0;
	n:;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			swap(p[i],p[j]);
			for(int k=0;k<N;k++){
				if(p[k]!=k+1){
					goto end;
				}
			}
			cout << "YES" << endl;
			return 0;
			end:;
			swap(p[i],p[j]);
		}
	}
	cout << "NO" << endl;
	return 0;
}
