
# include <stdlib.h>
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>


void swap(int *a, int *b)
{
  int temp = *a;
  *a=*b;
  *b=temp;
}
int max_array (int *begin,int *end)
{
  int max =0;
  for (;end-begin!=0;begin++)
  {
    if (max < *(begin))
    {
      max = *(begin);
    }
  }
  return max;
}
int array_is_sorted(int *begin, int *end)
{
  for (; (end-begin) - 1 !=0;begin++)
  {
    if (*(begin) > (*(begin+1)))
    {
      return 0;
    }
  }
  return 1;
}

void array_print(int *begin, int *end)
{
  int line = 0;
  for (; begin != end; ++begin) {
    if (line > 72) {
      printf("|`|\n");
      line = 0;
    }
    line += printf("| %4d ", *begin);
  }
  printf("|\n");
}
// insert using the naive algo
void array_insert(int *begin, int *end, int x)
{
  size_t i = (end-begin)-1 ;
  *(end -1) = 0;
  while(i > 0 && x < *((begin+i)-1))
  {
    *(begin+i)=*(begin+i-1);
    i--;
  }
  *(begin + i) = x;
}
 void array_insert_sort(int *begin, int *end)
{
  size_t i =0;
  int save= *(begin);
  for (;end-(begin+i)!=0;i++)
  {
    if (i!=0)
    {
      array_insert(begin,begin+i,*(begin+i));
    }
  }
  array_insert(begin,end,save);
}
int binary_search(int *begin, int *end, int x)
{
  int save =0;
  for (;end-begin!=0;begin++)
  {
    if (*(begin)>x)
    {
      return save;
    }
    save++;
  }
  return save;
}
// insert using binary search
void array_insert_bin(int *begin, int *end, int x)
{
 //long i =   memmove(begin,end,3);
 int i = binary_search(begin,end,x);
 size_t j = (end-begin)-1;
 //*(end -1) = 0;
 while(j>i)
 {
   *(begin + j)=*((begin + (j-1)));
   j=j-1;
 }
 *(begin + i)=x;
}
// insertion sort using binary search
void array_insert_sort_bin(int *begin, int *end)
{

   size_t i =0;
   int save= max_array(begin,end);
   for (;end-(begin+i)!=0;i++)
   {
     if (i!=0)
     {
       array_insert_bin(begin,begin+i,*(begin+i));
     }
   }
   array_insert(begin,end,save);
}
int main (void)
{
  printf("=====Insert=====\n");
  int array2[10] = {1,2,4,5,6,7,8,9,10}; // an example of array of size 10
  int *begin2 = array2;
  int *end2 = begin2 + 10;
  array_print(begin2,end2);
  printf("\n");
  array_insert(begin2,end2,0);
  printf("After insert -> : \n");
  array_print(begin2,end2);
  printf("=====Insert_Sort=====");
  printf("\n");
  int array[9] = {1,2,10,20,30,40,50,70,21}; // an example of array of size 10
  int *begin = array;
  int *end = begin + 9;
  array_print(begin,end);
  printf("\n");
  array_insert_sort(begin,end);
  array_print(begin,end);
  printf("=====Insert_Bin=====\n");
  int array3[10] = {1,2,4,5,6,7,8,9,10}; // an example of array of size 10
  int *begin3 = array3;
  int *end3 = begin3 + 10;
  array_print(begin3,end3);
  printf("\n");
  array_insert_bin(begin3,end3,3);
  array_print(begin3,end3);
  printf("=====Insert_Bin_Sort=====\n");
  printf("\n");
  int array4[9] = {1,2,10,20,30,40,50,70,21}; // an example of array of size 10
  int *begin4 = array4;
  int *end4 = begin4 + 9;
  array_print(begin4,end4);
  printf("\n");
  array_insert_sort_bin(begin4,end4);
  array_print(begin4,end4);
  //hybrid_sort(begin2,end2);
  //array_print(begin2,end2);
  return 0;
}
