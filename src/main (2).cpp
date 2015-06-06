#include "CPP_Language.h"

void main()
{
	int a = 1;
	int b = 2;
	Swap(a , b);
	cout<<a<<" "<<b<<endl;
	int arr[] = {3,5,1,2,7,5,6,8,2};

	QSort(arr,  9, 0, 8);

	for(int i = 0; i < 9; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<Fibonacci1(4)<<endl;
	cout<<NumOf1(2)<<endl;
	cout<<NumOf1Impr(0xffffffff)<<endl;
	cout<<is2x(10)<<endl;
	cout<<NumOf0(1)<<endl;
	cout<<NewPow(2, -3)<<endl;
	cout<<NewPowLevels(2, 3)<<endl;
	char* str = "12345555";
	char str2[] = "12345555";
	cout<<strlen(str)<<" "<<sizeof(str2)<<endl;
	system("pause");

}