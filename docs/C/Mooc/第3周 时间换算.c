#include <stdio.h>

int main()
{
	int BJT;
	scanf("%d", &BJT);
	
	int UTC = BJT - 800;
	if(UTC < 0)
	{
		UTC += 2400;
	}
	
	printf("%d",UTC);
}