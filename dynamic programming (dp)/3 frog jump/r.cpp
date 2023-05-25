// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, vector<int> &heights) {
    if (i == 0) return 0;
    if (i == 1) return abs(heights[0] - heights[1]);
    return min( abs(heights[i] - heights[i - 1]) + r(i - 1, heights), 
                abs(heights[i] - heights[i - 2]) + r(i - 2, heights));
}

int main() {
    vector<int> heights={10,20,30,10};
    int n=4;
    cout<<r(n-1,heights)<<endl;
    vector<int> heights2={10, 50, 30};
    int n2=3;
    cout<<r(n2-1,heights2)<<endl;
    return 0;
}