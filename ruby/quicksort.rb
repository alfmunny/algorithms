def quicksort(arr, lo, hi)
  if lo < hi
    j = partition(arr, lo, hi)
    quicksort(arr, lo, j-1)
    quicksort(arr, j+1, hi)
  end
  arr
end

def partition(arr, lo, hi)
  i = lo+1
  j = hi;
  p = lo #pivot

  while true 
    p arr
    while i <= j && arr[i] < arr[p]
      i += 1
      break if i == hi
    end

    while i <= j && arr[p] < arr[j]
      j -= 1
      break if j == lo
    end

    break if i >= j
    arr[i], arr[j] = arr[j], arr[i]
    j -= 1
    i += 1
  end

  arr[j], arr[p] = arr[p], arr[j]
  j
end


input = [5, 4, 3, 5, 2, 1,222222,2,2,2,2,2,2]

p quicksort(input, 0, input.length-1)
