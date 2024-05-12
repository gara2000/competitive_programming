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
ll dp[501][501];
ll a[501];
ll pref_sum[501];
void init(){
	for(int i=0;i<501;i++)
		for(int j=0;j<501; j++)
			dp[i][j] = -1;
}
ll min_(int l, int r){
	if(l==r) return 0;
	if(dp[l][r]!=-1)
		return dp[l][r];
	dp[l][r] = ll(1e18);
	for(int i=l;i<r;i++){
		ll curr = min_(l, i)+pref_sum[i]-pref_sum[l-1]+min_(i+1, r)+pref_sum[r]-pref_sum[i];
		dp[l][r] = min(dp[l][r], curr);	
	}	
	return dp[l][r];
}
void solve()
{
	cin>>n;
	init();
	pref_sum[0] = 0;	
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		pref_sum[i] = pref_sum[i-1] + a[i];
	}
	cout<<min_(1, n)<<endl;
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

