# include <assert.h>
# include <err.h>
# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

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
int queue_is_empty(struct queue *queue)
{
  return queue->size == 0;
}
void* queue_pop(struct queue *queue)
{

}
void queue_push(struct queue *queue, void *elm)
{
  
}
struct shared_queue* new_shared_queue(void)
{
  /*queue->store = NULL;
    queue->size = 0;*/
}

/* shared_queue_push(queue, val) add val to the queue                 *
 * notify waiting threads when done                                   */
void shared_queue_push(struct shared_queue *queue, int val)
{

}

/* shared_queue_pop(queue) pop a new value from the queue             *
 * blocks while the queue is empty                                    */
int shared_queue_pop(struct shared_queue *queue)
{

}

/* shared_queue_destroy(queue) destroy the queue                      *
 * free any remaining memory                                          */
void shared_queue_destroy(struct shared_queue *queue)
{

}
