#ifndef GUARD_SORT_H
#define GUARD_SORT_H

typedef int ElemType;
void InsertionSort(ElemType A[], int N);
void ShellSort(ElemType A[], int N);
void PercDown(ElemType A[], int N, int i);
void HeapSort(ElemType A[], int N);
void MSort(ElemType A[], ElemType TmpArray[], int Left, int Right);
void Merge(ElemType A[], ElemType TmpArray[], int Lpos, int Rpos, int RightEnd);
void MergeSort(ElemType A[], int N);
void QuickSort(ElemType A[], int N);
ElemType Median3(ElemType A[], int Left, int Right);
void QSort(ElemType A[], int Left, int Right);
void QSelect(ElemType A[], int k, int Left, int Right);
void BucketSort(ElemType A[], int N);
void BubbleSort(ElemType A[], int N);


void Permute( ElemType A[ ], int N );
void Swap(ElemType *Lhs, ElemType *Rhs);
void Checksort( ElemType A[ ], int N );
void Copy( ElemType Lhs[ ], const ElemType Rhs[ ], int N );

#endif