#User function Template for python3
class Solution:
    def kthMissing(self, arr, k):
        # code here
        low, high = 0, len(arr) - 1
        while low <= high:
            mid = (low + high) >> 1
            if arr[mid] - mid + 1 == k:
                return arr[mid] - 1
            if arr[mid] - mid + 1 < k:
                low = mid + 1
            else:
                high = mid - 1
        return k + high - 1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.kthMissing(A, D)
        print(ans)
        print("~")

# } Driver Code Ends
