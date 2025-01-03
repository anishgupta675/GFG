class Solution:
    def subarrayXor(self, arr, k):
        # code here
        pre_xor, count, hmap = 0, 0, {}
        for i in range(len(arr)):
            pre_xor ^= arr[i]
            if pre_xor == k:
                count += 1
            if pre_xor ^ k in hmap:
                count += hmap[pre_xor ^ k]
            if pre_xor in hmap:
                hmap[pre_xor] += 1
            else:
                hmap[pre_xor] = 1
        return count

#{ 
 # Driver Code Starts
if __name__ == "__main__":
    tc = int(input())

    for _ in range(tc):
        arr = list(map(int, input().split()))
        k = int(input())

        obj = Solution()
        print(obj.subarrayXor(arr, k))
        print("~")

# } Driver Code Ends
