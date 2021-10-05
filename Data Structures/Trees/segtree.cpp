#include<bits/stdc++.h>
using namespace std;

#define END '\n'
#define int long long

//Minimum Segment Tree
struct SegTree{
	int size;
	vector<int> f;
	void initialize(int n){
		size = 1;
		while(size < n)
			size *= 2;
		f.assign(2 * size, 2e9);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			f[x] = v;
			return;
		}
		int m = (lx + rx)/2;
		if(i < m)
			set(i, v, 2 * x + 1, lx, m);
		else
			set(i, v, 2 * x + 2, m, rx);
		f[x] = min(f[2 * x + 1], f[2 * x + 2]);
	}
	void set(int i, int v){
		set(i, v, 0, 0, size);
	}
	int mn(int l, int r, int x, int lx, int rx){
		if(lx >= r|| l >= rx) return init;
		else if(lx >= l && rx <= r) return f[x];
		int m = (lx + rx)/2;
		return min(mn(l, r, 2 * x + 1], lx, m), mn(l, r, 2 * x + 2, m, rx));
	}
	int mn(int l, int r){
		return mn(l, r, 0, 0, size);
	}
};
void solve(){
	int n, m;
	cin>>n>>m;
	SegTree st;
	st.initialize(n);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
		st.set(i, a[i]);
	}
	for(int j = 0; j < m; j++){
		int type;
		cin>>type;
		if(type == 1){
			//Set the ith index to v
			int i, v;
			cin>>i>>v;
			st.set(i, v);
		}
		else{
			//Find the minimum in the range [l, r)
			int l, r;
			cin>>l>>r;
			cout<<st.get(l, r)<<END;
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}
