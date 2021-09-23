#include<stdio.h>

int main()
{
    FILE* fp;
    fp=fopen("text.txt","r");
    char str[1000];
    fgets(str,1000,fp);

    int i, count = 0;
    char c;

    scanf("%c",&c);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] == c)
        {
            count = count + 1;
        }
    }
    printf("%d\n",count);
}
