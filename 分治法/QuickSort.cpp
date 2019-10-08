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

/*
 * 交换序列中两个元素的位置
 */
void swap(int a, int b) {}

int Partition(int r[], int low, int high) {//划分函数
    int i = low, j = high, pivot = r[low];//基准元素
    while (i < j) {
        while (i < j && r[j] > pivot)
            j--;//向左扫描
        if (i < j) {
            swap(r[i++], r[j]);//r[i]和r[j]交换后i右移一位
        }
        while (i < j && r[i] <= pivot)
            i++;//向右扫描
        if (i < j) {
            swap(r[i], r[j--]);//r[i]和r[j]交换后j左移一位
        }
    }
    return i;//返回最终划分完成后基准元素所在位置
}

void QuickSort(int R[], int low, int high) {
    int mid;
    if (low < high) {
        mid = Partition(R, low, high);
        QuickSort(R, low, mid - 1);
        QuickSort(R, mid + 1, high);
    }
}


/**
 * 优化：Partition每次交换都是在和基准元素进行交换
 * 我们的目的就是想把原序列分成以基准元素为届的两个子序列，左侧子序列小于等于基准元素，右侧子序列大于基准元素。
 * 那么有很多方法可以实现，我们可以从右向左扫描，找小于等于pivot的数R[j]，然后从左向右扫描，找大于pivot的数R[i],
 * 让R[i]和R[j]交换，一直交替进行，直到i和j碰头为止，这时将基准元素与R[i]交换即可。这样就完成了一次划分过程，但交换元素的个数少了很多。
 * @param r
 * @param low
 * @param high
 * @return
 */
int Partition2(int r[], int low, int high) {
    int i = low, j = high, pivot = r[low];//基准元素
    while (i < j) {
        while (i < j && r[j] > pivot) j--;//向左扫描
        while (i < j && r[i] <= pivot) i++;//向右扫描
        if (i < j) {
            swap(r[i++], r[j--]);//r[i]和r[j]交换，交换后i++,j--
        }
    }
    if (r[i] > pivot) {
        swap(r[i - 1], r[low]);//r[i-1]和r[low]交换
        return i - 1;//返回最终划分完成后基准元素所在位置
    }
    swap(r[i], r[low]);//r[i]和r[low]交换
    return i;//返回最终划分完成后基准元素所在位置
}