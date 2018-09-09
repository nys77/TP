# define _GNU_SOURCE
# define _POSIX_C_SOURCE 201112L
# ifndef EPITA_IP_SHARED_QUEUE_H_
# define EPITA_IP_SHARED_QUEUE_H_
# include <err.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <netdb.h>
# include <signal.h>
# include <errno.h>
# include <assert.h>
# include <pthread.h>
# include <semaphore.h>

struct tharg {
  unsigned id;
  struct shared_queue *queue;
  pthread_barrier_t *sync;
};

typedef struct s_sem_queue *semq;


struct shared_queue {
  sem_t lock, size;
  struct queue *store;
};

/* standard linked lists */
struct list {
  struct list *next;
  void        *data;
};

/*
 * queue container: replace sentinel and add abstraction
 */
struct queue {
  struct list *store;
  size_t       size;
};



int main(int argc, char* argv[])
{
  
}
