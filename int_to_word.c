#include<stdio.h>
#include<conio.h>
int l;
char ones[][20]={"","one","two","three","four","five","six","seven","eight","nine"};
char eletonin[][20]={"","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char tens[][20]={"","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
int twodigit(char *num, char a,char b,int d)
{
   int x,y;
   x=a-48;
   y=b-48;int printed=1;
   if((x!=0)&&(y==0))
   {
       printf("%s ",tens[x]);
   }
    else if((x==1)&&(y!=0))
   {
       printf("%s ",eletonin[y]);
   }
    else if(x!=0&&y!=0)
   {
       printf("%s %s ",tens[x],ones[y]);
   }
   else if(x==0&&y!=0)
   {
     printf("%s ",ones[y]);
   }
   else
   {
       printed=0;
   }
   switch(d)
   {
   case 9:
    { if(printed)
    printf("crores ");
    d-=2;
    return d;}
   case 7:
    { if(printed==1)
    printf("lakhs ");
    d-=2;
    return d;
    }
    case 5:
    {  if(printed==1)
    printf("thousand ");
    d-=2;
    return d;
    }
    case 2:
    {
    if(d==2)d-=2;
    return d;
    }
   }
}
int threedigit(char *num, char x,int d)
{
    int y=x-48;
    if(y==0)
    {
        d-=1;
        return d;
    }
    else
    {
        printf("%s hundred ",ones[y]);
        d-=1;
        return d;
    }
}
int main()
{
    char num[10];
    scanf("%s",&num);
    int d=0,l;
    d=strlen(num);l=d;
    while(d!=0)
    {
        if(d==9||d==7||d==5||d==2)
            {
            d=twodigit(num,num[l-d],num[l-d+1],d);
            }
            if(d==3)
            {
                d=threedigit(num,num[l-d],d);
            }
    }
}
