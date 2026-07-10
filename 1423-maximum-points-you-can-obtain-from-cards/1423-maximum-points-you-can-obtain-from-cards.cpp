#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int l) {
        int n = nums.size();
        int curr = 0;
        for (int i = 0; i < l; i++) {
            curr += nums[i];
        }  
        int ans = curr;
        for (int i = l - 1; i >= 0; i--) {
            curr -= nums[i];
            curr += nums[n - l + i];
            ans = max(ans, curr); 
        }    
        return ans;
    }
};