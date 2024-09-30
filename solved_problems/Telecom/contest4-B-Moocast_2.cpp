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

int n;
vector<pair<double,double>> cows(1001);
vector<bool> vis(1001);
vector<bool> row(1001);
vector<vector<bool>> relation(1001, row);
vector<int> adj[1001];
double squared(double x, double y){
	return (x-y)*(x-y);
}

double distance(int i, int j){
	return sqrt(squared(cows[i].fi, cows[j].fi)+squared(cows[i].se, cows[j].se));
}
void init(double d){
	for(int i=0;i<n;i++){
		adj[i].clear();
		vis[i] = 0;
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(distance(i, j)<=d)
				adj[i].pb(j);
		}
	}
}
int dfs(int s){
	vis[s]=1;
	int c=1;
	bool test = false;
	for(auto y: adj[s]){
		if(!vis[y])
			c += dfs(y);
	}
	return c;
}
bool f(ll x){
	double d = sqrt(double(x));
	init(d);
	return (dfs(0)==n);
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cows[i].fi>>cows[i].se;
	}
	ll r = ll(1e10), l = 0;
	while(l<r){
		ll x = (l+r)/2;
		if(f(x))
			r = x;
		else
			l = x+1;
	}
	cout<<l<<endl;
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

