#include <stdio.h>
int min(int a[],int i,int j)
{
	int min=a[i];          //��ʼֵ�������� ��������Ϊ����ֵ��ʱ��
	for(;i<=j;i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}
int main(void)
{
	int i,j,n,area,height[1001],max_area=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &height[i]);
	}
	for (i = 1; i <= n; i++)//��������
	{
		for (j = i; j <= n; j++)
		{
			area = (j-i+1) * min(height,i,j);
			if (area > max_area)
			{
				max_area = area;
			}
		}
	}
	printf("%d\n", max_area);
	return 0;
}