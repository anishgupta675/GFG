
class Solution:
    def countTriplets(self, arr, target):
        # code here
        ans = 0
        for i in range(len(arr) - 1):
            left, right = i + 1, len(arr) - 1
            while left < right:
                total = arr[i] + arr[left] + arr[right]
                if total < target:
                    left += 1
                elif total > target:
                    right -= 1
                else:
                    e1, e2, c1, c2 = arr[left], arr[right], 0, 0
                    while left <= right and arr[left] == e1:
                        c1 += 1
                        left += 1
                    while left <= right and arr[right] == e2:
                        c2 += 1
                        right -= 1
                    if e1 == e2:
                        ans += (c1 * (c1 - 1)) >> 1
                    else:
                        ans += c1 * c2
        return ans

#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        target = int(input())
        ob = Solution()
        ans = ob.countTriplets(arr, target)
        print(ans)
        print("~")
# } Driver Code Ends
