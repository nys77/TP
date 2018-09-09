#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<string.h>

char* build_query(const char *url, size_t *len);
void get_page(const char *name, const char *url, const char *port);


