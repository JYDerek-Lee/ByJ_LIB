// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define IN 10000 //������ ��

typedef struct Data {
	char input1[30];
	char input2[10];
	int  input3; //���� ��
	//char vol[500]; //�ڷᱸ���� ũ�� ����
	//char vol[1000]; //�ڷᱸ���� ũ�� ����
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