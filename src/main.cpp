#include <string>
#include<queue>
#include<complex>
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stack>
using namespace std;
char* ss = "12345455";
char temp[10];
int a[] = {1,2,3,4};
int f(char temp[5])
{
    return sizeof(temp);
}
class A {};
class B
{
public:
    B()
    {
        cout<<"B()"<<endl;
    }
    ~B()
    {
        cout<<"~B()"<<endl;
    }
    virtual void fun()
    {
        cout<<"fun"<<endl;
    }
    virtual void fun1()
    {
        cout<<"fun1"<<endl;
    }
    float a;
    float b;//12
};
class C:B
{
    virtual void fun() {}
};
class D:public C, public B
{
    virtual   int fun2() {}
};
class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString();
    CMyString& operator=(const CMyString& str)
    {
        //����ֵ��������������Ϊ���ܹ�������ֵ������Ϊvoid��ֻ�ܽ��е�һ��ֵ��
        //������const�����ã������������������һ�θ��ƹ��캯�������Ҹ�ֵ�������������ı������״̬��
        //�жϵ�Ŀ����Ϊ�˱��������ͬһ��ʵ���Ļ���delete���ǲ�����ʵ��Ҳ��delete�����·���ΪNULL��
        if(this == &str)
            return *this;
        delete []m_pData;
        m_pData = NULL;
        m_pData = new char[strlen(str.m_pData)+1];
        strcpy(m_pData, str.m_pData);
        return *this;
    };
    //��ֵ����������������д����
//    CMyString& operator=(const CMyString& str){
//        if(this != &str){
//            CMyString strTmp(str);
//            char* pTemp = strTmp.m_pData;
//            strTmp.m_pData = m_pData;
//            m_pData = pTemp;
//
////            char* pTemp = m_pData;
////            m_pData = strTmp.m_pData;
////            strTmp.m_pData = pTemp;
//        }
//        return *this;
//    }
private:
    char* m_pData;
};
bool find(int matrix[], int rows, int cols, int key)
{
    bool Find = false;
    if(matrix != NULL && rows > 0 && cols > 0)
    {
        int row = 0;
        int col = cols - 1;
        while(row < rows && col >= 0)
        {
            if(matrix[row*cols+col]==key)
            {
                Find = true;
                break;
            }
            else if(matrix[row*cols+col]>key)
                col--;
            else row++;
        }
    }
    return Find;
}
//���ո��滻��%20��,lenΪ�������ʱ������ڴ�
void replaceBlank(char string[], int len)
{

    if(string == NULL && len < 0) return;
    int originLen = 0;
    int numOfBlank = 0;
    int i = 0;
    while(string[i] != '\0')
    {
        ++originLen;
        if(string[i]==' ') ++numOfBlank;
        ++i;
    }
    int newLen = originLen + numOfBlank*2;
    if(newLen>len) return;
    int indexOfOrigin = originLen;
    int indexOfNew = newLen;
    while(indexOfOrigin >= 0&& indexOfOrigin < indexOfNew)
    {
        if(string[indexOfOrigin] != ' ')
            string[indexOfNew--] = string[indexOfOrigin--];
        else
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
            indexOfOrigin--;
        }

    }

//   return string;
}
//��������������ϲ�
void mergeArray(int a[], int b[], int length, int length_a, int length_b)
{
//��β��ͷ��ӡ����

    if(a == NULL || b ==NULL || length < 0 || length_a+length_b > length)return;
    int newLen = length_a+length_b;
    int k = newLen-1;
    int i = length_a, j = length_b;
    i--;
    j--;
    while(i>=0&&j>=0&&i<=k)
    {
        if(a[i] > b[j])
        {
            a[k--] = a[i];
            a[k] = b[j];
            i--;
            k--;
            j--;
        }
        else
        {
            a[k] = b[j];
            k--;
            j--;
        }
    }
}
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
//��ջ���
void reverseListNode(ListNode* pHead)
{
    if(pHead == NULL) return;
    stack<ListNode*> sNode;
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        sNode.push(pNode);
        pNode = pNode->m_pNext;
    }
    while(!sNode.empty())
    {
        pNode = sNode.top();
        printf("%d\n", pNode->m_nValue);
        sNode.pop();
    }
}
//�õݹ���
void reverseListD(ListNode* pHead)
{
    if(pHead == NULL) return;
    if(pHead != NULL)
    {
        if(pHead->m_pNext != NULL)
        {
            reverseListD(pHead->m_pNext);
        }
        printf("%d\n", pHead->m_nValue);
    }
}
int main()
{

    char ss1[] = "00000123";
    cout<<strlen(ss1)<<endl;
//    int a[3][4];
//    int b = 9;
    B b;
    cout<<sizeof(A)<<endl<<sizeof(B)<<endl<<sizeof(b)<<sizeof(D)<<endl;
//    cout<<f(temp);
////    cout<<size of(temp)<<endl;
//    cout<<sizeof(b = 6)<<b<<endl;
//    cout << "Hello world!" << endl;
//    complex<double> cx;
//    cx.real() = 3;
//    cx.imag() = 4;
//    complex<double> cy;
//    cy.real() = 8;
//    cy.imag() = 9;
//
//    cout<<cx+cy<<endl;
//    string *str = new string[3];
//    str[0] = "str1";
//    str[1] = "str2";
//    for(int i = 0; i < sizeof(*str)*2/sizeof(string); i++)
//        cout<<str[i]<<endl;
    int matrix[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    if(find(matrix, 4, 4, 7))
        cout<<"find"<<endl;
    else cout<<"no find"<<endl;
    char* str1 = "abcd";//�ַ��������洢�ھ�̬����str2��ͬ�ĵ�ַ
    char* str2 = "abcd";
    char str3[] = "abcd";
    char str4[] = "abcd";
    if(str1 == str2)
        cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    if(str2 == str4)
        cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    char origin[] = "abce adg dd";
    replaceBlank(origin, 30);
    printf("%s\n", origin);
    int aAr[] = {1,3,5,6,7};
    int bAr[] = {2,4,6};
    mergeArray(aAr,bAr,20,5,3);
    for(int i = 0; i < 8; i++)
        cout<<aAr[i]<<" ";
    cout<<endl;

    ListNode* pHead = new ListNode;
    pHead->m_nValue = 1;
    ListNode* p = pHead;
    for(int i = 0; i < 10; i++)
    {
        ListNode* q = new ListNode;
        q->m_nValue = i+2;
        p->m_pNext = q;
        p = q;
        p->m_pNext = NULL;//ע������β��
    }

    reverseListNode(pHead);
//    reverseListD(pHead);
//    while(pHead)
//    {
//        cout<<pHead->m_nValue<<" "<<endl;
//        pHead = pHead->m_pNext;
//    }
    return 0;
}
