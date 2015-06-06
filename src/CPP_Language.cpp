#include "CPP_Language.h"

bool g_InvalidInput = false;//全局变量不能定义在头文件中

void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int Partition2( int data[], int len, int start, int end )
{
	if(data == NULL || len <= 0|| start < 0|| end < 0)
		throw new exception("invalid parameters input");
	int small = start-1;
	for(int index = start; index < end; index++)
	{
		if(data[index] < data[end])
		{ 
			++small;
			if(small != index)
				Swap(data[index], data[small]);
		}
		for(int i = 0; i < len; i++) 
			cout<<data[i]<<" ";
		cout<<endl;
	}
	++small;
	Swap(data[small], data[end]);
	return small;
}
int Partition1(int A[], int low, int high)
{
	int pivot;
	pivot = A[low];
	// 从线性表的两端交替地向中间扫描
	while (low < high)
	{
		while (low < high && A[high] >= pivot)
			high--;
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
			low++;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
void QSort(int data[], int len, int start, int end)
{
	if(start == end) return;
	//int index = Partition2(data, len, start, end);
	int index = Partition1(data, start, end);
	if(index > start)
		QSort(data, len, start, index-1);
	if(index < end)
		QSort(data, len, index+1, end);
}
int Fibonacci0(int n)//递归
{
	if(n <= 0) return 0;
	if(n == 1) return 1;
	return Fibonacci0(n-1) + Fibonacci0(n-2);
}
int Fibonacci1(int n)//O(n)
{
	if(n<2)return n;
	int f1 = 0, f2 = 1, fn = 0;
	for(int i = 1; i < n; i++)
	{
		fn = f1 + f2;
		f1 = f2; 
		f2 = fn;
	}
	return fn;
}
int NumOf0(int n )
{
	int count = 0;
	int flag = 1;
	while(flag)
	{
		if((flag&n) == 0)//运算符优先级 算术>>关系>>逻辑
			count++;
		flag = flag<<1;
	}
	return count;
}
int NumOf1(int n)//从后依次向前判断每一位是否为1
{
	int count = 0;
	int flag = 1;
	while(flag)
	{
		if(n&flag)
			count++;
		flag = flag << 1; 
	}
	return count;
}
int NumOf1Impr(int n)//判断为1的改进算法
{
	int count = 0;
	while(n)
	{
		n = (n-1) & n;
		count++;
	}
	return count;
}
bool is2x(int n)//判断是不是2的整数次方
{
	return !((n-1)&n);

}
bool equal(double num1, double num2)
{
	if((num1 - num2 > -0.000001) && (num1 - num2 < 0.000001))
		return true;
	else return false;
}
double NewPow(double base, int exponent)
{
	g_InvalidInput = false;
	if(equal(base, 0.0) && (exponent < 0))
	{
		g_InvalidInput = true;//全局变量作为出错信息提示，此外还有返回值和异常两种方式
		return 0.0;
	}
	double result = 1.0;
	if(exponent == 0) return 1;
	if(exponent > 0)
	{
		for(int i = 0; i < exponent; i++)
			result *= base;
	}
	if(exponent < 0)
	{
		exponent = -exponent;
		for(int i = 0; i < exponent; i++)
			result *= base;
		result = 1/result;
	}
	return result;
}
double NewPowLevels(double base, unsigned int exponent)
{
	if(exponent == 1)
		return base;
	if(exponent == 0)
		return 1;
	double result = NewPowLevels(base, exponent >> 1);
	result *= result;
	if((exponent & 0x01) == 1)//关系大于逻辑，判断奇偶数
		result *= base;
	return result;
}
//大数越界的问题 用字符串或者数组代替
void printToMaxofDigits(int n)
{
	if(n <= 0)
		return;
	char* number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';
	while(!Increase(number))
	{
		printNumber(number);
	}
	delete []number;
}
bool Increase(char* number)
{	
	bool isOverflow = false;//最高位是否要进位
	int nTakeOver = 0;//进位
	int nLength = strlen(number);
	for(int i = nLength-1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if(i == nLength-1)
			nSum++;
		if(nSum > 10)//发生进位
		{
			if(i == 0)
				isOverflow = false;
			else
			{
				nsum -= 10;
				nTakeOver = 1;
				number[i] = '0'+nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;

}
void printNumber(char* number)
{
	bool isBegin = true;
	int nLength = strlen(number);
	for(int i = 0; i < nLength; i++)
	{
		if((isBegin && number[i] != '0')
			isBegin = false;
		if(!isBegin)
			cout<<number[i];
	}
}