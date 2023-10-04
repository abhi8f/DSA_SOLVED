#include<bits/stdc++.h>

int getLongestZeroSumSubarrayLength(vector<int> &arr) {
	unordered_map<int, int> m;
	int n=arr.size(), ans=0, curSum=0;
	m[0]=-1;
	for(int i=0; i<n; i++){
		curSum+=arr[i];
		auto search=m.find(curSum);
		if (search!=m.end()){
			ans=max(ans, i-search->second);
		} 
		else m[curSum]=i;
	}
	return ans;
	
}