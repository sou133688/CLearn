#include<stdio.h>
void print_board(int board[3][3]){
int i,j;
for( i = 0; i < 3; i++ ){
for( j = 0; j < 3; j++ ){
printf("|");

if(board[i][j]==0)printf(" ");
else if(board[i][j]==1)printf(" O ");
else if(board[i][j]==-1)printf(" X ");
}
printf("|\n");
}
}

int judge(int board[3][3]){

int x,y;

for(x=0;x<3;x++){
if(board[0][x]!=0){
if(board[0][x]==board[1][x] && board[1][x]==board[2][x]){
return board[0][x];
}
}
}



for(y=0;y<3;y++){
if(board[y][0]!=0){
if(board[y][0]==board[y][1] && board[y][1]==board[y][2]){
return board[y][0];
}
}
}


if(board[1][1]!=0){
if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
return board[1][1];
}

if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
return board[1][1];
}
}

for(x=0;x<3;x++){
for(y=0;y<3;y++){
if(board[y][x]==0){

return 0;
}
}
}

return -1;
}

void mark_board(int board[3][3],int turn){
int x,y;

if(turn==1){
printf("Oのターンです");
}else{

printf("Xのターンです");
}
printf("縦の位置は？");
scanf("%d",&x);
printf("横の位置は？");
scanf("%d",&y);

}


void print_message(int result){
}

int main(void){
int board[3][3]={};
int turn=1;/*1=maru,-1=batsu*/
int result;

while((result=judge(board))==0){
print_board(board);
mark_board(board,turn);
turn*=-1;
}

print_board(board);
print_message(result);

return 0;
}
