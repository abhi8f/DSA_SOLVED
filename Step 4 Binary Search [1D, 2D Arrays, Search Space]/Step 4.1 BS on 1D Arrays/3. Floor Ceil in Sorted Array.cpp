pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int f=-1, c=-1, l=0, r=n-1, m;
	while(l<=r){
		m=l+(r-l)/2;
		if (a[m]>x) c=a[m], r=m-1;
		else if (a[m]<x) f=a[m], l=m+1;
		else return {x, x};
	}
	return {f, c};
}