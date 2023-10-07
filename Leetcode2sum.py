class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_to_index = {}  # Create a hashmap to store elements and their indices
        
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_to_index:
                # Return the indices of the two numbers that add up to the target
                return [num_to_index[complement], i]
            num_to_index[num] = i
        
        # If no solution is found, return an empty list
        return []
