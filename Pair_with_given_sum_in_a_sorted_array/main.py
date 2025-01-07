#User function Template for python3


class Solution:
    def countPairs (self, arr, target) : 
        #Complete the function
        count, left, right = 0, 0, len(arr) - 1
        while left < right:
            total = arr[left] + arr[right]
            if total == target:
                count += 1
                l = left + 1
                while l < right and arr[l] == arr[left]:
                    count += 1
                    l += 1
                r = right - 1
                while left < r and arr[r] == arr[right]:
                    count += 1
                    r -= 1
                left += 1
                right -= 1
            elif total < target:
                left += 1
            else:
                right -= 1
        return count

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    import sys
    input = sys.stdin.read
    data = input().split('\n')

    t = int(data[0].strip())
    index = 1

    for _ in range(t):
        arr = list(map(int, data[index].strip().split()))
        index += 1
        target = int(data[index].strip())
        index += 1

        res = Solution().countPairs(arr, target)
        print(res)
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
