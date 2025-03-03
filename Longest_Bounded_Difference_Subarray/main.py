class Solution:
    def longestSubarray(self, arr, x):
        max_val = min_val = i = j = low = high = 0
        while j < len(arr):
            if abs(arr[j] - arr[max_val]) <= x:
                if abs(arr[j] - arr[min_val]) <= x:
                    if abs(arr[j]) > abs(arr[max_val]):
                        max_val = j
                    elif abs(arr[j]) < abs(arr[min_val]):
                        min_val = j
                    j += 1
                else:
                    if (high - low) < j-i:
                        low = i
                        high = j
                    i = min_val + 1
                    min_val = i
                    if max_val < min_val:
                        max_val = min_val
                    j = i + 1
            else:
                if (high - low) < j - i:
                    low = i
                    high = j
                i = max_val + 1
                max_val = i
                if min_val < max_val:
                    min_val = max_val
                j = i + 1
        if (high - low) < j-i:
            low = i
            high = j
        return arr[low:high]

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        ans = ob.longestSubarray(arr, k)

        print(" ".join(map(str, ans)))
        tc -= 1
        print("~")

# } Driver Code Ends        

        
