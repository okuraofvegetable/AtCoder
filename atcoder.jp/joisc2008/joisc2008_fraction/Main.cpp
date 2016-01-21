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
int m,k;
int id,p=-1,c=-1;
void farey(int ap,int ac,int bp,int bc){
	int cp = ap+bp,cc = ac+bc;
	if(cp>m)return;
	if(id>k)return;
	farey(ap,ac,cp,cc);
	id++;
	if(id==k){
		c = cc;
		p = cp;
		return;
	}
	farey(cp,cc,bp,bc);
}
int main(){
	scanf("%d %d",&m,&k);
	farey(1,0,1,1);
	if(p==-1)printf("-1\n");
	else printf("%d %d\n",c,p);
	return 0;
}