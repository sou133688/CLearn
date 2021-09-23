int countChar(char* abc, char k)
{
    int i,count=0;
    for(i=0;abc[i]!='\0';i++)
    {
        if(abc[i]==k)
        {
            count=count+1;
        }
    }
    return count;
}
