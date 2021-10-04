#include"iostream"
#include "cstdlib"
#include "ctime"
#include"Windows.h"
#include <stack>//实现快速排序非递归
using namespace std;
#include"SortTest.h"


//随机数生成器，微秒为单位的时间种子
int SortTest::randEx()
{
	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);
	srand(seed.QuadPart);
	return rand();
}
//两数交换
void SortTest::Swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
//修改r数组
void SortTest::rChange(int len,int flag)
{
	N = len;
	if (flag == 1)//升序
	{
		for (int i = 0; i < len; i++)r[i] = i + 1;
	}
	if (flag == 2)//降序
	{
		for (int i = len; i > 0; i--)r[i - 1] = len-i+1;
	}
	if (flag == 3)
	{
		//生成范围在1~100的随机数 
		for (int i = 0; i < N; i++) {
			r[i] = randEx() % (100 - 1 + 1) + 1;//生成区间100~1的随机数 
		}
	}
}
//输出指定长度的数组a
void SortTest::PrintList()
{
	for (int i = 0; i < N; i++)
		cout << r[i] << " ";
	cout << endl;
}


//数据生成模块
//无参构造函数
SortTest::SortTest()
{
	/// <summary>
	/// 无参构造函数，生成支持的最大长度全0数组
	/// </summary>
	N = MaxSize;
	for (int i = 0; i < N; i++)
	{
		r[i] = 0;
	}
}
//构造函数
SortTest::SortTest(int a[], int size)
{
	/// <summary>
	/// 生成指定数组
	/// </summary>
	/// <param name="a">要生成的指定数组</param>
	/// <param name="size">数组长度</param>
	if (size > MaxSize) throw"超出数组上限";
	N = size;
	for (int i = 1; i < N; i++)
	{
		r[i] = a[i];
	}
}

//构造函数,生成随机数组
SortTest::SortTest(int min, int max, int size)
{
	/// <summary>
	/// 生成随机数组
	/// </summary>
	/// <param name="min">随机数最小值</param>
	/// <param name="max">随机数最大值</param>
	/// <param name="max">数组大小</param>
	//生成范围在max~min的随机数 
	N = size;
	for (int i = 0; i < N; i++) {
		r[i] = randEx() % (max - min + 1) + min;//生成区间max~min的随机数 
	}
}


//排序实现模块
//直接插入排序
double SortTest::InsertSort()
{
	/// <summary>
	/// 把记录分为有序和无序区，初始时把无序区第一个元素作为有序区
	/// 无序区按顺序插入有序区中
	/// </summary>
	/// <returns>程序用时</returns>

	double Time, startTime, endTime;
	startTime = clock();//计时开始


	int i, j;
	int temp;//暂存单元
	for (i = 1; i < N; i++)
	{
		temp = r[i];				//暂存关键码
		for (j = i - 1; j >= 0 && temp < r[j]; j--)//寻找插入位置
			r[j + 1] = r[j];//记录后移
		r[j + 1] = temp;
	}


	endTime = clock();//计时结束
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//希尔排序
double SortTest::ShellSort()
{
	/// <summary>
	/// 把序列划分为若干个子序列，对子序列进行插入排序
	/// </summary>
	/// <returns>程序用时</returns>
	double Time, startTime, endTime;
	startTime = clock();//计时开始

	int d, i, j;
	int temp;
	for (d = N / 2; d >= 1; d = d / 2)
	{
		for (i = d; i < N; i++)
		{
			temp = r[i];
			for (j = i - d; j >= 0 && temp < r[j]; j = j - d)
				r[j + d] = r[j];
			r[j + d] = temp;
		}
	}

	endTime = clock();//计时结束
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//起泡排序
double SortTest::BubbleSort()
{
	/// <summary>
	/// 起泡排序
	/// </summary>
	/// <returns>程序用时</returns>
	double Time, startTime, endTime;
	startTime = clock();//计时开始


	int exchange, bound;
	exchange = N;
	while (exchange != 0)
	{
		bound = exchange;
		exchange = 0;
		for (int j = 0; j < bound - 1; j++)
		{
			if (r[j] > r[j + 1])
			{
				Swap(r[j], r[j + 1]);
				exchange = j+1;
			}
		}
	}

	endTime = clock();//计时结束
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//快速排序，需要给数组索引值
int SortTest::Partition(int first, int end)
{
	/// <summary>
	/// 一次划分,以第一个数组元素为基准,
	/// 大于等于该基准的值放置组数右侧,
	/// 小于该基准的值放置数组左侧,
	/// 最后该基准放置于中间位置。
	/// </summary>
	/// <param name="first">待排序数组首位索引</param>
	/// <param name="end">待排序数组末位索引</param>
	/// <returns>轴值最终位置</returns>
	int i, j;
	i = first;
	j = end;
	while (i < j)
	{
		while (i < j && r[i] <= r[j])j--;
		if (i < j)
		{
			Swap(r[j], r[i]);
		}
		while (i < j && r[i] <= r[j])i++;
		if (i < j)
		{
			Swap(r[j], r[i]);
		}
	}
	return i;
}
void SortTest::QuickSort(int first, int end)//递归实现
{
	/// <summary>
	/// 快速排序
	/// </summary>
	/// <param name="first">待排序数组首位索引</param>
	/// <param name="end">待排序数组末位索引</param>
	int pivot;
	if (first < end)
	{
		pivot = Partition(first, end);
		QuickSort(first, pivot - 1);
		QuickSort(pivot + 1, end);
	}
}
//快速排序非递归实现
double SortTest::QuickSortUnrecursion()
{
	/// <summary>
	/// 快速排序非递归实现
	/// </summary>
	/// <returns>程序用时</returns>
	double Time, startTime, endTime;
	startTime = clock();//计时开始
	int first = 0, end = N-1;

	stack<int> stackIndex;
	stackIndex.push(first);
	stackIndex.push(end);
	int nBegin = 0;
	int nEnd = 0;
	int nMid = 0;
	while (!stackIndex.empty())
	{
		nEnd = stackIndex.top();
		stackIndex.pop();
		nBegin = stackIndex.top();
		stackIndex.pop();
		nMid = Partition(nBegin, nEnd);
		if (nBegin < nMid - 1)
		{
			stackIndex.push(nBegin);
			stackIndex.push(nMid - 1);
		}
		if (nEnd > nMid + 1)
		{
			stackIndex.push(nMid + 1);
			stackIndex.push(nEnd);
		}
	}

	endTime = clock();//计时结束
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//直接选择排序
double SortTest::SelectSort()
{
	/// <summary>
	/// 直接选择排序
	/// </summary>
	double Time, startTime, endTime;
	startTime = clock();//计时开始


	int i, index, j;
	for (i = 0; i <= N - 1; i++)
	{
		index = i;
		for (j = i + 1; j < N; j++)
			if (r[j] < r[index])index = j;
		if (index != i)
		{
			Swap(r[i], r[index]);
		}
	}

	endTime = clock();//计时结束
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//堆排序
//筛选法调整堆算法
void SortTest::Sift(int k, int m)
{
	/// <summary>
	/// 筛选法调整堆
	/// </summary>
	/// <param name="k">为筛选节点</param>
	/// <param name="m">堆的末位</param>
	int i, j;
	i = k; j = 2 * i + 1;//i为筛选节点，j为i的左孩子
	while (j < m)
	{
		if (j + 1 < m && r[j] < r[j + 1])j++;//取值最大的孩子
		if (r[i] > r[j]) break;//比较筛选节点的值与最大孩子的值，取最大值为根节点
		else {
			Swap(r[i], r[j]);
			i = j; j = 2 * i + 1;
		}
	}
}
//堆排序算法
double SortTest::HeapSort()
{
	/// <summary>
	/// 堆排序
	/// </summary>
	/// <returns>程序用时</returns>
	double Time, startTime, endTime;
	startTime = clock();//计时开始


	for (int i = N / 2 - 1; i >= 0; i--)//初建堆，从最后一个分支结点到根结点
		Sift(i, N);
	for (int i = 0; i < N; i++)
	{
		int tmp = r[0];
		r[0] = r[N - i - 1];
		r[N - i - 1] = tmp;//把堆顶移动到有序区
		Sift(0, N - i - 1);//除去有序区，重建堆
	}

	endTime = clock();//计时结束
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//归并排序
//一次归并算法
void SortTest::Merge(int r1[], int s, int m, int t)
{
	/// <summary>
	/// 一次归并
	/// </summary>
	/// <param name="r1">一个足够长的数组</param>
	/// <param name="s">第一个子列的首位</param>
	/// <param name="m">第二个子列的首位</param>
	/// <param name="t">第二个子列的末位</param>
	int nBegin = s;
	int nEnd = t;
	int nIndex1 = s;
	int nMid = m;
	int nIndex2 = nMid + 1;
	while (nBegin <= nEnd)
	{
		if (nIndex1 <= nMid && nIndex2 <= t)
		{
			if (r[nIndex1] <= r[nIndex2])
			{
				r1[nBegin++] = r[nIndex1++];
			}
			else
			{
				r1[nBegin++] = r[nIndex2++];
			}
		}
		else if (nIndex1 <= nMid)
		{
			r1[nBegin++] = r[nIndex1++];
		}
		else if (nIndex2 <= t)
		{
			r1[nBegin++] = r[nIndex2++];
		}
	}
	//排序完修改原数组
	for (int i = s; i <= t; i++)
	{
		r[i] = r1[i];
	}
}
//归并排序递归算法
void SortTest::MergeSort(int r1[], int s, int t)
{
	/// <summary>
	/// 归并排序递归算法
	/// </summary>
	/// <param name="r1">一个足够长的数组</param>
	/// <param name="s">数组首位索引</param>
	/// <param name="t">数组末位索引</param>
	if (s >= t)return;//当待排序列只有一位，直接记录在r1中，并且结束递归
	else {
		int m = (s + t) / 2;//对半划分
		MergeSort(r1, s, m);//左边待排序列归并
		MergeSort(r1, m+1, t);//右边待排序列归并
		Merge(r1, s, m, t);//将两个子序列归并
	}
}
void SortTest::MergeSortRecursion()
{
	if (N <= 0)
	{
		return;
	}
	int* r1 = new int[N];
	MergeSort(r1,0, N - 1);
	delete[] r1;
}
//归并排序非递归算法
double SortTest::MergeSortUnrecursion()
{
	/// <summary>
	/// 归并排序非递归算法
	/// </summary>
	/// <returns>程序用时</returns>
	double Time, startTime, endTime;
	startTime = clock();//计时开始


	if (N <= 0)
	{
		return -1;
	}
	int nLength = N;
	int* r1 = new int[nLength];
	int nSize = 1;//分出的最小组  
	while (nSize <= nLength)
	{
		int nBegin = 0;
		int nMid = 0;
		int nEnd = 0;
		while (nEnd < nLength - 1)
		{
			nMid = nBegin + nSize-1;
			nEnd = nMid + nSize;
			if (nEnd >= nLength)
			{
				nEnd = nLength - 1;
			}
			Merge(r1, nBegin, nMid, nEnd);
			nBegin = nEnd + 1;
		}
		nSize *= 2;
	}
	delete[] r1;

	endTime = clock();//计时结束
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//双向冒泡排序
double SortTest::TwoBubbleSort()
{	
	/// <summary>
	/// 双向冒泡排序，以正向冒泡排序，逆向冒泡排序为一趟排序
	/// </summary>
	/// <returns>程序用时</returns>
	double Time, startTime, endTime;
	startTime = clock();//计时开始


	int left = 0,right = N - 1;//有序标签
	int shift = 1;//两端已排序的元素位置

	while (left < right) { // 往右排序
		for (int i = left; i < right; i++) {
			if (r[i] > r[i + 1]) { // 第一个数比第二个数大，交换
				Swap(r[i], r[i + 1]);
				shift = i;
			}
		}
		right = shift;
		for (int i = right - 1; i >= left; i--) { // 向左排序
			if (r[i] > r[i + 1]) { // 第一个数比第二个数大，交换
				Swap(r[i], r[i + 1]);
				shift = i + 1;
			}
		}
		left = shift;
	}

	endTime = clock();//计时结束
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}


//时间性能测试模块
void SortTest::TimePerformanceTest(int len, int time, int mod)
{
	/// <summary>
	/// 测试直接插入排序、希尔排序、起泡排序、
	/// 快速排序、直接选择排序、堆排序和归并排序的时间性能
	/// </summary>
	/// <param name="len">排序数组长度，应该小于或等于100</param>
	/// <param name="time">循环排序次数</param>
	/// <param name="mod">生成数组的模式选择，1为升序，2为降序，3为随机数组</param>
	double startTime = clock();//计时开始
	for (int i = 0; i <= time; i++)
	{
		//cout << "初始数组" << endl;
		rChange(len, mod);
		//PrintList();
		TwoBubbleSort();
		//cout << "排序后数组" << endl;
		//PrintList();
	}
	double endTime = clock();//计时结束
	double Time = endTime - startTime;
	cout << "双向冒泡排序耗时：" << Time / CLOCKS_PER_SEC << "s" << endl;
	//-----------------------------------------------------
	startTime = clock();//计时开始
	for (int i = 0; i <= time; i++)
	{
		//cout << "初始数组" << endl;
		rChange(len, mod);
		//PrintList();
		InsertSort();
		//cout << "排序后数组" << endl;
		//PrintList();
	}
	endTime = clock();//计时结束
	Time = endTime - startTime;
	cout << "直接插入排序耗时：" << Time / CLOCKS_PER_SEC << "s" << endl;
	//-----------------------------------------------------
	startTime = clock();//计时开始
	for (int i = 0; i <= time; i++)
	{
		//cout << "初始数组" << endl;
		rChange(len, mod);
		//PrintList();
		ShellSort();
		//cout << "排序后数组" << endl;
		//PrintList();
	}
	endTime = clock();//计时结束
	Time = endTime - startTime;
	cout << "希尔排序耗时：" << Time / CLOCKS_PER_SEC << "s" << endl;
	//-----------------------------------------------------
	startTime = clock();//计时开始
	for (int i = 0; i <= time; i++)
	{
		//cout << "初始数组" << endl;
		rChange(len, mod);
		//PrintList();
		BubbleSort();
		//cout << "排序后数组" << endl;
		//PrintList();
	}
	endTime = clock();//计时结束
	Time = endTime - startTime;
	cout << "起泡排序耗时：" << Time / CLOCKS_PER_SEC << "s" << endl;

	//-----------------------------------------------------
	startTime = clock();//计时开始
	for (int i = 0; i <= time; i++)
	{
		//cout << "初始数组" << endl;
		rChange(len, mod);
		//PrintList();
		QuickSort(0,N-1);
		//cout << "排序后数组" << endl;
		//PrintList();
	}
	endTime = clock();//计时结束
	Time = endTime - startTime;
	cout << "快速排序耗时：" << Time / CLOCKS_PER_SEC << "s" << endl;


	//-----------------------------------------------------
	startTime = clock();//计时开始
	for (int i = 0; i <= time; i++)
	{
		//cout << "初始数组" << endl;
		rChange(len, mod);
		//PrintList();
		SelectSort();//直接选择排序
		//cout << "排序后数组" << endl;
		//PrintList();
	}
	endTime = clock();//计时结束
	Time = endTime - startTime;
	cout << "直接选择排序耗时：" << Time / CLOCKS_PER_SEC << "s" << endl;


	//-----------------------------------------------------
	startTime = clock();//计时开始
	for (int i = 0; i <= time; i++)
	{
		//cout << "初始数组" << endl;
		rChange(len, mod);
		//PrintList();
		HeapSort();//堆排序
		//cout << "排序后数组" << endl;
		//PrintList();
	}
	endTime = clock();//计时结束
	Time = endTime - startTime;
	cout << "堆排序耗时：" << Time / CLOCKS_PER_SEC << "s" << endl;

	//-----------------------------------------------------
	int r1[MaxSize] = { 0 };
	startTime = clock();//计时开始
	for (int i = 0; i <= time; i++)
	{
		//cout << "初始数组" << endl;
		rChange(len, mod);
		//PrintList();
		MergeSort(r1,0,N);//归并排序
		//cout << "排序后数组" << endl;
		//PrintList();
	}
	endTime = clock();//计时结束
	Time = endTime - startTime;
	cout << "归并排序耗时：" << Time / CLOCKS_PER_SEC << "s" << endl;
}