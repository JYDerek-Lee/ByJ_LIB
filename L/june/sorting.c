#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SWAP1(a, b) { int t; t = a; a = b; b = t; }
#define SWAP(x,y,z) ( (z)=(x), (x)=(y), (y)=(z) );
#define MAX 150000
#define BUCKETS 10
#define DIGITS 4
#define IN 10000 //������ ��
#define Check_Vol
#define TXT "output.txt"

#ifdef Check_Data
// �ذṮ�� 1�� �ڷᱸ��
typedef struct Data {
	char input1[30];
	char input2[10];
	int  input3; //���Ұ�
}Data;
#endif

#ifdef Check_Vol
// �ذṮ�� 2�� �ڷᱸ��
typedef struct Data {
	char input1[30];
	char input2[10];
	int  input3; //���� ��
	//char vol[500]; //�ڷᱸ���� ũ�� ����
	//char vol[1000]; //�ڷᱸ���� ũ�� ����
}Data;
#endif

clock_t start_time, end_time;


//1. ���� ���� �Լ�
void insertion_sort(Data data[IN], int n) {
	int i, j, key;
	FILE *wfp = fopen(TXT, "w");
	start_time = clock();

	//���� �� �� ����
	for (i = 1; i<n; i++) {
		key = data[i].input3;
		// ������ ��ġ�� ����
		for (j = i - 1; j >= 0 && data[j].input3>key; j--) {
			data[j + 1].input3 = data[j].input3;
		}
		data[j + 1].input3 = key;
	}
	end_time = clock();
	fprintf(wfp, "%d���� [���� ����] �Ҹ� �ð�  : %f �Դϴ�.\n", n, ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
	fclose(wfp);
}


//2. �� ���� �Լ�
void inc_insertion_sort(Data list[IN], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i].input3;
		for (j = i - gap; j >= first && key<list[j].input3; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap].input3 = key;
	}
}
void shell_sort(Data list[IN], int n) {   // n = size
	int i, gap;
	FILE *wfp = fopen(TXT, "w");
	start_time = clock();

	for (gap = n / 2; gap>0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i<gap; i++)      // �κ� ����Ʈ�� ������ gap
			inc_insertion_sort(list, i, n - 1, gap);
	}
	end_time = clock();
	fprintf(wfp, "%d���� [�� ����] �Ҹ� �ð�  : %f �Դϴ�.\n", IN, ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
	fclose(wfp);
}


//3. �� ���� �Լ�
void QuickSort_1(Data list[IN], int num) {
	int left, right;
	Data key;

	if (num <= 1) return;

	key.input3 = list[num - 1].input3;
	for (left = 0, right = num - 2;; left++, right--) {
		while (list[left].input3 < key.input3) left++;
		while (list[right].input3 > key.input3) right--;
		if (left >= right) break;
		SWAP1(list[left].input3, list[right].input3);
	}
	SWAP1(list[left].input3, list[num - 1].input3);
	QuickSort_1(list, left);
	QuickSort_1(list + left + 1, num - left - 1);

}
void QuickSort(Data list[IN], int num) {
	FILE *wfp = fopen(TXT, "w");
	start_time = clock();

	QuickSort_1(list, num);

	end_time = clock();
	fprintf(wfp, "%d���� [�� ����] �Ҹ� �ð�  : %f �Դϴ�.\n", IN, ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
	fclose(wfp);
}


//4. ���� ����
void Min_Heap(Data list[IN], int parm_start, int parm_count) {
	int node_left, node_right, node_current, node_start, node_index, temp = 0;

	if (parm_count - parm_start < 2) return;
	node_current = parm_start;

	while (node_current >= 0) {
		node_index = node_current;
		node_start = node_current;
		while (node_start * 2 + 1 < parm_count) {
			node_left = node_start * 2 + 1;
			node_right = node_start * 2 + 2;
			node_start = node_left;

			if (node_right < parm_count && list[node_right].input3 >= list[node_left].input3) {
				node_start = node_right;
			}
			if (list[node_start].input3 > list[node_index].input3) {
				SWAP(list[node_index].input3, list[node_start].input3, temp);
				node_index = node_start;
			}
		}
		--node_current;
	}
}
void Heap_Sort(Data list[IN], int parm_count) {
	int temp = 0;
	FILE *wfp = fopen(TXT, "w");
	start_time = clock();

	Min_Heap(list, parm_count / 2 - 1, parm_count);
	while (parm_count > 0) {
		--parm_count;
		SWAP(list[0].input3, list[parm_count].input3, temp);
		Min_Heap(list, 0, parm_count);
	}
	end_time = clock();
	fprintf(wfp, "%d���� [��������] �Ҹ� �ð�  : %f �Դϴ�.\n", IN, ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
	fclose(wfp);
}


//5. �պ� ����
int sorted[MAX] = { 0 }; // �߰� ������ �ʿ�
// i�� ���ĵ� ���ʸ���Ʈ�� ���� �ε���
// j�� ���ĵ� �����ʸ���Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε���
void merge(Data list[IN], int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i].input3 <= list[j].input3) sorted[k++] = list[i++].input3;
		else sorted[k++] = list[j++].input3;
	}
	if (i>mid)    // ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++)
			sorted[k++] = list[l].input3;
	else    // ���� �ִ� ���ڵ��� �ϰ� ����r
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l].input3;
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
	for (l = left; l <= right; l++)
		list[l].input3 = sorted[l];
}
void merge_sortt(Data list[IN], int left, int right) {
	int mid;
	if (left<right) {
		mid = (left + right) / 2;    // ����Ʈ�� �յ� ����
		merge_sortt(list, left, mid);    // �κи���Ʈ ����
		merge_sortt(list, mid + 1, right);//�κи���Ʈ ����
		merge(list, left, mid, right);   // �պ�
	}
}
void merge_sort(Data list[IN], int left, int right) {
	FILE *wfp = fopen(TXT, "w");
	start_time = clock();

	merge_sortt(list, left, right);

	end_time = clock();
	fprintf(wfp, "%d���� [�պ� ����] �Ҹ� �ð�  : %f �Դϴ�.\n", IN, ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
	fclose(wfp);
}


//6. ��� ����
typedef struct QueueNode {
	int item;
	struct QueueNode *link;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
}QueueType;

void init(QueueType *q) {
	q->front = q->rear = NULL;
}

int is_empty(QueueType *q) {
	return (q->front == NULL);
}

int enqueue(QueueType *q, int item) {
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));

	temp->item = item;
	temp->link = NULL;

	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}
int dequeue(QueueType *q) {
	QueueNode *temp = q->front;
	int item;

	if (is_empty(q)) {
		printf("ť�� ����ֽ��ϴ�\n");
		return -1;
	}

	item = temp->item;
	q->front = q->front->link;

	if (q->front == NULL)
		q->rear = NULL;

	free(temp);

	return item;
}

void radix_sort(Data list[IN], int n) {
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	FILE *wfp = fopen(TXT, "w");
	start_time = clock();

	for (b = 0; b<BUCKETS; b++) init(&queues[b]);   // ť���� �ʱ�ȭ

	for (d = 0; d<DIGITS; d++) {
		for (i = 0; i<n; i++)            // �����͵��� �ڸ����� ���� ť�� �Է�
			enqueue(&queues[(list[i].input3 / factor) % 10], list[i].input3);

		for (b = i = 0; b<BUCKETS; b++)         // ���Ͽ��� ������ list�� ��ģ��.
			while (!is_empty(&queues[b]))
				list[i++].input3 = dequeue(&queues[b]);
		factor *= 10;            // �� ���� �ڸ����� ����.
	}
	end_time = clock();
	fprintf(wfp, "%d���� [��� ����] �Ҹ� �ð�  : %f �Դϴ�.\n", IN, ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
	fclose(wfp);
}



// ����Լ� =====================================================================
void displaySorting(Data want[IN], int first, int last) {
	int j = 0;
	FILE *wfp = fopen(TXT, "a");

	fprintf(stderr, "\n-------- %d�� �ֻ��� %d�� --------\n", IN, last - first + 1);
	fprintf(wfp, "\n-------- %d�� �ֻ��� %d�� --------\n", IN, last - first + 1);
	for (j = first; j <= last; j++) {
		fprintf(stderr, "%s   %s   %d\n", want[j].input1, want[j].input2, want[j].input3);
		fprintf(wfp, "%s   %s   %d\n", want[j].input1, want[j].input2, want[j].input3);
	}
	fprintf(stderr, "------------------------------------\n\n");
	fprintf(wfp, "------------------------------------\n\n");
	fclose(wfp);
	system("output.txt");
}


// ���� ==========================================================================
void main() {
	FILE *rfp = fopen("input.tsv", "r");

	int i = 0, k = 0;
	char temp[100];
	Data data[IN] = { 0 };

	if (rfp == NULL) {
		printf("<ERROR> file open failed \n");
	}
	else {
		while (k<IN) {
			fscanf(rfp, "%s %s %s", data[k].input1, data[k].input2, temp);
			data[k].input3 = atoi(temp);
			k++;
		}
	}
	fclose(rfp);

	//insertion_sort(data,IN);
	//shell_sort(data, IN);
	//QuickSort(data, IN);
	//Heap_Sort(data, IN);
	//merge_sort(data,0,IN-1);
	radix_sort(data, IN);

	displaySorting(data, 1, 5);
}