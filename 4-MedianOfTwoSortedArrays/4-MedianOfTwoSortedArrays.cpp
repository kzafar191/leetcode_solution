// Last updated: 5/6/2026, 5:11:16 pm
class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        const vector<int>&A = (nums1.size() <= nums2.size() ? nums1 : nums2);
        const vector<int>&B = (nums1.size() <= nums2.size() ? nums2 : nums1);
        int m = A.size(), n = B.size();
        int low = 0, high = m;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;
            int Aleft = (i == 0 ? INT_MIN : A[i-1]);
            int Aright = (i == m ? INT_MAX : A[i]);
            int Bleft = (j == 0 ? INT_MIN : B[j-1]);
            int Bright = (j == n ? INT_MAX : B[j]);
            
            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 1) {
                    return max(Aleft, Bleft);
                }
                else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            } else if (Aleft > Bright) {
                high = i - 1;
            }
            else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};