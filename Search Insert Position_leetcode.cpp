class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx;
        int l = 0, r = nums.size()-1;
        while(l<=r) {
            int m = (l+r) / 2;

            if(nums[m] >= target) {
                if(nums[m] == target)
                    return m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
