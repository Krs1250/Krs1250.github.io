#include <stdio.h>

int main()
{
    int N = 0;
    int count = 0, sum = 0;
    
    printf("请输入学生人数N:");
    scanf("%d", &N);

    for(int i = 0; i< N; i++)
    {
        int stu = 0;
        scanf("%d", &stu);

        sum += stu;
        if(stu >= 60)
        {
            count += 1;
        }
    }

    printf("average = %f.1\n", sum*1.0/N);
    printf("count = %d", count);
}