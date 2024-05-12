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

int n, k;
vector<int> col[501];
vector<int> row[501];
map<ii, int> m;
void solve()
{
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int x, y;
		cin>>x>>y;
		col[y].pb(x);
		row[x].pb(y);
		m[make_pair(x, 0)]++;
		m[make_pair(y, 1)]++;
	}
	int c = 0;
	int ans = 0;
	while(c<k){
		ans++;
		set<pair<int, pair<int,int>>> s;
		for(auto p: m){
			s.insert(make_pair(-p.se, make_pair(p.fi.fi, p.fi.se)));
		}
		auto [num, p] = *s.begin();
		num = -num;
		c+=num;
		// if it is a row
		if(p.se==0){
			for(auto y: row[p.fi]) m[make_pair(y, 1)]--;
		}
		// if it is a column
		if(p.se==1){
			for(auto x: col[p.fi]) m[make_pair(x, 0)]--;
		}
		m[p] = 0;
	}
	cout<<ans<<endl;
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

