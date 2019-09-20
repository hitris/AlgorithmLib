//
// Created by hitris on 2019-09-20.
//
// 合并排序
//
// 问题描述：给定一个由大量数据组成的数列，将其分解为很小的数列，直到只剩一个数时，本身已有序，再把这些有序的数列合并在一起，执行一个和分解相反的过程，从而完成整个数列的排序。
// 算法设计：合并排序时采用分治策略实现对n个元素进行排序的算法，是分治法的一个典型应用和完美体现。它是一种平衡、简单的二分分治策略，过程大致分为：
//          (1)分解：将待排序元素分成大小大致相同的两个子序列。
//          (2)治理：对两个子序列进行合并排序。
//          (3)合并：将排好序的有序子序列进行合并，得到最终的有序序列。
// 时间复杂度：O(nlogn) 空间复杂度：O(logn)

/**
 * 辅助合并函数
 * @param A 原数列
 * @param low 待合并的两个子序列在数组中的上届
 * @param mid 上届和下届的中间位置
 * @param high 待合并的两个子序列在数组中的下届
 */
void Merge(int A[], int low, int mid, int high) {
    int *B = new int[high - low + 1];//申请一个辅助数组B[]
    int i = low, j = mid + 1, k = 0;//i、j分别指向两个待排序子序列中当前待比较的元素，k指向辅助数组B[]中待放置元素的位置。
    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {//比较A[i]和A[j]，将较小的赋值给B[k]，同时响应指针向后移动
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    //循环结束，对剩余元素进行处理，直接放到B[]
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= high) {
        B[k++] = A[j++];
    }
    //将合并后的有序序列复制到原来的A[]序列
    for (i = low, k = 0; i < high; i++) {
        A[i] = B[k++];
    }
}

/**
 * 递归形式的合并排序算法
 * 将序列分为两个子序列，然后对子序列进行递归排序，再把两个已排好序的子序列合并成一个有序的序列。
 * @param A 原数列
 * @param low 数列排序开始位置
 * @param high 数列排序结束位置
 */
void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid, high);
        Merge(A, low, mid, high);
    }
}