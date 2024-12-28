#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


# } Driver Code Ends
#User function Template for python3
class Solution:
    def findTriplets(self, arr):
        # Your code here
        res = []
        for i in range(len(arr) - 2):
            hmap = {}
            for j in range(i + 1, len(arr) - 1):
                if 0 - arr[i] - arr[j] in hmap:
                    res.append([i, j, hmap[0 - arr[i] - arr[j]]])
                else:
                    hmap[arr[j]] = j
        return res


#{ 
 # Driver Code Starts.

def main():
    T = int(input())
    while (T > 0):

        A = [int(x) for x in input().strip().split()]

        ob = Solution()
        res = ob.findTriplets(A)
        res = sorted(res)
        if len(res) == 0:
            print('[]')
        for i in range(len(res)):
            for j in range(len(res[i])):
                print(res[i][j], end=" ")
            print("")
        print('~')
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
