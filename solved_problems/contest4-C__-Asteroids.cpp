 // Include statements
	#include <bits/stdc++.h>
	#include <iomanip>
	#include <cmath>

 // Definitions
	// #define endl '\n' 
	#define mod 1000000007ll
	#define pb push_back
	#define all(v) v.begin(),v.end()
	#define M_PI           3.14159265358979323846
	#define prime6 347717
	#define loop(start, end, step) for(int i=start; i<end; i+=step)
	#define fi first
	#define se second

using namespace std;
 // Type definitions
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int,int> ii;
	typedef pair<ll,ll> pll;
	typedef pair<ll,int> plli;

 // Constants
	const ll inf=ll(1e14)+5;
	const ll mo=998244353;
	//const int p=31;
 
template<typename T>
void repr(vector<T> a, int N)
{
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<typename T>
void represent(T a){
	for(auto x: a)
	cout<<x<<" ";
	cout<<endl;
}
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}

int capa[1002][1002], flow[1002][1002];
bool vis[1002];
vector<int> adj[1002];
int source=0, target=1001;

int dfs(int x, int max_flow){
	if(vis[x]) return 0;
	if(x==target){
		return max_flow;
	} 
	vis[x] = true;
	for(int n:adj[x]){
		if(flow[x][n] < capa[x][n]){
			const int sub_flow = dfs(n, min(max_flow, capa[x][n]-flow[x][n]));
			if(sub_flow>0){
				flow[x][n]+=sub_flow;
				flow[n][x]-=sub_flow;
				return sub_flow;
			}
		}
	}
	return 0;
}

void solve()
{
	int n, k;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int r, c;
		cin>>r>>c;
		c+=500;
		adj[r].pb(c);
		adj[c].pb(r);
		capa[r][c]=1;
		capa[c][r]=1;
		flow[r][c]=0;
		flow[c][r]=1;
	}
	for(int i=1;i<=n;i++)
	{
		adj[source].pb(i);
		adj[i].pb(source);
		capa[source][i] = 1;
		capa[i][source] = 1;
		flow[source][i] = 0;
		flow[i][source] = 1;

		int c = i+500;
		adj[target].pb(c);
		adj[c].pb(target);
		capa[target][c] = 1;
		capa[c][target] = 1;
		flow[target][c] = 1;
		flow[c][target] = 0;
	}

	int total_flow=0, cur_flow = 1;
	while(cur_flow>0){
		fill(vis, vis+1002, false);
		cur_flow = dfs(source, 10000);
		total_flow +=cur_flow;
	}

	cout<<total_flow<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
	// freopen("polygon.in", "r", stdi n);
 
    cout<<setprecision(20);
 
	int t=1;
	bool test = false;
	if(test)
		cin>>t;
	while(t--)
		solve();
 
	return 0;
}


