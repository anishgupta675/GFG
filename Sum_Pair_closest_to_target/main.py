#User function Template for python3
class Solution:
    def sumClosest(self, arr, target):
        # code here
        if len(arr) < 2:
            return []
        arr.sort()
        i, j, mine, ans = 0, len(arr) - 1, float('inf'), [float('inf'), float('inf')]
        while i < j:
            total = arr[i] + arr[j]
            if abs(target - total) <= mine:
                if abs(target - total) < mine:
                    mine = abs(target - total)
                    ans.clear()
                    ans = [arr[i], arr[j]]
                elif arr[j] - arr[i] > ans[1] - ans[0]:
                    ans.clear()
                    ans = [arr[i], arr[j]]
            if total > target:
                j -= 1
            else:
                i += 1
        return [ans[0], ans[1]]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input().strip())
    while t > 0:
        arr = list(map(int, input().strip().split()))
        target = int(input().strip())
        ob = Solution()
        ans = ob.sumClosest(arr, target)
        if not ans:
            print("[]")
        else:
            print(*ans)
        print("~")
        t -= 1

# } Driver Code Ends
