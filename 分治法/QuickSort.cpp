//
// Created by hitris on 2019-09-25.
//
//
// 快速排序
//
// 基本思想：通过一组排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据要小，
//          然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此使所有数据变成有序序列。
// 算法设计：(1)分解：先从数列中取出一个元素作为基准元素。以基准元素为标准，将问题分解为两个子序列，使小于或等于基准元素的子序列在左侧，使大于基准元素的子序列在右侧。
//          (2)治理：对两个子序列进行快速排序。
//          (3)合并：将排好序的两个子序列合并在一起，得到原问题的解。
//
// 时间复杂度:最好O(nlogn) 最坏O(n2) 平均O(nlogn)
// 空间复杂度:最好O(logn) 最坏O(n) 平均O(logn)

void swap(int a, int b) {}

int Partition(int r[], int low, int high) {
    int i = low, j = high, pivot = r[low];
    while (i < j) {
        while (i < j && r[j] > pivot)
            j--;
        if (i < j) {
            swap(r[i++], r[j]);
        }
        while (i < j && r[i] <= pivot)
            i++;
        if (i < j) {
            swap(r[i], r[j--]);
        }
    }
    return i;
}

void QuickSort(int R[], int low, int high) {
    int mid;
    if (low < high) {
        mid = Partition(R, low, high);
        QuickSort(R, low, mid - 1);
        QuickSort(R, mid + 1, high);
    }
}