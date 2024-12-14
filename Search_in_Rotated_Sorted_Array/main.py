#User function Template for python3

class Solution:
    def search(self,arr,key):
        # Complete this function
        low, high = 0, len(arr) - 1
        while low <= high:
            mid = (low + high) >> 1
            if arr[mid] == key:
                return key
            if arr[low] <= arr[mid]:
                if arr[low] <= key and arr[mid] >= key:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if arr[mid] <= key and arr[high] >= key:
                    low = mid + 1
                else:
                    high = mid - 1
        return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.search(A, k))
        print("~")

# } Driver Code Ends
