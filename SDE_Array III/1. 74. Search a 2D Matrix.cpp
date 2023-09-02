class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(), c=matrix[0].size();
        int l=0, h=r*c-1, m, i, j;
        while(l<=h){
            m=l+(h-l)/2;
            i=m/c;
            j=m%c;
            if (matrix[i][j]==target) return true;
            else if (target<matrix[i][j]) h=m-1;
            else l=m+1;
        }
        return false;
    }
};