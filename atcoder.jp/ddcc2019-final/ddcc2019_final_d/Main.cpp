#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
#define MAX_N 1000100
struct BIT{
	unsigned int bit[MAX_N+1];
	void add(int i,int x){
		i++;
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	unsigned int sum(int i){
		i++;
		unsigned int res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
	unsigned int sum(int l,int r){// [l,r]
		if(l==0)return sum(r);
		else return sum(r)-sum(l-1);
	}
};
BIT D,DI,DIS,DISC,DISCO;
BIT I,IS,ISC,ISCO;
BIT S,SC,SCO;
BIT C,CO;
BIT O;
unsigned int cO(int L,int R){
	return O.sum(L,R);
}
unsigned int cCO(int L,int R){
	unsigned int ret = CO.sum(L,R);
	ret -= C.sum(L-1)*cO(L,R);
	return ret;
}
unsigned int cSCO(int L,int R){
	unsigned int ret = SCO.sum(L,R);
	ret -= S.sum(L-1)*cCO(L,R);
	ret -= SC.sum(L-1)*cO(L,R);
	return ret;
}
unsigned int cISCO(int L,int R){
	unsigned int ret = ISCO.sum(L,R);
	ret -= I.sum(L-1)*cSCO(L,R);
	ret -= IS.sum(L-1)*cCO(L,R);
	ret -= ISC.sum(L-1)*cO(L,R);
	return ret;
}
unsigned int cDISCO(int L,int R){
	unsigned int ret = DISCO.sum(L,R);
	ret -= D.sum(L-1)*cISCO(L,R);
	ret -= DI.sum(L-1)*cSCO(L,R);
	ret -= DIS.sum(L-1)*cCO(L,R);
	ret -= DISC.sum(L-1)*cO(L,R);
	return ret;
}
string s;
int Q;
int main(){
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='D'){
			D.add(i,1);
		}else if(s[i]=='I'){
			I.add(i,1);
			DI.add(i,D.sum(i-1));
		}else if(s[i]=='S'){
			S.add(i,1);
			IS.add(i,I.sum(i-1));
			DIS.add(i,DI.sum(i-1));
		}else if(s[i]=='C'){
			C.add(i,1);
			SC.add(i,S.sum(i-1));
			ISC.add(i,IS.sum(i-1));
			DISC.add(i,DIS.sum(i-1));
		}else{
			O.add(i,1);
			CO.add(i,C.sum(i-1));
			SCO.add(i,SC.sum(i-1));
			ISCO.add(i,ISC.sum(i-1));
			DISCO.add(i,DISC.sum(i-1));
		}
	}
	cin >> Q;
	for(int i=0;i<Q;i++){
		int L,R;
		cin >> L >> R;
		L--;R--;
		cout << cDISCO(L,R) << endl;
	}
	return 0;
}