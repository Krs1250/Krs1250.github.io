#include <stdio.h>
#include <string.h>

// 用sign（默认为+，用于第一次取值）记录下未被使用的符号，直到遇到下一个符号（包括=）才拿出来用

// temp 临时存储数据，同sign一起为每次遇到新的符号的时候，赋值给result
int main()
{
    char text[100];
    scanf("%s", text);

    int sign = '+';
    int temp = 0;
    int key = 1;
    double result;
    for(int i=0; i<strlen(text); i++)
    {
        printf("i = %d text[%d] = %c\n", i, i, text[i]);
        printf("k = %d\n", key);
        // 判断为数字
        if(text[i]<='9'&&text[i]>='0')
        {
            // 为temp赋值
            if(key==1)
            {
                temp=text[i]-'0';
                key = 0;
            }
            else
            {
                temp*=10;
                temp+=text[i]-'0';
            }

        }
        // 判断为符号
        else if(text[i]=='+'||text[i]=='-'||text[i]=='*'||text[i]=='/'||text[i]=='=')
        {
            printf("%c\n",text[i]);
            key = 1;
            // 计算result
            if(sign=='+')
            {result+=temp;}
            else if(sign=='-')
            {result-=temp;}
            else if(sign=='*')
            {result*=temp;}
            else if(sign=='/')
            {result/=temp;}
            // 判断sign
            if(text[i]=='+')
            {sign='+';}
            else if(text[i]=='-')
            {sign='-';}
            else if(text[i]=='*')
            {sign='*';}
            else if(text[i]=='/')
            {sign='/';}
            else if(text[i]=='=')
            {break;}
        }

    }
    printf("%.1lf\n", result);

}