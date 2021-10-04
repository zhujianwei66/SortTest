#ifndef SortTest_H
#define SortTest_H
const int MaxSize = 1000;//数组最大数量
class SortTest
{
	int r[MaxSize];//待排序数组
	int N;//数组大小
	int Partition(int first, int end);//快速排序一次划分算法
	void Sift(int k, int m);//筛选法调整堆算法
	void Merge(int r1[], int s, int m, int t);//一次归并算法
	void Swap(int& x, int& y);//两数交换
	int randEx();//随机数生成器
	void MergeSort(int r1[], int s, int t);//归并排序

public:
	SortTest();
	SortTest(int min ,int max, int size);//构造函数，生成size数量的(min~max)随机数组
	SortTest(int a[],int size);//生成指定数量（size）的已定数组a[]
	~SortTest() {}//析构函数
	//排序方法
	double InsertSort();//直接插入排序，升序
	double ShellSort();//希尔排序，升序
	double BubbleSort();//起泡排序，升序
	void QuickSort(int first, int end);//递归快速排序，升序
	double QuickSortUnrecursion(); //非递归快速排序，升序
	double SelectSort();//直接选择排序，升序
	double HeapSort();//堆排序，升序
	void MergeSortRecursion();//归并排序,升序
	double MergeSortUnrecursion(); //非递归归并排序,，升序
	double TwoBubbleSort();//双向冒泡排序，升序
	void PrintList();//输出数组
	void rChange(int len, int flag);//修改待排序数组
	void TimePerformanceTest(int len,int time,int mod);//测试排序时间性能
};

#endif