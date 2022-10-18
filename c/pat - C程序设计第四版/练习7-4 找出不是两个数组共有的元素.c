#include <stdio.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	int List1[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", List1 + i);
	}
	
	int m;
	scanf("%d", &m);
	int List2[m];
	for(int i=0; i<m; i++)
	{
		scanf("%d", List2 + i);
	}
	
	int result[m+n];
	int result_count = 0;
	
	int key;
	
	
	// List1 对 List2
	for(int i=0; i<n; i++)
	{
		key = 1;
		// 判断List1&List2是否重复
		for(int j=0; j<m; j++)
		{
			if(List1[i]==List2[j])
			{
				key = 0;
				break;
			}
		}
		// 判断result中是否有重复
		for(int j=0; j<result_count; j++)
		{
			if(List1[i]==result[j])
			{
				key = 0;
				break;
			}
		}
		if(key == 1)
		{
			result[result_count++]=List1[i];
		}
	}
	
	
	// List2 对 List1
	for(int i=0; i<m; i++)
	{
		key = 1;
		// 判断List1&List2是否重复
		for(int j=0; j<n; j++)
		{
			if(List2[i]==List1[j])
			{
				key = 0;
				break;
			}
		}
		// 判断result中是否有重复
		for(int j=0; j<result_count; j++)
		{
			if(List2[i]==result[j])
			{
				key = 0;
				break;
			}
		}
		if(key == 1)
		{
			result[result_count++]=List2[i];
		}
	}
	
	// 打印result
	for(int i=0; i<result_count; i++)
	{
		printf("%d ", *(result + i));
	}
}