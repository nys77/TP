/* testing.c : testing queue */

# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>

# include "queue.h"

void simple_test(size_t len)
{
    printf(">>> Simple Test: <<<\n");
    struct queue queue;
    queue_init(&queue);
    int *data = calloc(len, sizeof (int));
    if (!data)
        err(1, "allocating data failed, dying");
    printf("  Push:\n");
    for (size_t i = 0; i < len; ++i) {
        data[i] = (int)i;
        queue_push(&queue, data + i);
        printf("    pushed: %d\n", data[i]);
        assert(queue.size == i + 1);
    }
    printf("  after push, size: %zu\n", queue.size);
    assert(queue.size == len);
    while (!queue_is_empty(&queue)) {
        int *elm = queue_pop(&queue);
        assert(elm);
        printf("    pop: %d\n", *elm);
    }
    printf("  after pop, size: %zu\n", queue.size);
    assert(queue.size == 0);
    free(data);
}

int main(int argc, char *argv[])
{
    size_t len = 16;
    if (argc > 1)
        len = strtoul(argv[1], NULL, 10);
    simple_test(len);
    return 0;
}
