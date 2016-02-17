#include <bits/stdc++.h>
#include "ramen.h"
using namespace std;
typedef pair<int,int> P;
typedef pair<P,P> F;
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
void Ramen(int N){
	vector<int> mi,mx;
	for(int i=0;i<N/2;i++){
		if(Compare(i*2,i*2+1)==1){
			mx.pb(i*2);
			mi.pb(i*2+1);
		}else{
			mi.pb(i*2);
			mx.pb(i*2+1);
		}
	}
	if(N%2==1){
		mx.pb(N-1);
		mi.pb(N-1);
	}
	vector<int> tmp;
	while(sz(mi)>1){
		for(int i=0;i<sz(mi)/2;i++){
			if(Compare(mi[i*2],mi[i*2+1])==1)tmp.pb(mi[i*2+1]);
			else tmp.pb(mi[i*2]);
		}
		if(sz(mi)%2==1)tmp.pb(mi[sz(mi)-1]);
		mi.clear();
		mi = tmp;
		tmp.clear();
	}
	while(sz(mx)>1){
		for(int i=0;i<sz(mx)/2;i++){
			if(Compare(mx[i*2],mx[i*2+1])==1)tmp.pb(mx[i*2]);
			else tmp.pb(mx[i*2+1]);
		}
		if(sz(mx)%2==1)tmp.pb(mx[sz(mx)-1]);
		mx.clear();
		mx = tmp;
		tmp.clear();
	}
	Answer(mi[0],mx[0]);
}