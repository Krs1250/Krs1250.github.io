#include <stdio.h>

int main()
{
    int random;
    int N;
    printf("输入随机数&猜测的最大次数N\n");
    scanf("%d %d", &random, &N);

    int guess;
    int key = 0;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &guess);
        if(guess == random)
        {
            key = 1;
            if(i == 1)
            {
                printf("Bingo!");
            }
            else if(i <= 3)
            {
                printf("Luck You!");
            }
            else if(i > 3)
            {
                printf("Good Guess!");
            }
        }
        else if(guess > random)
        {
            printf("Too big\n");
        }
        else if(guess < random)
        {
            printf("Too Small\n");
        }
        else if(guess < 0)
        {
            break;
        }
    }
    if(key == 0)
    {
        printf("Game Over!");
    }
}