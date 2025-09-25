class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        # nums = [i for i in range(n)]
        # for i in range(1,k):
        #     sure
            
            
            
            
        
        
        
        # come lets try, i comment urs first? fk py
        
        
        
        nums = [i+1 for i in range(n)] #get all nums
        factors = [1] * (n+1) #all factors

        for i in range(1,n+1):
            factors[i] = factors[i-1]*i

        k -= 1 #0-based index?
        res = []

        for len in range(n,0,-1):
            block = factors[len-1]
            ind = k // block
            k = k%block
            res.append(str(nums[ind]))
            nums.pop(ind)
            
        return "".join(res)
        
        