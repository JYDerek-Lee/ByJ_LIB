#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SWAP1(a, b) { int t; t = a; a = b; b = t; }
#define SWAP(x,y,z) ( (z)=(x), (x)=(y), (y)=(z) );
#define MAX 150000
#define BUCKETS 10
#define DIGITS 4
#define IN 300000 //데이터 수
#define Check_Vol
#define TXT "output.txt"

#ifdef Check_Data
typedef struct Data {
	char input1[30];
	char input2[10];
	int  input3; //비교할것
}Data;
#endif

#ifdef Check_Vol
typedef struct Data {
	char input1[30];
	char input2[10];
	int  input3; //비교할 것
	//char vol[500]; //자료구조의 크기 조정
	//char vol[1000]; //자료구조의 크기 조정
}Data;
#endif


void insertion_sort(Data data[IN], int n);
void shell_sort(Data list[IN], int n);
void QuickSort(Data list[IN], int num);
void Heap_Sort(Data list[IN], int parm_count);
void merge(Data list[IN], int left, int mid, int right);
void radix_sort(Data list[IN], int n);