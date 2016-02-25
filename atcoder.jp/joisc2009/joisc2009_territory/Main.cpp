#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
map<P,int> m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char str[]="NESW";
int main(){
	P pos = P(0,0);
	while(1){
		char c;
		scanf(" %c",&c);
		if(c=='Q')break;
		//printf("%d %d\n",pos.fi,pos.sec);
		for(int i=0;i<4;i++){
			if(str[i]==c){
				m[pos]|=(1<<i);
				pos.fi += dx[i];
				pos.sec += dy[i];
				m[pos]|=(1<<((i+2)%4));
			}
		}
	}
	P cur = m.begin()->fi;
	P init = cur;
	int dir = 0,cnt = 0;
	int ans = 0;
	while(1){
		//printf("%d %d %d\n",cur.fi,cur.sec,dir);
		int nd = (dir+3)%4;
		for(int i=0;i<4;i++){
			if(cur==init&&nd==0&&cnt>0)goto end;
			if((m[cur]>>nd)&1){
				if(nd==1)ans+=cur.sec;
				if(nd==3)ans-=cur.sec;
				cur.fi += dx[nd];
				cur.sec += dy[nd];
				break;
			}
			nd = (nd+1)%4;
		}
		dir = nd;
		cnt++;
	}
	end:;
	printf("%d\n",ans);
	return 0;
}