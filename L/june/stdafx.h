// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define IN 10000 //데이터 수

typedef struct Data {
	char input1[30];
	char input2[10];
	int  input3; //비교할 것
	//char vol[500]; //자료구조의 크기 조정
	//char vol[1000]; //자료구조의 크기 조정
}Data;

void insertion_sort(Data data[IN], int n);

void inc_insertion_sort(Data list[IN], int first, int last, int gap);
void shell_sort(Data list[IN], int size);

void QuickSort_1(Data list[IN], int num);
void QuickSort(Data list[IN], int num);

void Min_Heap(Data list[IN], int parm_start, int parm_count);
void Heap_Sort(Data list[IN], int parm_count);

void merge(Data list[IN], int left, int mid, int right);
void merge_sortt(Data list[IN], int left, int right);
void merge_sort(Data list[IN], int left, int right);

void radix_sort(Data list[IN], int n);

void displaySorting(Data want[IN], int first, int last);