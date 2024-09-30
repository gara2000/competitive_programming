#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>
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
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> plli;
 
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

typedef struct cow{
	double x;
	double y;
	double p;
} cow;
int n;
vector<cow> cows(201);
vector<bool> row(201);
vector<vector<bool>> relation(201, row);
vector<int> adj[201];
vector<int> vis(201);
void init(){
	for(int i=0;i<201;i++){
		for(int j=0;j<201;j++){
			relation[i][j] = 0;
		}
		relation[i][i] = 1;
	}
}
bool dfs(int s, int d){
	if(relation[s][d])
		return 1;
	vis[s]=1;
	bool test = false;
	for(auto y: adj[s]){
		if(!vis[y])
			test = test | dfs(y, d);
	}
	return test;
}
double squared(double x, double y){
	return (x-y)*(x-y);
}

double distance(int i, int j){
	return sqrt(squared(cows[i].x, cows[j].x)+squared(cows[i].y, cows[j].y));
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cows[i].x>>cows[i].y>>cows[i].p;
	}
	init();

	// fill the adj list
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(distance(i, j)<=cows[i].p)
				adj[i].pb(j);
		}
	}

	// find which cows each cow message can reach
	int m = 0;
	for(int i=0;i<n;i++){
		int c = 0;
		for(int j=0;j<n;j++){
			for(int x=0;x<n;x++)
				vis[x] = 0;
			c+=dfs(i, j);
		}
		m = max(c, m);
	}
	cout<<m<<endl;
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

