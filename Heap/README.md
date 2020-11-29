# Heap

## MaxHeap

A binary tree is heap-ordered if the key in each node is larger than or equal to the keys in that node's two children.

A MaxHeap is an array arranged in heap-ordered binary tree in level order.

We use a N+1 length array. Heap[0] is unused.

1. The maximum is at `Heap[1]`
2. The children of index `k` is at `2*k` and `2*k+1`

## MinHeap

The minimum is at `Heap[0]`. 

## Template

```c++
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

```
