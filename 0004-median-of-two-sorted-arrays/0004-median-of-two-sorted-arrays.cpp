class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n = nums1.size(); 
        int m = nums2.size();
        
        int left = 0;
        int right = n; 
        int k = (n + m + 1) / 2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;   
            int cut2 = k - mid;                    
            int l1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int r1 = (mid == n) ? INT_MAX : nums1[mid];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];
            
            if (l1 > r2) {
                right = mid - 1; 
            }
            else if (l2 > r1) {
                left = mid + 1; 
            }
            else {
                if ((n + m) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    return max(l1, l2);
                }
            }
        }
        
        return 0.0;
    }
};