//
//  DZCommonAlgorithm.m
//  LJMster
//
//  Created by jiejie on 2020/2/28.
//  Copyright © 2020 jiejie. All rights reserved.
//

#import "DZCommonAlgorithm.h"

@implementation DZCommonAlgorithm

/*冒泡排序*/
+ (NSMutableArray *)bubbleSortWithArray:(NSMutableArray *)array{
    for (int i = 0; i < array.count; i++) {
        for (int j = 0; j<array.count-1-i; j++) {
            if ([array[j]integerValue] > [array[j+1] integerValue]) {
                [array exchangeObjectAtIndex:j withObjectAtIndex:j+1];
            }
        }
    }
    return  array ;
}

+(NSMutableArray *)bubbleSortWtihArray:(NSMutableArray *)array {
    for (int i = 0; i < array.count; i ++) {
        for (int j = 0; j < array.count - i -1; j++) {
            if ([array[j] integerValue] > [array[j+ 1] integerValue]) {
                [array exchangeObjectAtIndex:j withObjectAtIndex:j + 1] ;
            }
        }
    }
    return array ; 
}

- (void)selectionSortWithWithArray:(NSMutableArray *)array{
    for (int i = 0; i < array.count; i++) {
        for (int j = i+1; j<array.count; j++) {
            if ([array[i]integerValue] > [array[j] integerValue]) {
                [array exchangeObjectAtIndex:i withObjectAtIndex:j];
            }
        }
    }
}


/*快排**/
- (void)fastSortWithWithArray:(NSMutableArray *)array leftIndex:(NSInteger)leftIndex rightIndex:(NSInteger)rightIndex{
    if (leftIndex>= rightIndex) {
        /*如果数组长度我0,或1时 返回*/
        return;
    }
    /*去第一个下标为基数**/
    NSInteger flag =leftIndex;
    //取基准数
    NSInteger num = [array[flag] integerValue];
    
    
    while (flag <rightIndex) {
        
        /*从右边开始取出比基数小的值*/
        while (flag < rightIndex && [array[rightIndex] integerValue] >= num) {
            rightIndex--;
        }
        /*如果比基数小，查找到小值到最最左边位置*/
        array[flag] = array[rightIndex];
        
        
        /*从左边开始取出比基数大的值*/
        while (flag < rightIndex && [array[flag] integerValue] <= num) {
            flag++;
        }
        /*如果比基数大，则查找到最大值为最右边位置**/
        array[rightIndex]  = array[flag];
    }
    
    array[flag] = @(num);
    
    [self fastSortWithWithArray:array leftIndex:leftIndex rightIndex:flag-1];
    [self fastSortWithWithArray:array leftIndex:flag+1 rightIndex:rightIndex];
}


/*插入排序**/
- (void)insertSortWithArray:(NSMutableArray *)array{
    /*从第二个值开始*/
    for (int i = 1; i < array.count; i++) {
        /*记录下标*/
        int j = i;
        /*获取当前的值*/
        NSInteger temp = [array[i] integerValue];
        
        while (j > 0 &&temp < [array[j-1]integerValue]) {
            /*把大于temp的值放到temp位置*/
            [array replaceObjectAtIndex:j withObject:array[j-1]];
            j--;
        }
        //然后把temp的值放在前面的位置
        [array replaceObjectAtIndex:j withObject:[NSNumber numberWithInteger:temp]];
    }
}

/*堆排序*/
- (void)heapSortWithArray:(NSMutableArray *)array{
    NSInteger i, size;
    size = array.count;
    for (i = array.count/2-1; i>=0; i--) {
        [self creatBigHeapWithArray:array size:size beIndex:i];
    }
    while (size>0) {
        [array exchangeObjectAtIndex:size-1 withObjectAtIndex:0];
        size--;
        [self creatBigHeapWithArray:array size:size beIndex:0];
    }
    NSLog(@"堆排序%@",array);
}
/*生成一个堆**/
- (void)creatBigHeapWithArray:(NSMutableArray *)array size:(NSInteger) size beIndex:(NSInteger)element{
    /*左子树*/
    NSInteger leftChild = element*2+1;
    /*右子树*/
    NSInteger rightChild = leftChild+1;
    while (rightChild<size) {
        if (array[element]>= array[leftChild] &&array[element]>= array[rightChild]) {
            /*如果左右子树都大,完成整理*/
            return;
        }
        if (array[leftChild]> array[rightChild]) {
            /*如果左边的最大**/
            /*把左边的提到上面*/
            [array exchangeObjectAtIndex:element withObjectAtIndex:leftChild];
            element = leftChild;
        }else{
            [array exchangeObjectAtIndex:element withObjectAtIndex:rightChild];
            element = rightChild;
        }
        //重新计算子树位置
        leftChild = element*2+1;
        rightChild = leftChild+1;
    }
    //只有左子树且子树大于自己
    if (leftChild<size &&array[leftChild]>array[element]) {
        [array exchangeObjectAtIndex:leftChild withObjectAtIndex:element];
    }
}


@end
