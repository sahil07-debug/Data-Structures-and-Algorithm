class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int j=0;
            int a=-1;
            while(nums2[j]!=nums1[i]&& j<nums2.size()){
                j++;
            }
            while(j<nums2.size()){
                if(nums2[j]>nums1[i]){
                    a=nums2[j];
                    break;
                }
                j++;
            }
            ans.push_back(a);
        }
        return ans;
    }
};