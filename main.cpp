#include"iostream"
#include"SortTest.h"


using namespace std;
int main()
{
	SortTest arr = SortTest();

	int n = 3;//1为升序，2为降序，3为随机数组
	int num = 500;//数组长度
	int time = 10000;
	//double Time;
	////单个排序测试
	//arr.rChange(num, n);
	//cout << "前" << endl;
	//arr.PrintList();
	//Time = arr.InsertSort();
	//cout << "耗时"<< Time <<"s,直接插入排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//Time = arr.ShellSort();
	//cout << "耗时" << Time << "s,希尔排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//Time = arr.BubbleSort();
	//cout << "耗时" << Time << "s,起泡排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//Time = arr.TwoBubbleSort();
	//cout << "耗时" << Time << "s,双向起泡排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//arr.QuickSort(0,9);//递归算法未计时
	//cout << "快速排序排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//Time = arr.QuickSortUnrecursion();
	//cout << "耗时" << Time << "s,非递归快速排序排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//Time = arr.SelectSort();
	//cout << "耗时" << Time << "s,直接选择排序排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//Time = arr.HeapSort();
	//cout << "耗时" << Time << "s,堆排序排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//arr.MergeSortRecursion();
	//cout << "归并排序后" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\n前" << endl;
	//arr.PrintList();
	//Time = arr.MergeSortUnrecursion();
	//cout << "耗时" << Time << "s,非递归归并排序后" << endl;
	//arr.PrintList();

	//排序耗时比较,应为单次排序过快无法分辨，用循环多次排序计算耗时
	for (int i = 1; i <= 3; i++)
	{
		arr.TimePerformanceTest(num,time,i);
		cout << endl << endl;
	}
	return 0;
}