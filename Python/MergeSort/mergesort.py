class MergeSort:
  def rsort(self, a, aux, left, right):
    if left >= right:
      return

    mid = (left + right) // 2
    print(mid)
    self.rsort(a, aux, left, mid)
    self.rsort(a, aux, mid+1, right)
    self.merge(a, aux, left, mid, right)

  def merge(self, a, aux, left, mid, right):
    aux[left:right+1] = a[left:right+1]

    i = left
    j = mid + 1

    for k in range(left, right + 1):
      if i > mid:
        a[k] = aux[j]
        j += 1
      elif j > right:
        a[k] = aux[i]
        i += 1
      elif aux[i] > aux[j]:
        a[k] = aux[j]
        j += 1
      else:
        a[k] = aux[i]
        i += 1


  def sort(self, a):
    aux = a[:]
    self.rsort(a, aux, 0, len(a) - 1)


if __name__ == "__main__":
  a = [2, 4, 6, 1, 3, 5]
  aux = a[:]
  print(aux)

  ms = MergeSort()
  #ms.merge(a, aux, 0, 2, 5)
  ms.sort(a)

  print(a)

