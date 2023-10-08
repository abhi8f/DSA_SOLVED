int rightMost(vector<int>& arr, int x, int l, int r){
	int m, ans=-1;
	while(l<=r){
		m=l+(r-l)/2;
		if (arr[m]==x) ans=m, l=m+1;
		else if (arr[m]>x) r=m-1;
		else l=m+1;
	}
	return ans;
}

int leftMost(vector<int>& arr, int x, int l, int r){
	int m, ans=-1;
	while(l<=r){
		m=l+(r-l)/2;
		if (arr[m]==x) ans=m, r=m-1;
		else if (arr[m]>x) r=m-1;
		else l=m+1;
	}
	return ans;
}

int count(vector<int>& arr, int n, int x) {
	// int l=0, r=n-1, m, tmp;
	// while(l<=r){
	// 	m=l+(r-l)/2;
	// 	if (arr[m]==x){
	// 		return rightMost(arr, x, m, n-1) - leftMost(arr, x, 0, m) + 1;
	// 	}
	// 	else if (arr[m]>x) r=m-1;
	// 	else l=m+1;
	// }
	// return 0;
	int rm=rightMost(arr, x, 0, n-1);
	if (rm==-1) return 0;
	return rm - leftMost(arr, x, 0, n-1) + 1;	
}
