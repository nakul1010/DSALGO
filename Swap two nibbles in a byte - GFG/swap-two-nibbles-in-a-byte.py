#User function Template for python3
class Solution:
    def swapNibbles (self, N):
       b = bin(N)
       b = b.replace("0b","0"*(10-len(b)))
       b = b[4:]+b[:4]
       return int(b,2)

#{ 
#  Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
       

        ob = Solution()
        print(ob.swapNibbles(N))
# } Driver Code Ends