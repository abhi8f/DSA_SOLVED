class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r_min = 0, c_min = 0;
        int r_max = matrix.size()-1, c_max = matrix[0].size()-1;
        vector<int> result;

        for(int i=0, r = 0, c = 0; i<matrix.size()*matrix[0].size(); i++)
        {
            result.push_back(matrix[r][c]);

            if     (r==r_min && c!=c_max) c++;
            else if(r!=r_max && c==c_max) r++;
            else if(r==r_max && c!=c_min) c--;
            else if(r!=r_min && c==c_min) r--;

            if(r==r_min && c==c_min) r++, c++, r_min++, c_min++, r_max--, c_max--;
        }
        return result;
    }
};
