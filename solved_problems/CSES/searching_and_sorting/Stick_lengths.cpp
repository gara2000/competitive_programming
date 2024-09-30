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
	vector<ll> a(n);
	ll sum = 0;
	loop(n) {
		cin>>a[i];
		sum+=a[i];
	}
	sort(all(a));
	ll ans = ll(1e15);
	ll r = 0;
	for(int i=0;i<n;i++){
		ll curr = r+sum-ll(n-i)*a[i];
		ans = min(ans, curr);
		sum-=a[i];
		if(i<n-1)
			r+=(a[i+1]-a[i])*(i+1);
	}
	cout<<ans<<endl;

	return 0;
}