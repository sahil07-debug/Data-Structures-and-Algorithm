class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size()-1;
        int n= matrix[0].size()-1;
        int left=0;
        int right=m;
        while(left<=right){
            int mid=left+((right-left)/2);
            if(matrix[mid][0]<=target && matrix[mid][n]>=target){
                int min=0;
                int max=n;
                while(min<=max){
                    int x=min+((max-min)/2);
                    if(matrix[mid][x]==target) return true;
                    else if(matrix[mid][x]<target) min=x+1;
                    else max=x-1;
            }
            return false;
            }
            else if(matrix[mid][n]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};