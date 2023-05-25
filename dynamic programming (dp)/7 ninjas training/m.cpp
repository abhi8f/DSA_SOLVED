// TC: O(3n) = O(n)
// SC: O(n) + O(3n) = O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int selectIndex, vector<vector<int>> &points, vector<vector<int>> &mv) {
    if (i==points.size()) return 0;
    int maxPoints=INT_MIN;
    for(int c=0;c<3;c++){
        if (selectIndex==c) continue;
        if (mv[i][c]==-1) mv[i][c]=points[i][c]+ r(i+1,c,points,mv);
        maxPoints=max(maxPoints, mv[i][c]);
    }
    return maxPoints;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> mv(n, vector<int>(3,-1));
    return r(0,-1,points, mv);
}

int main(){
    vector<vector<int>> points={
        {10,20,90},
        {10,30,150},
        {40,180,20},
        {160,20,50}
    };
    cout<<ninjaTraining(4,points)<<endl;
    return 0;
}