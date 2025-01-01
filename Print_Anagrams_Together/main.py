#User function Template for python3

class Solution:

    def anagrams(self, arr):
        '''
        words: list of word
        n:      no of words
        return : list of group of anagram {list will be sorted in driver code (not word in grp)}
        '''

        #code here
        v, vec, hmap = [], [], {}
        for i in range(len(arr)):
            cpy = ''.join(sorted(arr[i]))
            if cpy in hmap:
                hmap[cpy].append(arr[i])
            else:
                hmap[cpy] = [arr[i]]
        for i in hmap.values():
            for j in i:
                vec.append(j)
            v.append(vec)
            vec.clear()
        return v

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for tcs in range(t):
        words = input().split()

        ob = Solution()
        ans = ob.anagrams(words)

        for grp in sorted(ans):
            for word in grp:
                print(word, end=' ')
            print()

        print("~")

# } Driver Code Ends
