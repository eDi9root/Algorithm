class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int reach = 0;
        int end = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            reach = max(reach, i + nums[i]);
            if (i == end) {
                end = reach;
                res++;
            }
        }
        return res;
    }
};