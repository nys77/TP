#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <err.h>
struct th_arg{
  const char *msg;
  size_t id;
};
void *thread_1(void *arg)
{
    struct th_arg *boi = (struct th_arg*)arg;
    printf("<%zu> : Hello from thread ! \n",(boi)->id);
    (void)arg;
    pthread_exit(NULL);
}
int main(int argc ,char *argv[])
{

    //avant création
    size_t nb = atof(argv[1]);
    (void)argc;
    struct th_arg boi[nb];
     pthread_t thr[nb];
  for(size_t i=0;i<nb;i++)
  {
    boi[i].id =i;
    if(pthread_create(thr+i, NULL, thread_1, boi + i) == -1) {
	perror("pthread_create");
    }
  }
  for(size_t i=0;i<nb;i++)
  {
   pthread_join(thr[i], NULL);
  }
    //aprés création;

    return 0;
}
