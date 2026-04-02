// 归并排序

void Merge(int A[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];
    while (i <= mid && j <= right){
        if (A[i] <= A[j]){
            temp[k++] = A[i++];
        }
        else{
            temp[k++] = A[j++];
        }
    }
    while (i <= mid){
        temp[k++] = A[i++];
    }
    while (j <= right){
        temp[k++] = A[j++];
    }
    for (int i = left, k = 0; i <= right; ++i, ++k){
        A[i] = temp[k];
    }
}
