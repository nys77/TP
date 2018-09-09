
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
size_t min_array (int *begin ,int *end)
{
    int min;
    size_t i =0;
    size_t pos_min;
    for (;end-begin!=0;begin++)
    {
        if (i==0)
        {
            min =*(begin);
            pos_min =0;
        }
        else if( min>*(begin))
        {
            min =*(begin);
            pos_min= i ;
        }
        i++;
     }
    return pos_min;
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
void Select_Sort(int *begin , int *end)
{
    for (;end-begin!=0;begin++)
    {
        swap(begin,begin+min_array(begin,end));
    }
}
void Bubble_Sort(int *begin, int *end)
{
    size_t i = (end -begin);
    for(;i>1;i--)
    {
        for (size_t j = 0; j!=i-1 ;j++)
        {
            if (*(begin+j+1)<*(begin+j))
            {
                swap((begin+j+1),(begin+j));
            }
        }
    }
}
int main (void)
{
  int array2[9] = {12,21,4,51,62,79,8,91,10}; // an example of array of size 10
  int *begin2 = array2;
  int *end2 = begin2 + 9;
  printf("======Min=====\n");
  printf("The Min is : %zu\n",min_array(begin2,end2));
  printf("=====Select_Sort=====\n");
  array_print(begin2,end2);
  Select_Sort(begin2,end2);
  array_print(begin2,end2);
  printf("=====Bubble_Sort=====\n");
  int array[9] = {12,21,4,51,62,79,8,91,10}; // an example of array of size 10
  int *begin = array;
  int *end = begin + 9;
  array_print(begin,end);
  Bubble_Sort(begin,end);
  array_print(begin,end);
  return 0;
}
