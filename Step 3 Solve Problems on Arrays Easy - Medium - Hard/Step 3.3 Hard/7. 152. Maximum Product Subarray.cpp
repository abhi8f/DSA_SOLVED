class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size(), mx=arr[0], mn=arr[0], ans=arr[0], temp;

        for(int i=1; i<n; i++){
            temp = max({arr[i], mx*arr[i], mn*arr[i]});
            
            mn=min({arr[i], mx*arr[i], mn*arr[i]});
            mx=temp;

            ans=max(ans, mx);
        }
        return ans;
    }
};