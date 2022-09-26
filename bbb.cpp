d = defaultdict(lambda:0) 
n = len(nums)

for i in range(n):
        d[nums[i]] = d[nums[i]] + 1            
    
    nums.sort(key=lambda x:(d[x],-x))    
    
    return (nums)
