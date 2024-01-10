#include <iostream>
#include <vector>

using namespace std;

// Utility function to print a subset
void printSubset(const vector<int>& subset) {
    cout << "Subset: { ";
    for (int num : subset)
        cout << num << " ";
    cout << "}\n";
}

// Function to find and print all subsets with the given sum
void findSubsetsWithSum(vector<int>& nums, int sum, int n, vector<int>& subset) {
    // Base case: if sum becomes 0, print the current subset
    if (sum == 0) {
        printSubset(subset);
        return;
    }

    // Base case: if no more elements are left or sum is negative
    if (n == 0 || sum < 0)
        return;

    // Exclude the last element and recur
    findSubsetsWithSum(nums, sum, n - 1, subset);

    // Include the last element in the subset and recur
    subset.push_back(nums[n - 1]);
    findSubsetsWithSum(nums, sum - nums[n - 1], n - 1, subset);

    // Backtrack: remove the last element to explore other possibilities
    subset.pop_back();
}

int main() {
    // Input: Array of numbers
    vector<int> nums = { 3, 34, 4, 12, 5, 2 };

    // Input: Target sum
    int targetSum = 9;

    // Initial empty subset
    vector<int> emptySubset;

    // Find and print all subsets with the given sum
    cout << "Subsets with sum " << targetSum << ":\n";
    findSubsetsWithSum(nums, targetSum, nums.size(), emptySubset);

    return 0;
}
