# include <stdio.h>
# include <stdlib.h>


int* two_sum(int array[] , int target , size_t len)
{
    for (size_t i =0 ; i< len ; i++)
    {
        for (size_t j =i+1 ; j<len ; j++)
        {
            if(array[i]+array[j]==target)
            {
                int* result;
                for (size_t z =0 ; z<2 ;z++)
                {
                    if (z==0)
                    {
                        *(result)=array[i];
                    }
                    else
                    {
                        *(result+z)=array[j];
                    }
                }
                return result;
            }
        }
    }
    return NULL;
}
int Presente(char *s , char s1, size_t len)
{
    for (size_t i=0; i<len;i++)
    {
        if (*(s+i)==s1)
        {
            return 1;
        }
    }
    return 0;
}
char* Copy (char *s , size_t i , size_t j)
{
    char *result=malloc(sizeof(i-j));
    for (size_t z =0 ; z < (j-i);z++)
    {
        *(result+z)=*(s+z);
    }
    return result;
}
char* subStrings (char *s , size_t len)
{
    size_t save_pos_i;
    size_t save_pos_j;

    size_t compteur=0;
    char* dico;
    size_t save_compteur=0;
    size_t z;
    for(size_t i =0 ; i<len ; i++)
    {
        memset (dico, 0,sizeof(dico));
        z=0;
        compteur=0;
        size_t j =i;
        while ( (j<len) && (!(Presente(dico,*(s+j),len) )))
        {
            compteur++;
            *(dico+z)=*(s+j);
            j++;
            z++;
        }
        if (compteur > save_compteur)
        {
            save_pos_i = i;
            save_pos_j= j ;
            save_compteur = compteur;
        }
    }
    char *result;
    result= Copy(s,save_pos_i,save_pos_j);
    //return save_compteur;
    return result;
}
char* equal (char *s , char *z ,size_t len)
{
    for (size_t i =0 ; i<len ;i++)
    {
        *(s+i)=*(z+i);
    }
    return s;
}
void swap ( char *s , char *s1)
{
    char temp = *(s);
    *(s)=*(s1);
    *(s1)=temp;
}
void AllPermutation(char *s , size_t len)
{
    char *save_s=s;
    for (size_t i =0 ; i<len ;i++)
    {
        swap(s,(s+i));
        printf("%s",s);
        save_s=equal(save_s,s,len);
        save_s= s;
        for (size_t j = 1 ; j<len-1;j++)
        {
            char * temp = equal(temp,s,len);
            swap((temp+j),(temp+j+1));
            printf("%s\n",temp);
        }
        s=equal(s,save_s,len);
    }
}
int main (void)
{
    printf("======Two_Sum=====\n");
    int array[4];
    array[0]=2;
    array[1]=7;
    array[2]=11;
    array[3]=15;
    int* result;
    result=two_sum(array,9,2);
    for (size_t i = 0 ; i < 2 ; i++)
    {
        printf("%d\n", *(result+i));
    }
    printf("======SubStrings=====\n");
    char chaine[] = "bcbcbb\n";
    //printf("%d\n", x);
    printf("%s\n",subStrings(chaine,6));
    printf("======AllPermutation=====\n");
    char chaine2[] = "abcd\n";
    AllPermutation(chaine2,4);
    printf("======Presente=====\n");
    char a ='a';
    printf("%d\n",Presente(chaine2,'d',3));
    return 0;
}
