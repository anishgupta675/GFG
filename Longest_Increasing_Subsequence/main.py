class Solution:
    def lower_bound(self, a: list[int], low: int, high: int, target: int) -> int:
        if low > high:
            return low
        mid = (low + high) >> 1
        if target <= a[mid]:
            return self.lower_bound(a, low, mid - 1, target)
        return self.lower_bound(a, mid + 1, high, target)
    def lis(self, arr):
        count = 1
        res = []
        res.append(arr[0])
        for i in range(1, len(arr)):
            if arr[i] > res[-1]:
                res.append(arr[i])
                count += 1
            else:
                res[self.lower_bound(res, 0, len(res) - 1, arr[i])] = arr[i]
        return len(res)

#{ 
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    for _ in range(int(input())):
        a = [int(x) for x in input().split()]
        ob = Solution()
        print(ob.lis(a))
        print("~")
# } Driver Code Ends
