class Solution:
    
    def checkPages(self, arr: list, k: int, max_pages: int) -> bool:
        total1, total2 = 1, 0
        for i in arr:
            total2 += i
            if total2 > max_pages:
                total1 += 1
                total2 = i
        return total1 <= k
    
    #Function to find minimum number of pages.
    def findPages(self, arr, k):
        #code here
        if k > len(arr):
            return -1
        low, high = 0, 0
        for i in arr:
            low = max(low, i)
            high += i
        ans = low
        while low <= high:
            mid = (low + high) >> 1
            if self.checkPages(arr, k, mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.findPages(A, D)
        print(ans)
        print("~")

# } Driver Code Ends
