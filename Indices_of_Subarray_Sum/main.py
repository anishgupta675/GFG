#User function Template for python3
class Solution:
    def subarraySum(self, arr, target):
        # code here
        left, right, total = 0, 0, 0
        while right < len(arr):
            total += arr[right]
            if total == target:
                return [left + 1, right + 1]
            if total < target:
                right += 1
            else:
                total -= arr[left]
                left += 1
                if left > right:
                    right += 1
                else:
                    total -= arr[right]
        return [-1]

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        d = int(input().strip())
        ob = Solution()
        result = ob.subarraySum(arr, d)
        print(" ".join(map(str, result)))
        tc -= 1
        print("~")

# } Driver Code Ends
