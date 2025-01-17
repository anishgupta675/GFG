#User function Template for python3

class Solution:
    def productExceptSelf(self, arr):
        #code here
        left, right, prod = [0] * len(arr), [0] * len(arr), [0] * len(arr)
        left[0] = 1
        right[-1] = 1
        for i in range(len(arr)):
            left[i] = arr[i - 1] * left[i - 1]
        for i in range(len(arr) - 2, -1, -1):
            right[i] = arr[i + 1] * right[i + 1]
        for i in range(len(arr)):
            prod[i] = left[i] * right[i]
        return prod

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):

        arr = [int(x) for x in input().split()]

        ans = Solution().productExceptSelf(arr)
        print(*ans)
        print("~")

# } Driver Code Ends
