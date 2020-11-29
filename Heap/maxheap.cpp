#include <cstdio>
#include <cstring>

class MaxHeap 
{
public:
  MaxHeap(int N) 
  {
    heap = new int[N+1];
    size = 0;
  }

  bool isEmpty() 
  {
    return size == 0;
  }

  int getSize()
  {
    return size;
  }

  void insert(int v)
  {
    heap[++size] = v;
    swim(size);
  }

  int pop()
  {
    int max = heap[1];
    heap[1] = heap[size--];
    heap[size+1] = 0;
    sink(1);
    return max;
  }

  ~MaxHeap() 
  {
    delete[] heap;
  }

private :
  int *heap;
  int size;


  void exch(int i, int j) 
  { 
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
  }

  void swim(int k) 
  {
    while (k>1 && heap[k/2] < heap[k])
    {
      exch(k/2, k);
      k = k/2;
    }
  }

  void sink(int k)
  {
    while (2*k <= size) 
    {
      int i = 2*k;
      if (i < size && heap[i+1] > heap[i]) i++;
      if (heap[k] > heap[i]) break;
      exch(k, i);
      k = i;
    }
  }
};

int main()
{
  MaxHeap maxHeap(10);
  maxHeap.insert(5);
  maxHeap.insert(7);
  maxHeap.insert(3);
  maxHeap.insert(12);
  maxHeap.insert(1);
  maxHeap.insert(4);
  maxHeap.insert(10);

  while(!maxHeap.isEmpty()) {
    printf("%d\n", maxHeap.pop());
  }
  return 0;
}
