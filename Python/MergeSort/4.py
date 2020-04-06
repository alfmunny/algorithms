import time

def merge(a, aux, lo, mid, hi):
  aux[lo:hi+1] = a[lo:hi+1]
  i = lo
  j = mid + 1
  for k in range(lo, hi+1):
    if i > mid:
      a[k] = aux[j]
      j += 1
    elif j > hi:
      a[k] = aux[i]
      i += 1
    elif aux[j] < aux[i]:
      a[k] = aux[j]
      j += 1
    else:
      a[k] = aux[i]
      i += 1

def rec_sort(a, aux, lo, hi):

  if lo >= hi:
    return

  mid = (lo + hi) // 2

  rec_sort(a, aux, lo, mid)
  rec_sort(a, aux, mid+1, hi)
  merge(a, aux, lo, mid, hi)

def sort(a):
  aux = a[:]
  rec_sort(a, aux, 0, len(a) - 1)

start = time.time()
a = [2, 4, 6, 8, 10, 1, 3, 5, 9, 7, 2, 6, 8, -1]
print(a)
