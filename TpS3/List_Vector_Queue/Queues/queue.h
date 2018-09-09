/*
 * queue.h: dynamic queue
 */



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
    int       size;
};

/*
 * queue_init(queue) initialize an empty queue container
 * allocation of the container is kept external for more flexibility
 */
void queue_init(struct queue *queue);

/*
 * queue_is_empty(queue) test for emptyness
 */
int queue_is_empty(struct queue *queue);

/*
 * queue_push(queue, elm) push elm
 */
void queue_push(struct queue *queue, void *elm);

/*
 * queue_pop(queue) pop the next element (FIFO order)
 * returns NULL if the queue is empty
 */
void* queue_pop(struct queue *queue);
