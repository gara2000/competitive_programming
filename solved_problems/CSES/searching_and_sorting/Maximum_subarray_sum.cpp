#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
using namespace std;

typedef complex<double> pt;
typedef pair<int,int> ii;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(17);

	/// SAVE THE FILE !!!///
	int n;
	cin>>n;
	ll sum = 0;
	ll ans = 0;
	ll min = -int(1e9);
	bool test = true;
	loop(n){
		ll x;
		cin>>x;
		if(x>=0)
			test = false;
		else
			min = max(x, min);
		sum += x;
		sum = max(sum, 0ll);
		ans = max(ans, sum);
		
	}
	if(test)
		cout<<min<<endl;
	else 
		cout<<ans<<endl;
	
	return 0;
}