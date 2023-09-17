class Solution {
public:
    int uniquePaths(int m, int n) {
        int t=m+n-2;
        int c=min(m-1, n-1);
        double ans=1;
        for(int i=0;i<c;i++)
            ans=(ans*(t-i))/(i+1);
        return ans;
        
    }
};
