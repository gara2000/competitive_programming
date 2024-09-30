// WASN'T SOLVED

#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
using namespace std;

typedef complex<double> pt;

double cross(pt z1, pt z2){
    return (conj(z1)*z2).imag();
}
int cross_sign(pt a, pt b){
    if(cross(a, b)<0) return -1;
    if(cross(a, b)>0) return 1;
    return 0;
}
double dot(pt a, pt b){
	return (conj(a)*b).real();
}
/// L is the leftmost point
/// v is the vector of points other than L (v neither contains L, nor a point with the same coordinates as L)
/// v doesn't contain the same point twice
bool turn_right(pt a, pt b, pt c){
    if(cross_sign(b-a, c-b)<=0)
        return true;
    return false;
}
double get_angle(pt a, pt b){
    return arg(b-a);
}

pt leftmost(vector<pt> v){
	pt lm = v[0];
	loop(v.size())
		if(v[i].real()<lm.real()) lm = v[i];
	return lm;
}

vector<pt> clean(vector<pt> v, pt L){
	vector<pt> res;
	map<pair<double,double>,int> m;
	loop(v.size()){
		if(m[make_pair(v[i].real(), v[i].imag())]) continue;
		if(v[i]==L) continue;
		res.push_back(v[i]);
		m[make_pair(v[i].real(), v[i].imag())]++;
	}
	return res;
}

void print(deque<pt> v){
	for(auto p: v) cout<<p<<" "; cout<<endl;
}
vector<pt> sort_by_inc_ang(pt L, vector<pt> v){
    set<pair<double, int>> s;
    vector<pt> sorted_v;
    for(int i=0;i<v.size(); i++)
    {
        double ang = get_angle(L, v[i]);
        s.insert(make_pair(ang, i));
    }
    for(auto [_, i]: s)
        sorted_v.push_back(v[i]);
    return sorted_v;
}
deque<pt> convex_hull(pt L, vector<pt> v){
    v = sort_by_inc_ang(L, v);
	v.push_back(L);

    deque<pt> res; res.push_back(L);
    for(auto &p: v){
        res.push_back(p);
        int len = res.size();
        while(len>=3&&turn_right(res[len-3], res[len-2], res[len-1])){
            res.erase(res.end()-2);
			len = res.size();
        }
    }
	res.erase(res.end()-1);
    return res;
}
pt proj(pt z1, pt z2){
	// projection of z2 over the line defined by z1
	pt origin=pt (0,0);
	if(z1==origin||z2==origin) return origin;
	return (dot(z1, z2)/dot(z1,z1))*z1;
}
double orth(pt a, pair<pt, pt> line){
	// cout<<"a: "<<a<<" "<<line.first<<" "<<line.second<<endl;
	pt z1 = line.second-line.first;
	pt z2 = a-line.first;
	pt p = proj(z1, z2);
	cout<<z1<<" "<<z2<<endl;
	cout<<p<<endl;
	return abs(z2-p);
}
double ternary_search(pair<pt,pt> line, deque<pt> v){
	int l = 0, r = v.size()-1;
	while(l<=r-3){
		int m1 = (r-l)/3 + l;
		int m2 = 2*(r-l)/3 + l;

		if(orth(v[m1], line)<orth(v[l], line))
			r = m1+1;
		else if(orth(v[m2], line)<orth(v[r], line))
			l = m2+1;
		else {
			l = m1;
			r = m2;
		}
	}
	double res = 0.;
	// cout<<line.first<<" "<<line.second<<endl;
	for(int i=l; i<=r; i++){
		// cout<<"orth of : "<<v[i]<<" "<<orth(v[i], line)<<endl;
		res = max(res, orth(v[i], line));
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(17);

	int n, r;
	cin>>n>>r;
	vector<pt> v(n);
	loop(n){
		double x, y;
		cin>>x>>y;
		v[i] = pt (x,y);
	}

	// double d = orth(pt(1,1), {pt (0,0),pt (2,2)});
	// cout<<"distance: "<<d<<endl;

	// Get the leftmost point
	pt L = leftmost(v);
	// Remove redundancies from v then remove the leftmost point 
	v = clean(v, L);

	// Get the convex_hull
	deque<pt> dq = convex_hull(L, v);

	// cout<<"The leftmost point: "<<L<<endl;
	// for(auto x: dq) cout<<x<<" "; cout<<endl;

	// Iterate over the lines of the convex_hall
	
	// double ans = INFINITY;
	// loop(dq.size()){
	// 	pt a = dq[0], b = dq[1];
	// 	pair<pt, pt> line = {a, b};
	// 	dq.pop_front(); dq.pop_front();

	// 	double curr = ternary_search(line, dq);
	// 	ans = min(ans, curr);
	// 	dq.push_front(b);
	// 	dq.push_back(a);
	// }
	// cout<<ans<<endl;
}