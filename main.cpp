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
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}

int n, m, c;
int money[1001];
int dp[1001][1001][2];
vector<int> adj[1001];
void init(){
	for(int i=0;i<=n; i++){
		for(int j=0;j<=1000; j++)
			for(int k=0;k<2;k++)
				dp[i][j][k] = -1;
	}
}
int max_(int x, int t, bool stop){
	if(x==1&&stop)
		return -c*t*t;
	if(t>=1000)
		return -c*t*t;
	int &d = dp[x][t][stop];
	if(d!=-1) return d;
	d = -int(1e8);
	for(auto y: adj[x]){
		int g = max(max_(y, t+1, 1), max_(y, t+1, 0));
		d = max(d, g+money[y]);
	}
	return d;
}
void solve()
{
	cin>>n>>m>>c;
	for(int i=1; i<=n; i++) 
		cin>>money[i];
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b);
	}
	init();
	cout<<max(max_(1, 0, 0), 0)<<endl;
	return;
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

