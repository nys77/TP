#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <err.h>
void *thread_1(void *arg)
{
    printf("Hello_world\n");
    (void)arg;
    pthread_exit(NULL);
}

int main(int argc ,char *argv[])
{

    //avant création
    size_t nb = atof(argv[1]);
    (void)argc;
    pthread_t thread1;
  for(size_t i=0;i<nb;i++)
  {
    if(pthread_create(&thread1, NULL, thread_1, NULL) == -1) {
	perror("pthread_create");
    }
  }
  for(size_t i=0;i<nb;i++)
  {
   pthread_join(thread1, NULL);
  }
    //aprés création;

    return 0;
}
