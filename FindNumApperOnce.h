#pragma once 

//��������ֻ����һ�ε�����
//˼·������1.�Ƚ����е���ȫ����� 2.Ȼ���ҳ�����ĵ�һ��Ϊ1��λ����Ϊ���Ϊ1��˵����һ���������λΪ1������һ���������λΪ0����ͬ���������϶�����ͬһ�飬
void FindNumApperOnce(int* a,int size,int& array1,int & array2)
{
	int sum = 0;
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		sum ^= a[i];
	}

	for (int i = 0; i < 32;i++)
	{
		if ((sum >> i) & 1 == 1)
		{
			index = i;
			break;
		}
	}

	if (index == 0)
		return;

	for (int i = 0; i < size; i++)
	{
		if (((a[i] >> index) & 1) == 1)
		{
			array1 ^= a[i];
		}
		else if (((a[i] >> index) & 1) == 0)
		{
			array2 ^= a[i];
		}
	}


}




void TestFind()
{
	int a[] = {2,4,3,6,3,2,5,5};
	int array1 = 0;
	int array2 = 0;
	FindNumApperOnce(a, sizeof(a) / sizeof(a[0]), array1, array2);
	cout << array1 << " " << array2 << endl;
}