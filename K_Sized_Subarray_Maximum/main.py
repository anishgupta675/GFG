class Solution:
    def getMaxIndex(self, arr, low, high):
        max_index = low
        for i in range(low, high + 1):
            if arr[i] > arr[max_index]:
                max_index = i
        return max_index

    def maxOfSubarrays(self, arr, k):
        # code here
        if k == 1:
            return arr
        res = []
        max_index, low, high = 0, 0, k - 1
        while high < len(arr):
            if max_index == low - 1:
                max_index = self.getMaxIndex(arr, low, high)
            else:
                if arr[high] > arr[max_index]:
                    max_index = high
            res.append(arr[max_index])
            low += 1
            high += 1
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys
from collections import deque

#Contributed by : Nagendra Jha

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        arr = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        res = ob.maxOfSubarrays(arr, k)
        for i in range(len(res)):
            print(res[i], end=" ")
        print()
        print("~")
# } Driver Code Ends
