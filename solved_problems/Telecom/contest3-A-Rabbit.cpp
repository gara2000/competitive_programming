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

string grid[501];
map<ii, int> vis;
// down, up, right, left
char dir[] = {'D', 'U', 'R', 'L'};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int c, r;
pair<ii,ii> get_positions(){
	ii s, d;
	for(int i=0; i<r; i++){
		for(int j=0;j<c;j++){
			if(grid[i][j]=='R')
				s = make_pair(i, j);
			if(grid[i][j]=='D')
				d = make_pair(i, j);
		}
	}
	return make_pair(s, d);
}
string dfs(ii s){
	vis[s]++;
	if(grid[s.fi][s.se]=='D')
		return "";
	for(int i=0;i<4;i++){
		int x = s.se+dx[i];
		int y = s.fi+dy[i];
		if(vis[make_pair(y, x)])
			continue;
		if(x>=0&&x<c&&y>=0&&y<r&&grid[y][x]!='#'){
			string curr = dfs(make_pair(y, x));
			if(curr!="X")
			{
				curr+=dir[i];
				return curr;
			}
		}
	}
	return "X";
}

void solve()
{
	cin>>c>>r;

	for(int i=0;i<r;i++){
		cin>>grid[i];
	}

	auto [s, d] = get_positions();
	string ans = dfs(s);
	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;
	// cout<<s.fi<<" "<<s.se<<" "<<d.fi<<" "<<d.se<<endl;
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

