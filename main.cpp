#include"iostream"
#include"SortTest.h"


using namespace std;
int main()
{
	SortTest arr = SortTest();

	int n = 3;//1Ϊ����2Ϊ����3Ϊ�������
	int num = 500;//���鳤��
	int time = 10000;
	//double Time;
	////�����������
	//arr.rChange(num, n);
	//cout << "ǰ" << endl;
	//arr.PrintList();
	//Time = arr.InsertSort();
	//cout << "��ʱ"<< Time <<"s,ֱ�Ӳ��������" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//Time = arr.ShellSort();
	//cout << "��ʱ" << Time << "s,ϣ�������" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//Time = arr.BubbleSort();
	//cout << "��ʱ" << Time << "s,���������" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//Time = arr.TwoBubbleSort();
	//cout << "��ʱ" << Time << "s,˫�����������" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//arr.QuickSort(0,9);//�ݹ��㷨δ��ʱ
	//cout << "�������������" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//Time = arr.QuickSortUnrecursion();
	//cout << "��ʱ" << Time << "s,�ǵݹ�������������" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//Time = arr.SelectSort();
	//cout << "��ʱ" << Time << "s,ֱ��ѡ�����������" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//Time = arr.HeapSort();
	//cout << "��ʱ" << Time << "s,�����������" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//arr.MergeSortRecursion();
	//cout << "�鲢�����" << endl;
	//arr.PrintList();

	//arr.rChange(num, n);
	//cout << "\nǰ" << endl;
	//arr.PrintList();
	//Time = arr.MergeSortUnrecursion();
	//cout << "��ʱ" << Time << "s,�ǵݹ�鲢�����" << endl;
	//arr.PrintList();

	//�����ʱ�Ƚ�,ӦΪ������������޷��ֱ棬��ѭ�������������ʱ
	for (int i = 1; i <= 3; i++)
	{
		arr.TimePerformanceTest(num,time,i);
		cout << endl << endl;
	}
	return 0;
}