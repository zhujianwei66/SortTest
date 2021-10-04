#ifndef SortTest_H
#define SortTest_H
const int MaxSize = 1000;//�����������
class SortTest
{
	int r[MaxSize];//����������
	int N;//�����С
	int Partition(int first, int end);//��������һ�λ����㷨
	void Sift(int k, int m);//ɸѡ���������㷨
	void Merge(int r1[], int s, int m, int t);//һ�ι鲢�㷨
	void Swap(int& x, int& y);//��������
	int randEx();//�����������
	void MergeSort(int r1[], int s, int t);//�鲢����

public:
	SortTest();
	SortTest(int min ,int max, int size);//���캯��������size������(min~max)�������
	SortTest(int a[],int size);//����ָ��������size�����Ѷ�����a[]
	~SortTest() {}//��������
	//���򷽷�
	double InsertSort();//ֱ�Ӳ�����������
	double ShellSort();//ϣ����������
	double BubbleSort();//������������
	void QuickSort(int first, int end);//�ݹ������������
	double QuickSortUnrecursion(); //�ǵݹ������������
	double SelectSort();//ֱ��ѡ����������
	double HeapSort();//����������
	void MergeSortRecursion();//�鲢����,����
	double MergeSortUnrecursion(); //�ǵݹ�鲢����,������
	double TwoBubbleSort();//˫��ð����������
	void PrintList();//�������
	void rChange(int len, int flag);//�޸Ĵ���������
	void TimePerformanceTest(int len,int time,int mod);//��������ʱ������
};

#endif