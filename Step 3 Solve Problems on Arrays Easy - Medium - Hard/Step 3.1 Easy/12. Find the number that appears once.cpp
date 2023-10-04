int getSingleElement(vector<int> &arr){
	int n=arr.size();
	if (n==1) return arr[0];
	for(int i=1; i<n; i+=2) if (arr[i]!=arr[i-1]) return arr[i-1];
	return arr[n-1];	
}


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int x: nums) ans^=x;
        return ans;
    }
};