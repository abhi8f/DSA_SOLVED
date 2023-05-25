// TC: O(n)
// SC: O(n) + O(n) = O(n)
#include <bits/stdc++.h>
using namespace std;

int m(int i, vector<int> &heights, vector<int> &mv) {
    if (mv[i]!=-1) return mv[i];
    if (i == 0) return 0;
    if (i == 1) return abs(heights[0] - heights[1]);
    return mv[i]= min( abs(heights[i] - heights[i - 1]) + m(i - 1, heights, mv), 
                       abs(heights[i] - heights[i - 2]) + m(i - 2, heights, mv));
}

int main() {
    vector<int> heights={10,20,30,10};
    int n=4;
    vector<int> mv(n,-1);
    cout<<m(n-1,heights,mv)<<endl;
    vector<int> heights2={10, 50, 30};
    int n2=3;
    vector<int> mv2(n2,-1);
    cout<<m(n2-1,heights2,mv2)<<endl;
    return 0;
}