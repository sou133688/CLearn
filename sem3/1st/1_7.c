// さんもくならべ!!
#include<stdio.h>



int main() {
  int i,j,turn,inp_o,line,row;
  char masu[3][3];

  // masu[0][0]=1+'0';
  // masu[0][1]=2+'0';
  // masu[0][2]=3+'0';
  // masu[1][0]=4+'0';
  // masu[1][1]=5+'0';
  // masu[1][2]=6+'0';
  // masu[2][0]=7+'0';
  // masu[2][1]=8+'0';
  // masu[2][2]=9+'0';

  // 各マスの初期値
  masu[0][0]='1';
  masu[0][1]='2';
  masu[0][2]='3';
  masu[1][0]='4';
  masu[1][1]='5';
  masu[1][2]='6';
  masu[2][0]='7';
  masu[2][1]='8';
  masu[2][2]='9';

// for (size_t i = 0; i < count; i++) {



  for (turn = 0; turn < 100; turn++) {
    // if (turn%2==0) {
      // 先攻
      printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",masu[2][0],masu[2][1],masu[2][2],masu[1][0],masu[1][1],masu[1][2],masu[0][0],masu[0][1],masu[0][2]);

      printf("o> ");
      scanf("%d\n",&inp_o);


      if (inp_o==1){
        masu[0][0]='o';
      }else if(inp_o==2){
        masu[0][1]='o';
      }else if(inp_o==3){
        masu[0][2]='o';
      }else if(inp_o==4){
        masu[1][0]='o';
      }else if(inp_o==5){
        masu[1][1]='o';
      }else if(inp_o==6){
        masu[1][2]='o';
      }else if(inp_o==7){
        masu[2][0]='o';
      }else if(inp_o==8){
        masu[2][1]='o';
      }else if(inp_o==9){
        masu[2][2]='o';
      }

      // result=check_masu(inp)
      // printf("%d\n", inp);
//

  //   }else{
  //     // 後攻
  //     printf("x> \n");
  //     // scanf("%s\n",a);
  //
  //
  //   }
  }




  for (i = 0; i < 3; i++) {
     for (j = 0; j < 3; j++) {
       printf("%c\n",masu[i][j]);
     }
  }
}

//
// int check_masu(int inp, int line, int rows, char masu[line][row]){
//
//
// }
