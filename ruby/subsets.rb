def subsets(nums)
  ret = [[]]
  nums.each { |n| ret += ret.map { |r| r + [n] } }
  ret
end


p subsets([1,2,3])
