#include <stdio.h>
#include <string.h>


#define H20   3
#define E200  3
#define MAX   2000

char  s1000w[9] = "26638985";
char  s200w[9] = "37266877";
char  h20w[H20][9] = {"15720791","21230260","55899892"};
char  e200[E200][4] = {"248","285","453"};
char  data[MAX][9]; 
char  tmp[9];

int   dollars = 0;
FILE *fopen(),*p1,*p;

int main()
{
    int i,j,k,is_end; /* k stand for how many tickets you won */
    p1 = fopen("final_data","r");
    p  = fopen("result.txt","w");
    k=0;    
    
    while(1)
    {
        is_end = fscanf(p1,"%s",tmp);
//        printf("tmp:%s\n",strrev(tmp));
        if  (is_end != 1)
            break;
        if  (strlen(tmp) != 8)
            continue;
        for(i=0;i<8;i++)
        {
            if  (tmp[i] >= '0' && tmp[i] <= '9')
                continue;
            else
                break;
        }
        i=0;/*initialize*/
        j=0;/*initialize*/
        /*only 200*/
//        printf("c:%c!!!!\n",tmp[7]);
        if( ((tmp[7]=='3')&&(tmp[6]=='5')&&(tmp[5]=='4')) || ((tmp[7]=='5')&&(tmp[6]=='8')&&(tmp[5]=='2')) || ((tmp[7]=='8')&&(tmp[6]=='4')&&(tmp[5]=='2')) )
        {
            strncat(data[k] , tmp,8);
            
            fprintf(p,"%d:%s,200\n",k+1,tmp);
            printf("%d:%s,200\n",k+1,data[k]);
            
            k++;
            dollars = dollars + 200;
        }
        else if( strcmp(s1000w,tmp) == 0) /* 1000w! */
        {
            strncat(data[k] , tmp,8);
            
            fprintf(p,"%d:%s,1000w!!\n",k+1,tmp);
            printf("%d:%s,1000w!!\n",k+1,data[k]);
            
            k++;
            dollars = dollars + 10000000;
        }
        else if( strcmp(s200w,tmp) == 0) /* 200w */
        {
            strncat(data[k] , tmp,8);
            
            fprintf(p,"%d:%s,200w!!\n",k+1,tmp);
            printf("%d:%s,200w!!\n",k+1,data[k]);
            
            k++;
            dollars = dollars + 2000000;
        }
        else /* check 20w */
        {
            for(i=0;i<3;i++)
            {
                  for(j=8;j>=0;j--)
                  {
                        if(tmp[j] == h20w[i][j])
                              continue;
                        else
                              break;
                  }
                  switch(j)
                  {
                  /*20 w j=-1*/
                        case -1: 
                        strncat(data[k] , tmp,8);
                        fprintf(p,"%d:%s,20w!!\n",k+1,tmp);
                        printf("%d:%s,20w!!\n",k+1,data[k]);
                        
                        k++;
                        dollars = dollars + 200000;
                        break;
                  /*4 w j=0*/
                        case 0:
                        strncat(data[k] , tmp,8);
                        fprintf(p,"%d:%s,4w!!\n",k+1,tmp);
                        printf("%d:%s,4w!!\n",k+1,data[k]);
                        
                        k++;
                        dollars = dollars + 40000;
                        break;
                  /*1 w j=1*/
                        case 1:
                        strncat(data[k] , tmp,8);
                        fprintf(p,"%d:%s,1w!!\n",k+1,tmp);
                        printf("%d:%s,1w!!\n",k+1,data[k]);
                        
                        k++;
                        dollars = dollars + 10000;
                        break;
                  /*4000 j=2*/
                        case 2:
                        strncat(data[k] , tmp,8);
                        fprintf(p,"%d:%s,4000\n",k+1,tmp);
                        printf("%d:%s,4000\n",k+1,data[k]);
                        
                        k++;
                        dollars = dollars + 4000;
                        break;
                  /*1000 j=3*/
                        case 3:
                        strncat(data[k] , tmp,8);
                        fprintf(p,"%d:%s,1000\n",k+1,tmp);
                        printf("%d:%s,1000\n",k+1,data[k]);
                        
                        k++;
                        dollars = dollars + 1000;
                        break;
                  /*200 j=4*/
                        case 4:
                        strncat(data[k] , tmp,8);
                        fprintf(p,"%d:%s,200\n",k+1,tmp);
                        printf("%d:%s,200\n",k+1,data[k]);
                        
                        k++;
                        dollars = dollars + 200;
                        break;
                  }
            }
        }
    }
    fprintf(p,"total win %d tickets, %d dollars!\n",k,dollars);
    printf("total win %d tickets, %d dollars!\n",k,dollars);
    fclose(p1);
    fclose(p);
}
