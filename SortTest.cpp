#include"iostream"
#include "cstdlib"
#include "ctime"
#include"Windows.h"
#include <stack>//ʵ�ֿ�������ǵݹ�
using namespace std;
#include"SortTest.h"


//�������������΢��Ϊ��λ��ʱ������
int SortTest::randEx()
{
	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);
	srand(seed.QuadPart);
	return rand();
}
//��������
void SortTest::Swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
//�޸�r����
void SortTest::rChange(int len,int flag)
{
	N = len;
	if (flag == 1)//����
	{
		for (int i = 0; i < len; i++)r[i] = i + 1;
	}
	if (flag == 2)//����
	{
		for (int i = len; i > 0; i--)r[i - 1] = len-i+1;
	}
	if (flag == 3)
	{
		//���ɷ�Χ��1~100������� 
		for (int i = 0; i < N; i++) {
			r[i] = randEx() % (100 - 1 + 1) + 1;//��������100~1������� 
		}
	}
}
//���ָ�����ȵ�����a
void SortTest::PrintList()
{
	for (int i = 0; i < N; i++)
		cout << r[i] << " ";
	cout << endl;
}


//��������ģ��
//�޲ι��캯��
SortTest::SortTest()
{
	/// <summary>
	/// �޲ι��캯��������֧�ֵ���󳤶�ȫ0����
	/// </summary>
	N = MaxSize;
	for (int i = 0; i < N; i++)
	{
		r[i] = 0;
	}
}
//���캯��
SortTest::SortTest(int a[], int size)
{
	/// <summary>
	/// ����ָ������
	/// </summary>
	/// <param name="a">Ҫ���ɵ�ָ������</param>
	/// <param name="size">���鳤��</param>
	if (size > MaxSize) throw"������������";
	N = size;
	for (int i = 1; i < N; i++)
	{
		r[i] = a[i];
	}
}

//���캯��,�����������
SortTest::SortTest(int min, int max, int size)
{
	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="min">�������Сֵ</param>
	/// <param name="max">��������ֵ</param>
	/// <param name="max">�����С</param>
	//���ɷ�Χ��max~min������� 
	N = size;
	for (int i = 0; i < N; i++) {
		r[i] = randEx() % (max - min + 1) + min;//��������max~min������� 
	}
}


//����ʵ��ģ��
//ֱ�Ӳ�������
double SortTest::InsertSort()
{
	/// <summary>
	/// �Ѽ�¼��Ϊ���������������ʼʱ����������һ��Ԫ����Ϊ������
	/// ��������˳�������������
	/// </summary>
	/// <returns>������ʱ</returns>

	double Time, startTime, endTime;
	startTime = clock();//��ʱ��ʼ


	int i, j;
	int temp;//�ݴ浥Ԫ
	for (i = 1; i < N; i++)
	{
		temp = r[i];				//�ݴ�ؼ���
		for (j = i - 1; j >= 0 && temp < r[j]; j--)//Ѱ�Ҳ���λ��
			r[j + 1] = r[j];//��¼����
		r[j + 1] = temp;
	}


	endTime = clock();//��ʱ����
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//ϣ������
double SortTest::ShellSort()
{
	/// <summary>
	/// �����л���Ϊ���ɸ������У��������н��в�������
	/// </summary>
	/// <returns>������ʱ</returns>
	double Time, startTime, endTime;
	startTime = clock();//��ʱ��ʼ

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

	endTime = clock();//��ʱ����
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//��������
double SortTest::BubbleSort()
{
	/// <summary>
	/// ��������
	/// </summary>
	/// <returns>������ʱ</returns>
	double Time, startTime, endTime;
	startTime = clock();//��ʱ��ʼ


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

	endTime = clock();//��ʱ����
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//����������Ҫ����������ֵ
int SortTest::Partition(int first, int end)
{
	/// <summary>
	/// һ�λ���,�Ե�һ������Ԫ��Ϊ��׼,
	/// ���ڵ��ڸû�׼��ֵ���������Ҳ�,
	/// С�ڸû�׼��ֵ�����������,
	/// ���û�׼�������м�λ�á�
	/// </summary>
	/// <param name="first">������������λ����</param>
	/// <param name="end">����������ĩλ����</param>
	/// <returns>��ֵ����λ��</returns>
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
void SortTest::QuickSort(int first, int end)//�ݹ�ʵ��
{
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="first">������������λ����</param>
	/// <param name="end">����������ĩλ����</param>
	int pivot;
	if (first < end)
	{
		pivot = Partition(first, end);
		QuickSort(first, pivot - 1);
		QuickSort(pivot + 1, end);
	}
}
//��������ǵݹ�ʵ��
double SortTest::QuickSortUnrecursion()
{
	/// <summary>
	/// ��������ǵݹ�ʵ��
	/// </summary>
	/// <returns>������ʱ</returns>
	double Time, startTime, endTime;
	startTime = clock();//��ʱ��ʼ
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

	endTime = clock();//��ʱ����
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//ֱ��ѡ������
double SortTest::SelectSort()
{
	/// <summary>
	/// ֱ��ѡ������
	/// </summary>
	double Time, startTime, endTime;
	startTime = clock();//��ʱ��ʼ


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

	endTime = clock();//��ʱ����
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//������
//ɸѡ���������㷨
void SortTest::Sift(int k, int m)
{
	/// <summary>
	/// ɸѡ��������
	/// </summary>
	/// <param name="k">Ϊɸѡ�ڵ�</param>
	/// <param name="m">�ѵ�ĩλ</param>
	int i, j;
	i = k; j = 2 * i + 1;//iΪɸѡ�ڵ㣬jΪi������
	while (j < m)
	{
		if (j + 1 < m && r[j] < r[j + 1])j++;//ȡֵ���ĺ���
		if (r[i] > r[j]) break;//�Ƚ�ɸѡ�ڵ��ֵ������ӵ�ֵ��ȡ���ֵΪ���ڵ�
		else {
			Swap(r[i], r[j]);
			i = j; j = 2 * i + 1;
		}
	}
}
//�������㷨
double SortTest::HeapSort()
{
	/// <summary>
	/// ������
	/// </summary>
	/// <returns>������ʱ</returns>
	double Time, startTime, endTime;
	startTime = clock();//��ʱ��ʼ


	for (int i = N / 2 - 1; i >= 0; i--)//�����ѣ������һ����֧��㵽�����
		Sift(i, N);
	for (int i = 0; i < N; i++)
	{
		int tmp = r[0];
		r[0] = r[N - i - 1];
		r[N - i - 1] = tmp;//�ѶѶ��ƶ���������
		Sift(0, N - i - 1);//��ȥ���������ؽ���
	}

	endTime = clock();//��ʱ����
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//�鲢����
//һ�ι鲢�㷨
void SortTest::Merge(int r1[], int s, int m, int t)
{
	/// <summary>
	/// һ�ι鲢
	/// </summary>
	/// <param name="r1">һ���㹻��������</param>
	/// <param name="s">��һ�����е���λ</param>
	/// <param name="m">�ڶ������е���λ</param>
	/// <param name="t">�ڶ������е�ĩλ</param>
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
	//�������޸�ԭ����
	for (int i = s; i <= t; i++)
	{
		r[i] = r1[i];
	}
}
//�鲢����ݹ��㷨
void SortTest::MergeSort(int r1[], int s, int t)
{
	/// <summary>
	/// �鲢����ݹ��㷨
	/// </summary>
	/// <param name="r1">һ���㹻��������</param>
	/// <param name="s">������λ����</param>
	/// <param name="t">����ĩλ����</param>
	if (s >= t)return;//����������ֻ��һλ��ֱ�Ӽ�¼��r1�У����ҽ����ݹ�
	else {
		int m = (s + t) / 2;//�԰뻮��
		MergeSort(r1, s, m);//��ߴ������й鲢
		MergeSort(r1, m+1, t);//�ұߴ������й鲢
		Merge(r1, s, m, t);//�����������й鲢
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
//�鲢����ǵݹ��㷨
double SortTest::MergeSortUnrecursion()
{
	/// <summary>
	/// �鲢����ǵݹ��㷨
	/// </summary>
	/// <returns>������ʱ</returns>
	double Time, startTime, endTime;
	startTime = clock();//��ʱ��ʼ


	if (N <= 0)
	{
		return -1;
	}
	int nLength = N;
	int* r1 = new int[nLength];
	int nSize = 1;//�ֳ�����С��  
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

	endTime = clock();//��ʱ����
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}
//˫��ð������
double SortTest::TwoBubbleSort()
{	
	/// <summary>
	/// ˫��ð������������ð����������ð������Ϊһ������
	/// </summary>
	/// <returns>������ʱ</returns>
	double Time, startTime, endTime;
	startTime = clock();//��ʱ��ʼ


	int left = 0,right = N - 1;//�����ǩ
	int shift = 1;//�����������Ԫ��λ��

	while (left < right) { // ��������
		for (int i = left; i < right; i++) {
			if (r[i] > r[i + 1]) { // ��һ�����ȵڶ������󣬽���
				Swap(r[i], r[i + 1]);
				shift = i;
			}
		}
		right = shift;
		for (int i = right - 1; i >= left; i--) { // ��������
			if (r[i] > r[i + 1]) { // ��һ�����ȵڶ������󣬽���
				Swap(r[i], r[i + 1]);
				shift = i + 1;
			}
		}
		left = shift;
	}

	endTime = clock();//��ʱ����
	Time = (endTime - startTime) / CLOCKS_PER_SEC;
	return Time;
}


//ʱ�����ܲ���ģ��
void SortTest::TimePerformanceTest(int len, int time, int mod)
{
	/// <summary>
	/// ����ֱ�Ӳ�������ϣ��������������
	/// ��������ֱ��ѡ�����򡢶�����͹鲢�����ʱ������
	/// </summary>
	/// <param name="len">�������鳤�ȣ�Ӧ��С�ڻ����100</param>
	/// <param name="time">ѭ���������</param>
	/// <param name="mod">���������ģʽѡ��1Ϊ����2Ϊ����3Ϊ�������</param>
	double startTime = clock();//��ʱ��ʼ
	for (int i = 0; i <= time; i++)
	{
		//cout << "��ʼ����" << endl;
		rChange(len, mod);
		//PrintList();
		TwoBubbleSort();
		//cout << "���������" << endl;
		//PrintList();
	}
	double endTime = clock();//��ʱ����
	double Time = endTime - startTime;
	cout << "˫��ð�������ʱ��" << Time / CLOCKS_PER_SEC << "s" << endl;
	//-----------------------------------------------------
	startTime = clock();//��ʱ��ʼ
	for (int i = 0; i <= time; i++)
	{
		//cout << "��ʼ����" << endl;
		rChange(len, mod);
		//PrintList();
		InsertSort();
		//cout << "���������" << endl;
		//PrintList();
	}
	endTime = clock();//��ʱ����
	Time = endTime - startTime;
	cout << "ֱ�Ӳ��������ʱ��" << Time / CLOCKS_PER_SEC << "s" << endl;
	//-----------------------------------------------------
	startTime = clock();//��ʱ��ʼ
	for (int i = 0; i <= time; i++)
	{
		//cout << "��ʼ����" << endl;
		rChange(len, mod);
		//PrintList();
		ShellSort();
		//cout << "���������" << endl;
		//PrintList();
	}
	endTime = clock();//��ʱ����
	Time = endTime - startTime;
	cout << "ϣ�������ʱ��" << Time / CLOCKS_PER_SEC << "s" << endl;
	//-----------------------------------------------------
	startTime = clock();//��ʱ��ʼ
	for (int i = 0; i <= time; i++)
	{
		//cout << "��ʼ����" << endl;
		rChange(len, mod);
		//PrintList();
		BubbleSort();
		//cout << "���������" << endl;
		//PrintList();
	}
	endTime = clock();//��ʱ����
	Time = endTime - startTime;
	cout << "���������ʱ��" << Time / CLOCKS_PER_SEC << "s" << endl;

	//-----------------------------------------------------
	startTime = clock();//��ʱ��ʼ
	for (int i = 0; i <= time; i++)
	{
		//cout << "��ʼ����" << endl;
		rChange(len, mod);
		//PrintList();
		QuickSort(0,N-1);
		//cout << "���������" << endl;
		//PrintList();
	}
	endTime = clock();//��ʱ����
	Time = endTime - startTime;
	cout << "���������ʱ��" << Time / CLOCKS_PER_SEC << "s" << endl;


	//-----------------------------------------------------
	startTime = clock();//��ʱ��ʼ
	for (int i = 0; i <= time; i++)
	{
		//cout << "��ʼ����" << endl;
		rChange(len, mod);
		//PrintList();
		SelectSort();//ֱ��ѡ������
		//cout << "���������" << endl;
		//PrintList();
	}
	endTime = clock();//��ʱ����
	Time = endTime - startTime;
	cout << "ֱ��ѡ�������ʱ��" << Time / CLOCKS_PER_SEC << "s" << endl;


	//-----------------------------------------------------
	startTime = clock();//��ʱ��ʼ
	for (int i = 0; i <= time; i++)
	{
		//cout << "��ʼ����" << endl;
		rChange(len, mod);
		//PrintList();
		HeapSort();//������
		//cout << "���������" << endl;
		//PrintList();
	}
	endTime = clock();//��ʱ����
	Time = endTime - startTime;
	cout << "�������ʱ��" << Time / CLOCKS_PER_SEC << "s" << endl;

	//-----------------------------------------------------
	int r1[MaxSize] = { 0 };
	startTime = clock();//��ʱ��ʼ
	for (int i = 0; i <= time; i++)
	{
		//cout << "��ʼ����" << endl;
		rChange(len, mod);
		//PrintList();
		MergeSort(r1,0,N);//�鲢����
		//cout << "���������" << endl;
		//PrintList();
	}
	endTime = clock();//��ʱ����
	Time = endTime - startTime;
	cout << "�鲢�����ʱ��" << Time / CLOCKS_PER_SEC << "s" << endl;
}