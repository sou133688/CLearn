#include <stdio.h>

int main()
{
  int i;
  char word[100];

  printf("文字列を入力してください = ");
  scanf("%s", word);

  for(i=0; word[i]!='\0'; ++i);

  printf("%d文字\n",i);

  return 0;
}
