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
int dp[100001][21][3];
int a[100001];
int win[3] = {2, 0, 1};
void init(){
	for(int i=0;i<100001;i++)
		for(int j=0;j<=20; j++)
			for(int l=0; l<3; l++)
				dp[i][j][l] = -1;
}
int max_(int i, int r, int g){
	if(i>n) return 0;
	int &d = dp[i][r][g];
	if(d!=-1) return d;
	d = 0;
	for(int x=0;x<3;x++){
		if(g==x)
			d = max(d, max_(i+1, r, x));
		else if(r>0)
			d = max(d, max_(i+1, r-1, x));
	}
	if(win[g]==a[i]) 
		d++; 
	return d;
}
void solve()
{
	cin>>n>>k;
	init();
	for(int i=1;i<=n;i++) {
		char c;
		cin>>c;
		if(c=='H') a[i]=0;
		if(c=='P') a[i]=1;
		if(c=='S') a[i]=2;
	}
	int ans = 0;
	for(int i=0;i<3;i++)
		ans = max(ans, max_(1, k, i));
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

