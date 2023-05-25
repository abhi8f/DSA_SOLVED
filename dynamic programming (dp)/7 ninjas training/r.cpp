// TC: O(3^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int selectIndex, vector<vector<int>> &points) {
    if (i==points.size()) return 0;
    int maxPoints=INT_MIN;
    for(int c=0;c<3;c++){
        if (selectIndex==c) continue;
        maxPoints=max(maxPoints, points[i][c]+ r(i+1,c,points));
    }
    return maxPoints;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    return r(0,-1,points);
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