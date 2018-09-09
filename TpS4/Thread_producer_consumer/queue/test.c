/* testing shared queues */

# define _GNU_SOURCE

# include <assert.h>
# include <err.h>
# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "shared_queue.h"

# define ITER 500

const struct timespec sleeptime = {0, 10000};

struct tharg {
  unsigned id;
  struct shared_queue *queue;
  pthread_barrier_t *sync;
};

void* worker(void *arg_) {
  struct tharg *arg = arg_;
  struct shared_queue *queue = arg->queue;
  unsigned id = arg->id;
  pthread_barrier_wait(arg->sync);
  for (size_t i = 0; i < ITER; i++) {
    int x = random() % 100;
    printf("<%u> Pushed %d\n", id, x);
    shared_queue_push(queue, x);
    nanosleep(&sleeptime, NULL);
    x = shared_queue_pop(queue);
    printf("<%u> Poped %d\n", id, x);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  size_t nb_workers = 8;
  if (argc > 1)
    nb_workers = strtoul(argv[1], NULL, 10);
  pthread_barrier_t sync;
  pthread_barrier_init(&sync, NULL, nb_workers);
  // VLA are cool !
  pthread_t workers[nb_workers];
  struct tharg tharg[nb_workers];
  struct shared_queue *queue = new_shared_queue();
  for (size_t i = 0; i < nb_workers; i++) {
    tharg[i].sync = &sync;
    tharg[i].id = i;
    tharg[i].queue = queue;
    int thret = pthread_create(workers + i, NULL, worker, tharg + i);
    if (thret != 0) {
      errno = thret;
      err(1, "creating thread %zu failed", i);
    }
  }
  for (size_t i = 0; i < nb_workers; i++) {
    int joinret = pthread_join(workers[i], NULL);
    if (joinret != 0) {
      errno = joinret;
      err(1, "joining thread %zu failed", i);
    }
  }
  pthread_barrier_destroy(&sync);
  shared_queue_destroy(queue);
  return 0;
}
