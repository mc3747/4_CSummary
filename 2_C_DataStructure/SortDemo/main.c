//
//  main.c
//  SortDemo
//
//  Created by kk on 2021/5/7.
//
/*
 普通参考：https://zhuanlan.zhihu.com/p/102420855
 优化参考：https://zhuanlan.zhihu.com/p/89330236
 分类总结：https://juejin.cn/post/6956624975600025613#heading-16
 */
#include <stdio.h>
#include"sort1.h"
#include<time.h>
#include<string.h>

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int arr[15];
    for (int i = 0; i < 15; i++)
    {
        arr[i] = rand() % 120;
    }
    show(arr, 15);
    //冒泡排序
    BubbleSort(arr, 15);
    //SelectSort(arr, 15);
    //InsertSort(arr, 15);
    //QuickSort(arr, 0, 14);
    //ShellSort(arr, 15);
    //MergeSort(arr, 0, 14);
    //radix_sort(arr, 15);
//    show(arr, 15);
//    getchar();
    
    show(arr, 15);
    return 0;
}


