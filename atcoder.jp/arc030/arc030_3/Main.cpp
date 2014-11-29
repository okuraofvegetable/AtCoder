#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
vector<int> G[305],rG[305];
vector<int> vs;
string c[305];
int V,E,K;
bool used[305];
int cmp[305];
void add_edge(int from,int to)
{
    G[from].pb(to);
    rG[to].pb(from);
    return;
}
void dfs(int s)
{
    used[s]=true;
    for(int i=0;i<G[s].size();i++)
    {
        if(!used[G[s][i]])dfs(G[s][i]);
    }
    vs.pb(s);
}
void rdfs(int s,int k)
{
    used[s]=true;
    cmp[s]=k;
    for(int i=0;i<rG[s].size();i++)
    {
        if(!used[rG[s][i]])rdfs(rG[s][i],k);
    }
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++)
    {
        if(!used[v])dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]])rdfs(vs[i],k++);
    }
    return k;
}
int same(int u,int v)
{
    if(cmp[u]==cmp[v])return 1;
    else return 0;
}
vector<int> g[305];
string str[305];
int num[305];
string dp[305][305];
int main()
{
    cin >> V >> E >> K;
    for(int i=0;i<V;i++)cin >> c[i];
    for(int i=0;i<E;i++)
    {
        int s,t;
        cin >> s >> t;
		s--;t--;
        add_edge(s,t);
    }
    int N = scc();
	for(int i=0;i<V;i++)
	{
		str[cmp[i]]+=c[i];
		num[cmp[i]]++;
	}
	for(int i=0;i<N;i++)sort(str[i].begin(),str[i].end());
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			if(cmp[i]==cmp[G[i][j]])continue;
			g[cmp[i]].pb(cmp[G[i][j]]);
		}
	}
	for(int i=0;i<N;i++)
	{
		sort(all(g[i]));
		g[i].erase(unique(all(g[i])),g[i].end());
	}
	/*for(int i=0;i<N;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}*/
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<=K;j++)
		{
			dp[i][j]="}}}";
		}
		dp[i][0]="";
	}
	for(int i=0;i<N;i++)for(int j=1;j<=str[i].size();j++)dp[i][j]=str[i].substr(0,j);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=K;j++)
		{
			if(dp[i][j]=="}}}")continue;
			for(int k=0;k<g[i].size();k++)
			{
				int to = g[i][k];
				for(int l=0;l<=str[to].size();l++)
				{
					if(j+l>K)continue;
					dp[to][j+l]=min(dp[to][j+l],dp[i][j]+str[to].substr(0,l));
				}
			}
		}
	}
	string ans = "}}}";
	for(int i=0;i<N;i++)ans = min(ans,dp[i][K]);
	if(ans == "}}}")cout << -1 << endl;
	else cout << ans << endl;
    return 0;
}
