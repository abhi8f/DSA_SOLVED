// TC: O(3n) = O(n)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points){
    int a0=points[0][0], a1=points[0][1], a2=points[0][2], b0,b1,b2;
    
    for(int i=1;i<n;i++){
        b0=points[i][0]+max(a1,a2);
        b1=points[i][1]+max(a0,a2);
        b2=points[i][2]+max(a0,a1);
        a0=b0;
        a1=b1;
        a2=b2;
    }
    return max(a0,max(a1,a2));
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