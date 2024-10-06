#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		int n, k;
		cin>>n>>k;
		int first = 1;
		int cum = 0;
		bool odd = false;
		int step = 1;
		while(n/2){
			int curr = (n+odd)/2;
			if(k>cum+curr){
				if(odd) first+=(step+1)/2;
				step = (2*step)+1;
				if(n%2) odd = !odd;
				n-=curr;
			} else {
				int pos = k-cum-1;
				if(!odd){
					first += (step+1)/2;
				}
				first += (step+1)*pos;
				break;
			}
			cum+=curr;
		}
		cout<<first<<endl;
	}
	return 0;
}