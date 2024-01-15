class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        
        while (left <= right):
            mid = (right + left) // 2
            
            if nums[mid] == target:
                return mid
            elif target < nums[mid]:
                right = mid - 1
            elif target > nums[mid]:
                 left = mid + 1
                    
        return left