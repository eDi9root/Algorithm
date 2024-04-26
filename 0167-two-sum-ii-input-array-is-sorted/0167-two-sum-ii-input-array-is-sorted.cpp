class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Initialize two pointers, 'l' and 'r', pointing to the start and end of the array, respectively.
        int l = 0, r = numbers.size() - 1;
        // Initialize a vector 'ans' to store the result.
        vector<int> ans;

        // Use a while loop to iterate until 'l' is less than 'r'.
        while (l < r) {
            // Calculate the sum of the numbers at positions 'l' and 'r'.
            int sum_val = numbers[l] + numbers[r];

            // If the sum is greater than the target, decrement 'r'.
            if (sum_val > target) {
                r--;
            }
            // If the sum is less than the target, increment 'l'.
            else if (sum_val < target) {
                l++;
            }
            // If the sum is equal to the target, add the indices [l+1, r+1] to 'ans' and return it.
            else {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                return ans;
            }
        }

        // If no solution is found, return an empty vector.
        return ans;
    }
};