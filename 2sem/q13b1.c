#include<stdio.h>

int countChar(char*,char);

int main()
{
    FILE* fp;
    fp=fopen("text.txt","r");

    char str[1000];
    fgets(str,1000,fp);
    char c;

    scanf("%c",&c);
    printf("%d\n",countChar(str,c));
}
