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
int N,C;
int cnt[3100],p[3100];
vector<int> v,vec;
multiset<int> ms;
int m=0;
int main(){
	scanf("%d %d",&N,&C);
	C--;
	for(int i=0;i<2*N;i++){
		int s,a;
		scanf("%d %d",&s,&a);
		if(a==0)v.pb(s);
		else{
			p[--a]+=s;
			cnt[a]++;
		}
	}
	sort(all(v));
	for(int i=0;i<2-cnt[C];i++){
		p[C]+=v.back();
		v.pop_back();
	}
	cnt[C]=2;
	for(int i=0;i<v.size();i++)ms.insert(-v[i]);
	multiset<int>::iterator it;
	for(int i=0;i<N;i++){
		if(cnt[i]==1){
			it = ms.lower_bound(p[i]-p[C]);
			if(it==ms.end()){
				p[i]-=*ms.begin();
				cnt[i]++;
				it = ms.begin();
				ms.erase(it);
			}else{
				p[i]-=*it;
				cnt[i]++;
				ms.erase(it);
				m++;
			}
		}else if(cnt[i]==2){
			if(p[i]<=p[C])m++;
		}
	}
	for(it=ms.begin();it!=ms.end();it++){
		vec.pb(-(*it));
	}
	reverse(all(vec));
	int l = 0,r = sz(vec)-1;
	while(1){
		while(l<r&&vec[l]+vec[r]>p[C])r--;
		if(l>=r)break;
		m++;
		l++;r--;
	}
	printf("%d\n",N-m+1);
	return 0;
}