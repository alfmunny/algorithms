def sort(a):
  rec_sort(a, 0, len(a) - 1)

def rec_sort(a, lo, hi):
  if lo >= hi:
    return

  j = partition(a, lo, hi)
  rec_sort(a, lo, j - 1)
  rec_sort(a, j + 1, hi)

def partition(a, lo, hi):
  pivot = a[lo]
  i = lo + 1
  j = hi
  while i <= j:
    while i<= j and a[i] < pivot:
      i += 1
    while  i<= j and a[j] > pivot:
      j -= 1

    if i >= j:
      break

    a[i], a[j] = a[j], a[i]
    i += 1
    j -= 1

  a[lo], a[j] = a[j], a[lo]

  return j


a = [7, 8, 4, 2, 66666, 10000, 16, 6, 1, 5, 7]

sort(a)
print(a)
