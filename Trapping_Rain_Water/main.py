
class Solution:
    def maxWater(self, arr):
        # code here
        low, high = 0, len(arr) - 1
        max_low, max_high, res = arr[low], arr[high], 0
        while low < high:
            if arr[low] < arr[high]:
                low += 1
                res += max(0, max_low - arr[low])
                max_low = max(max_low, arr[low])
            else:
                high -= 1
                res += max(0, max_high - arr[high])
                max_high = max(max_high, arr[high])
        return res

#{ 
 # Driver Code Starts
#Initial template for Python 3

import math


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxWater(arr))

        t -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
