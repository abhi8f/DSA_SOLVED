7 12 14 15
0 1  2  3
l
		   h
     m1

1 2 3 4 9 11
0 1 2 3 4 5
	  m2

n1 = 4, n2 = 6  (n1+n2+1)/2  = 5

l1 r1
l2 r2

low = 0, high = n1-1;
 
			7 12 14 15    if (r1<l2) low = mid +1;
1 2 3 4 9   11

7 			12 14 15
1 2  3 4    9  11

7 12		14 15         if (l1>r2) high = mid -1;
1 2  3		4  9  11


////////

2 4
1 3 4

n1 = 2, n2 = 3   (n1+n2+1)/2 = 3

			2 4
1 3 4

2 			4
1 3			4

2 4
1			3 4



1 2
0 1
   lh
   m1

3 4
0 1
m2
  
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();   
        if (n1>n2) swap(n1, n2), swap(nums1, nums2);

        int low = 0, high = n1, leftPart = (n1 + n2 + 1)/2;
        int mid1, mid2, l1, l2, r1, r2;

        while(low<=high){
            mid1 = low + (high - low)/2;
            mid2 = leftPart - mid1;
            l1 = (mid1>0) ? nums1[mid1 - 1] : INT_MIN;
            l2 = (mid2>0) ? nums2[mid2 - 1] : INT_MIN;
            r1 = (mid1<n1) ? nums1[mid1] : INT_MAX;
            r2 = (mid2<n2) ? nums2[mid2] : INT_MAX;

            if (r1 < l2) low = mid1 + 1;
            else if (l1 > r2) high = mid1 - 1;
            else if ((n1 + n2) % 2 == 1) return max(l1, l2);
            else return ((double)min(r1, r2) + max(l1, l2))/2;
        }
        return 0;
    }
};