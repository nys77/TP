# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <err.h>
# include <pthread.h>
# include <unistd.h>
# include <errno.h>
struct th_arg{
  const char *msg;
  size_t id;
};
void echo(size_t id) {
  int r;
  char buf[256];
  while ( (r = read(STDIN_FILENO, buf, 255)) ) {
     if (r == -1) {
        if (errno == EINTR) continue;
        err(2, "Issue reading from stdin in thread %zu", id);
     }
     buf[r] = 0;
     printf("<%02zu>: %s", id, buf);
   }
}
void *thread_1(void *arg)
{
    struct th_arg *boi = (struct th_arg*)arg;
    echo(boi->id);
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
