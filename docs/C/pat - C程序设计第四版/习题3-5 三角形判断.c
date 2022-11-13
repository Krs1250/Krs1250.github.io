#include <stdio.h>
#include <math.h>

int main()
{
    int x1,y1,x2,y2,x3,y3;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

    int k12,k13,k23;
    k12 = (y2-y1)/(x2-x1);
    k13 = (y3-y1)/(x3-x1);
    k23 = (y3-y2)/(x3-x2);

    int key = 1;
    if( k12 == k13 || k12 == k23 || k13 == k23)
    {
        printf("Impossible\n");
    }
    else
    {
    	double L12, L13, L23;
    	L12 = sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
    	L13 = sqrt((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1));
    	L23 = sqrt((y3-y2)*(y3-y2)+(x3-x2)*(x3-x2));
		double C = L12+L13+L23;
		double S = sqrt(C/2*(C/2-L12)*(C/2-L13)*(C/2-L23));
        printf("L = %.2f\n", C );
        printf("S = %.2f\n", S );
    }

}