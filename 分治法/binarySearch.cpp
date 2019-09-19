// 二分搜索技术
// 问题描述：给定n个元素，这些元素是有序的（假定为升序），从中查找特定元素x
// 算法思想：将有序序列分成规模大致相等的两部分，然后取中间元素与特定查找元素x进行比较，如果x等于中间元素，则查找成功，算法终止；
//         如果x小于中间元素，则在序列的前半部分继续查找，即在序列的前半部分重复分解和治理操作；否则，在序列的后半部分继续查找，
//          ，即在序列的后半部分重复分解和治理操作。
// 算法设计：用一维数组S[]存储该有序序列，设变量low和high表示查找范围的下届和上届，middle表示查找范围的中间位置，x为特定的查找元素
//          (1)初始化。令low=0，即指向有序数组S[]的第一个元素；high=n-1,即指向有序数组S[]的最后一个元素。
//          (2)middle=(low+high)/2,即指示查找范围的中间元素。
//          (3)判定low<high是否成立，如果成立，转第4部，否则，算法结束。
//          (4)判断x元S[middle]的关系。如果x=S[middle],则搜索成功，算法结束；如果x>S[middle]，则令low=middle+1;
//          否则令high=middle-1，转为第二步。

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;
const int M = 10000;
int x, n, i;
int s[M];

/**
 * while实现: 时间复杂度：O(logn) 空间复杂度：O(1)
 * @param n 元素个数
 * @param s 有序数组
 * @param x 特定查找元素
 * @return
 */
int BinarySearch(int n, int s[], int x) {
    int low = 0, high = n - 1;
    while (low < high) {
        int middle = (low + high) / 2;
        if (x == s[middle]) {
            return middle;
        } else if (x < s[middle]) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return -1;
}

int main() {
    cout << "请输入数列中的元素个数n为：";
    while (cin >> n) {
        cout << "请依次输入数列中的元素：";
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        sort(s, s + n);
        cout << "排序后的数组为：";
        for (int i = 0; i < n; ++i) {
            cout << s[i] << " ";
        }
        cout << endl;
        cout << "请输入要查找的元素：";
        cin >> x;
        i = BinarySearch(n, s, x);
        if (i == -1) {
            cout << "该数列中没有要查找的元素" << endl;
        } else {
            cout << "要查找的元素在第" << i + 1 << "位" << endl;
        }
    }
    return 0;
}

/**
 * 递归实现：时间复杂度：O(logn) 空间复杂度：O(logn)
 * @param s
 * @param x
 * @param low
 * @param high
 * @return
 */
int recursoinBS(int s[], int x, int low, int high) {
    if (low > high) {
        return -1;
    }
    int middle = (low + high) / 2;
    if (x == s[middle]) {
        return middle;
    } else if (x < s[middle]) {
        recursoinBS(s, x, low, middle - 1);
    } else {
        recursoinBS(s, x, middle + 1, high);
    }
}
//recursionBS(s[],x,0,n-1);