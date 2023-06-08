// TC: O(2^((h*(h+1))/2)) = O(2^(h^2))
// SC: O(h)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, vector<vector<int>>& triangle, int n){
    if(i == n-1){
        return triangle[i][j];
    }
    return triangle[i][j] + min(r(i+1, j, triangle, n), r(i+1, j+1, triangle, n));
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	return r(0, 0, triangle, n);
}

int main(){
    
    return 0;
}