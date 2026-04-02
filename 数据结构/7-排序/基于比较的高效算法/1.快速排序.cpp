#include<iostream>

using namespace std;

#define MAX 1000

typedef struct 
{
    int * elem;
    int length;
} Sqlist;



int Partition(Sqlist &L , int low , int high)
{
    int pivot = L.elem[low];
    while (low < high)
    {
        while (low < high && L.elem[high] >= pivot)
        {
            --high;
        }
        L.elem[low] = L.elem[high];
        while (low < high && L.elem[low] < pivot)
        {
            ++low;
        }
        L.elem[high] = L.elem[high];
    }
    L.elem[low] = pivot;
    return low;
}


void QuickSort(Sqlist &L , int left , int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = Partition(L , left , right);
    QuickSort(L , left , pivot - 1);
    QuickSort(L , pivot + 1 , right);
}



int main()
{
    Sqlist ls;
    
    cin >> ls.length;
    
    ls.elem = new int[ls.length];
    for (int i = 1 ; i <= ls.length ; i++)
    {
        cin >> ls.elem[i];
    }

    QuickSort(ls , 1 , ls.length);

    for (int i = 1 ; i <= ls.length ; i++)
    {
        cout << ls.elem[i] << endl;
    }   

    delete[] ls.elem;
    return 0;
}