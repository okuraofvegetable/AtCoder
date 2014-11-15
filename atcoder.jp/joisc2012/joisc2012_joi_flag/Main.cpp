#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 2000000000
#define pb push_back
int N,K;
int X[1010],Y[1010];
char C[1010];
char JOI[] = "JOI";
int dfs(int x,int y,int r){
	if(r==1)return 0;
	int cnt=0;
	int a[4][3];
	memset(a,0,sizeof(a));
	for(int i=0;i<N;i++){
		if(x<=X[i]&&X[i]<x+r&&y<=Y[i]&&Y[i]<y+r)cnt++;
		if(x<=X[i]&&X[i]<x+r/2&&y<=Y[i]&&Y[i]<y+r/2)a[0][C[i]]++;
		if(x<=X[i]&&X[i]<x+r/2&&y+r/2<=Y[i]&&Y[i]<y+r)a[1][C[i]]++;
		if(x+r/2<=X[i]&&X[i]<x+r&&y<=Y[i]&&Y[i]<y+r/2)a[2][C[i]]++;
		if(x+r/2<=X[i]&&X[i]<x+r&&y+r/2<=Y[i]&&Y[i]<y+r)a[3][C[i]]++;
	}
	if(cnt==0)return 0;
	int b[4];
	b[0]=dfs(x,y,r/2);
	b[1]=dfs(x,y+r/2,r/2);
	b[2]=dfs(x+r/2,y,r/2);
	b[3]=dfs(x+r/2,y+r/2,r/2);
	vector<int> p;
	p.pb(0);p.pb(1);p.pb(2);p.pb(3);
	sort(p.begin(),p.end());
	int ans = INF;
	do{
		int res = 0;
		for(int i=0;i<4;i++){
			if(p[i]==3)res += b[i];
			else{
				for(int j=0;j<3;j++){
					if(j==p[i])continue;
					res += a[i][j];
				}
			}
		}
		ans = min(ans,res);
	}while(next_permutation(p.begin(),p.end()));
	return ans;
}
int main(){
	cin >> K >> N;
	for(int i=0;i<N;i++){
		char c;
		cin >> X[i] >> Y[i] >> c;
		for(int j=0;j<3;j++){
			if(JOI[j]==c){
				C[i]=j;
				break;
			}
		}
	}
	cout << dfs(1,1,1<<K) << endl;
	return 0;
}
