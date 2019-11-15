//
//  main.c
//  test_7_25(排序)
//
//  Created by 张辉 on 2019/7/25.
//  Copyright © 2019 张辉. All rights reserved.
//

//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  冒泡排序
void Swap(int *x , int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(int* arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                Swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
void PrintSort(int *arr,int size)
{
    for(int j=0; j < size; j++)
    {
        printf("%d ",arr[j]);
    }
    printf("\n");
}


//   选择排序
void SelectSort(int* arr, int size)
{
    for(int i = 0; i < size-1; i++)  //  也可以用 i < size
    {
        int k = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
        }
        Swap(&arr[i], &arr[k]);
    }
}
 // 插入排序
void InsertSort(int* arr, int size)
{
    int i, j, temp;
    for(i = 1; i < size; i++)
    {
        if(arr[i] < arr[i-1])
        {
            temp = arr[i];
            for(j = i - 1; j >= 0 && arr[j] > temp; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
    }
}
//   堆排序
void AdjustDown(int* arr,int size,int parent)
{
    int child = parent * 2 + 1;
    while(child < size)
    {
        //选出两个孩子中较小的那个孩子
        if(child+1 < size && arr[child+1] < arr[child])
            ++child;
        
        //孩子小于父亲，则交换
        if(arr[child] < arr[parent])
        {
            Swap(&arr[child],&arr[parent]);
            parent = child;
            child = parent*2+1;
        }
        else
        {
            break;
        }
    }
}
void HeapSort(int* arr,int size)
{
    //构建堆
    for(int i = (size-1-1)/2; i>=0; i--)
    {
        AdjustDown(arr, size, i);
    }
}


// 快速排序
//  1>
int patition(int* arr, int left, int right)
{
    int key = arr[right];
    int j = left;
    int i = j - 1;
    for(j = left; j < right; j++)
    {
        if(arr[j] <= key)
            Swap(&arr[j],&arr[++i]);
    }
    Swap(&arr[right],&arr[++i]);
    return i;
}
void QuickSort(int* arr, int left, int right)
{
    if(left >= right)
        return;
    int mid = patition(arr, left, right);
    QuickSort(arr, left, mid-1);
    QuickSort(arr, mid+1, right);
}
// 2>
//void QuickSort(int *arr, int begin, int end)
//{
//    int i, j;
//    if (begin < end) {
//        i = begin + 1;
//        j = end;
//        while (i < j) {
//            if(arr[i] > arr[begin]) {
//                Swap(&arr[i], &arr[j]);
//                j--;
//            } else {
//                i++;
//            }
//        }
//        if (arr[i] >= arr[begin]) {
//            i--;
//        }
//        Swap(&arr[begin], &arr[i]);
//        QuickSort(arr, begin, i);
//        QuickSort(arr, j, end);
//    }
//}
  //挖坑法
//int PartSort(int* arr, int left, int right)
//{
//    int key = arr[right];
//    while(left < right)
//    {
//        while(left < right && arr[left] <= key)
//        {
//            ++left;
//            arr[right] = arr[left];
//        }
//        while(left < right && arr[right] >= key)
//        {
//            --right;
//            arr[left] = arr[right];
//        }
//    }
//    arr[left] = key;
//    return left;
//}
//void QuickSort(int* arr, int left, int right)
//{
//    if(left >= right)
//        return;
//    int mid = PartSort(arr, left, right);
//    QuickSort(arr, left, mid-1);
//    QuickSort(arr, mid+1, right);
//}

//  3> 前后指针法
//int PartSort3(int* arr, int left, int right)
//{
//    int key = arr[right];
//    int prev = left - 1;
//    int cur = left;
//    while(cur < key)
//    {
//        if(arr[cur] < key && ++prev != cur)
//            Swap(&arr[cur], &arr[prev]);
//        ++cur;
//    }
//    ++prev;
//    Swap(&arr[right], &arr[prev]);
//    return prev;
//}
//void QuickSort(int* arr, int left, int right)
//{
//    if(left >= right)
//        return;
//    int mid = PartSort3(arr, left, right);
//    QuickSort(arr, left, mid-1);
//    QuickSort(arr, mid+1, right);
//}

// 归并排序
// 1>递归
//void _MergeSort(int* a, int left, int right, int* tmp)
//{
//    if (left == right)
//        return;
//
//    int mid = left + (right - left) / 2;
//    // [left, mid] [mid+1, right]分别有序
//    _MergeSort(a, left, mid, tmp);
//    _MergeSort(a, mid+1, right, tmp);
//
//    // a[left, mid] a[mid+1, right]归并到tmp[left, right]
//    int begin1 = left, end1 = mid;
//    int begin2 = mid + 1, end2 = right;
//    int i = left;
//    while (begin1 <= end1 && begin2 <= end2)
//    {
//        if (a[begin1] < a[begin2])
//        {
//            tmp[i++] = a[begin1];
//            ++begin1;
//        }
//        else
//        {
//            tmp[i++] = a[begin2];
//            ++begin2;
//        }
//    }
//
//    while (begin1 <= end1)
//    {
//        tmp[i++] = a[begin1];
//        ++begin1;
//    }
//
//    while (begin2 <= end2)
//    {
//        tmp[i++] = a[begin2];
//        ++begin2;
//    }
//    memcpy(a + left, tmp + left, sizeof(int)*(i - left));
//}
//
//void MergeSort(int* a, int n)
//{
//    int* tmp = (int*)malloc(sizeof(int)* n);
//    _MergeSort(a, 0, n - 1, tmp);
//    free(tmp);
//}
// 2> 递归
//void Merge(int a[], int left, int mid, int right)
//{
//    int len = right - left + 1;        //    数组的长度
//    int *temp = (int*)malloc(sizeof(int)* len); //分配个临时数组
//    int k = 0;
//    int i = left;                   // 前一数组的起始元素
//    int j = mid + 1;                // 后一数组的起始元素
//    while (i <= mid && j <= right)
//    {
//        //    选择较小的存入临时数组
//        temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
//    }
//    while (i <= mid)
//    {
//        temp[k++] = a[i++];
//    }
//    while (j <= right)
//    {
//        temp[k++] = a[j++];
//    }
//    for (int k = 0; k < len; k++)
//    {
//        a[left++] = temp[k];
//    }
//    free(temp);
//}
//
//// 递归实现的归并排序
//void MergeSort(int a[], int left, int right)
//{
//    if (left == right)
//        return;
//    int mid = (left + right) / 2;
//    MergeSort(a, left, mid);
//    MergeSort(a, mid + 1, right);
//    Merge(a, left, mid, right);
//}
//3> 非递归
void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int)* n);
    
    // [begin1,end1][begin2,end2]
    int gap = 1;
    while (gap < n)
    {
        for (int begin = 0; begin < n; begin += 2*gap)
        {
            // [begin, begin+gap-1][begin+gap, begin+2*gap-1]
            // [0, 0][1, 1]  gap = 1
            // [0, 1][2, 3]     gap = 2
            
            int begin1 = begin, end1 = begin+gap-1;
            if (end1 >= n)
                end1 = n - 1;
            
            int begin2 = begin+gap, end2 = begin+2*gap-1;
            if (end2 >= n)
                end2 = n - 1;
            
            int index = begin1;
            while (begin1 <= end1 && begin2 <= end2)
            {
                if (a[begin1] < a[begin2])
                    tmp[index++] = a[begin1++];
                else
                    tmp[index++] = a[begin2++];
            }
            
            while (begin1 <= end1)
                tmp[index++] = a[begin1++];
            
            while (begin2 <= end2)
                tmp[index++] = a[begin2++];
            
        }
        memcpy(a, tmp, sizeof(int)*n);
        
        gap *= 2;
        
    }
    free(tmp);
}
int main()
{
    int arr[] = { 7, 4, 1, 2, 3, 9, 8, 0, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    printf("arr:");
    PrintSort(arr, size);
    BubbleSort(arr, size);
    printf("BubbleSort:");
    PrintSort(arr, size);
    SelectSort(arr, size);
    printf("SecectSort:");
    PrintSort(arr, size);
    InsertSort(arr, size);
    printf("InsertSort:");
    PrintSort(arr, size);
    HeapSort(arr, size);
    printf("HeapSort:  ");
    PrintSort(arr, size);
    QuickSort(arr, 0, size-1);
    printf("QuickSort: ");
    PrintSort(arr, size);
    MergeSort(arr, size);
    printf("MergeSort: ");
    PrintSort(arr, size);
    return 0;
}
