class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        int n = nums.size() - 1;
        int rotated = 0;
        if (nums[0] > nums[n]) {
            int low = 0;
            int high = n;
            while (low <= high) {
                int mid = low + ((high - low) / 2);
                if (nums[mid] < nums[0]) {
                    rotated = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (target >= nums[rotated] && target <= nums[n]) {
            int low = rotated;
            int high = n;
            while (low <= high) {
                int mid = low + ((high - low) / 2);
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        } else {
            int low = 0;
            int high = rotated - 1;
            while (low <= high) {
                int mid = low + ((high - low) / 2);
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1; 
    }
};