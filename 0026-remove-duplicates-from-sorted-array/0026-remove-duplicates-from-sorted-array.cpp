class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Edge case: empty array
        
        int k = nums.size();  // Get the current size of the vector
        
        for (int i = 1; i < k; )  // Loop through the vector
        {
            if (nums[i] == nums[i-1])  // If a duplicate is found
            {
                // Shift all elements to the left to remove the duplicate
                for (int j = i; j < k - 1; j++) {
                    nums[j] = nums[j + 1];  // Shift elements left
                }
                k--;  // Decrease the size as the duplicate is removed
            }
            else {
                i++;  // Only move to the next element if no duplicate was found
            }
        }
        
        return k;  // Return the new size of the array
    }
};
