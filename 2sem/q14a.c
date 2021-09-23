#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct stats
  {
    char name[15];
    int atk;
    int def;
    int hp;
  };

int main()
{
    int n;
    int rnd,dam1,dam2;
    int a;
    struct stats chara[5]={{"momotaro",4,2,15},
                              {"saru",3,2,15},
                              {"inu",3,1,15},
                              {"kiji",2,2,15},
                              {"oni",5,3,15}};


    printf("鬼が現れた!\n");

    for(;;)
    {
        printf("誰が戦う?\n1:桃太郎(%d)　2：猿(%d)　3：犬(%d)　4：キジ(%d)\n",chara[0].hp,chara[1].hp,chara[2].hp,chara[3].hp);
        scanf("%d",&a);


        srand(time(NULL));
        rnd=rand()%3;
        dam1=(chara[a-1].atk*rnd)/(chara[4].def);
        n=chara[4].hp;
        chara[4].hp=chara[4].hp-dam1;

        printf("%sの攻撃!\n%sに%dのダメージ!\n%sの体力は%dになった!\n",chara[a-1].name,chara[4].name,dam1,chara[4].name,chara[4].hp);

        if(chara[4].hp<=0)
        {
            printf("鬼を倒した!めでたしめでたし\n");
            break;
        }


        srand(time(NULL));
        rnd=rand()%3;
        dam2=(chara[4].atk*rnd)/(chara[a-1].def);
        n=chara[a-1].hp;
        chara[a-1].hp=chara[a-1].hp-dam2;

        printf("%sの攻撃!\n%sに%dのダメージ!\n%sの体力は%dになった!\n",chara[4].name,chara[a-1].name,dam2,chara[a-1].name,chara[a-1].hp);

        if(chara[a-1].hp<=0)
        {
            printf("味方が倒されてしまった...出直そう\n");
            break;
        }
    }
}
