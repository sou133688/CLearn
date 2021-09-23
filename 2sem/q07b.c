#include <stdio.h>

#define N 10
#define M 250

int main()
{
    FILE *fp,*fout;
    float number[M],data[M];    //space for before proccesing data.
    float ave[M];        //space for average data.
    int count;
    float sum,n;
    int i=0,j=0;
    fp=fopen("chart1.txt","r");
    fout=fopen("chart2.txt","w");

    //Read files
    while(1)
    {
        count=fscanf(fp,"%f %f",&number[i], &data[i]);
        if(count==EOF)
        {
            break;
        }
        i++;
    }

    //calculation
    for(i=N-1;i<M;i++)
    {
        sum=0;
        for(j=i;j>=i-N+1;j--)
        {
            sum=sum+data[j];
        }
        ave[i]=sum/N;
        //Output
        fprintf(fout,"%d %f\n",i+1,ave[i]);
    }

    //File close
    fclose(fp);
    fclose(fout);

}
