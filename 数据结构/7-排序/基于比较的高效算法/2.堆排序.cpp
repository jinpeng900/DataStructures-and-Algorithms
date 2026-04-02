#include <iostream>
using namespace std;    

// 建立大根堆(优先队列)
void BuildMaxHeap(int a[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        HeadAdjust(a, i, n);
    }
}


void HeadAdjust(int A[], int k, int len)
{
    // 函数 HeadAdjust 对以元素 k 为根的子树进行调整
    A[0] = A[k];                // A[0] 暂存子树的根节点
    for (int i = 2 * k ; i < len ; i *= 2){
        if (i < len && A[i] < A[i + 1]){
            ++i;
        }
        if (A[0] >= A[i]){
            break;
        }
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}


void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len);
    for (int i = len ; i > 1; --i){
        swap(A[i], A[1]);
        HeadAdjust(A, 1, i-1);
    }
}