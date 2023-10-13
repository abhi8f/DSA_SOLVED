class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end()), m, s;
        while(l<=r){
            m=l+(r-l)/2;
            s=0;
            for(int x: piles) {
                s+=ceil((double)x/(double)m);
                if (s>h) break;
            }
            if (s<=h) r=m-1;
            else l=m+1;
        }
        return l;
    }
};