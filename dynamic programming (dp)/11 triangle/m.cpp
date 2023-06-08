// TC: O(h*(h+1))/2) = O(h^2)
// SC: O(h) + O(h^2) = O(h^2)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, vector<vector<int>>& triangle, int n,vector<vector<int>>& mv){
    if(i == n-1) return triangle[i][j];
    if(mv[i][j] != -1) return mv[i][j];
    return mv[i][j] = triangle[i][j] + min(r(i+1, j, triangle, n, mv), r(i+1, j+1, triangle, n, mv));
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> mv(n, vector<int>(n, -1));
	return r(0, 0, triangle, n, mv);
}

int main(){
    
    return 0;
}