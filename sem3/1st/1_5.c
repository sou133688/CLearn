#include<stdio.h>

int main(){
  int i=0,count=0,v=0,sum=0,t=0;
  char str[100];
  scanf("%100s\n", str);

// 桁数のカウント
for(i=0;i<60;++i){
  count=i;
  printf("%c\n", str[i]);
if(str[i] == '\0'){
  break;
}
}
if(count>60) {
    printf("Error\n");
    return 0;
  }

// for(i=0;i<61;++i){
//   // printf("%c\n", str[i]);
//   if(str[i] == '\0'){
//     count = i;
//     break;
//   }
// }
//   if(count==0||count>61) {
//   printf("Error\n");
//   return 0;
//   }

  printf("%d\n",count);

//
// if (count%2==0) {
//   // 桁数が偶数の場合
//   printf("偶数\n");
//   for (t = 0; t <= count; t++) {
//     // // int整数に戻す
//     printf("%d,%d\n",t,str[t]);
//     v=str[t]-'0';
//     printf("v=%d\n",v );
//     if(v!=0&&v!=1&&v!=2&&v!=3&&v!=4&&v!=5&&v!=6&&v!=7&&v!=8&&v!=9) {
//       // 整数値と10以上の場合にエラー表示
//       printf("Error\n");
//       return 0;
//     }
//
//     if(t%2==0){
//       v=v*2;
//       printf("この桁は2倍\n");
//       if(v>9){
//         // 2桁を1桁に
//         v=v-9;
//
//       }
//     }
//     printf("v %d\n", v);
//     sum=sum+v;
//     printf("SUM %d\n\n",sum);
//   }
// }
//
// else{
//   // 桁数が奇数の場合
//   printf("奇数\n");
//   for (t = 0; t <= count ; t++) {
//     // // int整数に戻す
//     printf("%d,%d\n",t,str[t]);
//     v=str[t]-'0';
//     printf("v=%d\n",v );
//     if(v!=0&&v!=1&&v!=2&&v!=3&&v!=4&&v!=5&&v!=6&&v!=7&&v!=8&&v!=9) {
//       // 整数値と10以上の場合にエラー表示
//       printf("Error\n");
//       return 0;
//     }
//
//     if(t%2==1){
//       v=v*2;
//       printf("この桁は2倍\n");
//       if(v>9){
//         // 2桁を1桁に
//         v=v-9;
//
//       }
//     }
//     printf("v %d\n", v);
//     sum=sum+v;
//     printf("SUM %d\n\n",sum);
//   }
// }
//
//
// printf("count %d\n",count);
//
// printf("sum %d\n",sum);
//
// if(sum%10==0){
//   printf("true\n");
// }else{
//   printf("false\n");
// }

return 0;
}
