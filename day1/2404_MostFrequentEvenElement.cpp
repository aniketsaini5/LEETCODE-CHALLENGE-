// Approach:
// Data Structure:

// The function uses a std::map<int, int> named um to store each integer from the input vector nums as a key and its corresponding frequency as the value.
// Counting Frequencies:

// It iterates through the vector nums and populates the map um. For each integer encountered in nums, it increments its count in the map um.
// Finding the Most Frequent Even Integer:

// Initialize variables max to track the maximum frequency found and ans to store the corresponding integer.
// Iterate through the map um using a range-based for loop (for (auto it : um)):
// Check if the key (integer) it.first is even (it.first % 2 == 0).
// If it is even, compare its frequency (it.second) with max.
// Update max and ans accordingly if it.second is greater than max.
// Return:

// Algorithm:
// Step 1: Initialize Map:

// Create an empty map um to store integer frequencies.
// Step 2: Populate Frequencies:

// Loop through each integer in nums.
// Use um[nums[i]]++ to increment the count for each integer nums[i] in the map um.
// Step 3: Find Maximum Frequency Even Integer:

// Initialize max to 0 and ans to -1.
// Iterate through each entry in um.
// If the key (it.first) is even, compare its frequency (it.second) with max.
// Update max and ans if it.second is greater than max.
// Step 4: Return Result:

// Return ans, which holds the most frequently occurring even integer. If no even integers were found (ans remains -1), return -1.
// Example:
// For an input vector nums = {1, 2, 2, 3, 4, 4, 4, 5}, the function would populate the map as follows:

// um = {1: 1, 2: 2, 3: 1, 4: 3, 5: 1}
// After iterating through um, it would find that 4 has the highest frequency among even integers (max = 3), so it would return 4.




class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> um;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            um[nums[i]]++;
        }
        int max = 0;
        int ans = -1;
        for (auto it : um) {
            if (it.first % 2 == 0) {
                if (it.second > max) {
                    max = it.second;
                    ans = it.first;
                }
            }
        }
        return ans;    
    }
};