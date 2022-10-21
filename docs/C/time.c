#include <stdio.h>

int main()
{
	int hour1,minute1;
	int hour2,minute2;
	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);
	
	int hour = hour2 - hour1;
	int minute = minute2 - minute1;
	
	if(minute < 0)
	{
		hour -- ;
		minute += 60;
	}
	
	printf("%d %d", hour, minute);
}