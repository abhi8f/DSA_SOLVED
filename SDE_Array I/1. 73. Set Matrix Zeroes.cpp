class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rs = matrix.size(), cs = matrix[0].size(), col0=1;
        
        for(int i=0;i<rs;i++){
            for(int j=0;j<cs;j++){
                if (matrix[i][j]==0) {
                    matrix[i][0]=0;
                    if (j==0) col0=0;
                    else matrix[0][j]=0;
                }
            }
        }
        for(int i=rs-1;i>=0;i--){
            for(int j=cs-1;j>=0;j--){
                if (matrix[i][0]==0 || (j==0 && col0==0) || (j!=0 && matrix[0][j]==0))
                    matrix[i][j]=0;
            }
        }
    }
};