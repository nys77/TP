/* main.c
 
 Client TCP/IP minimum
 
 */
#if defined (WIN32)
#include <winsock2.h>
#elif defined (linux)
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close (s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 23
#define IP "127.0.0.1"

void client (void)
{
    SOCKET sock= socket (AF_INET, SOCK_STREAM, 0);
    if (sock != INVALID_SOCKET)
    {
        int err;
        SOCKADDR_IN sin = {0};
        sin.sin_addr.s_addr = inet_addr (IP);
        sin.sin_family = AF_INET;
        sin.sin_port = htons (PORT);
        err = connect (sock, (SOCKADDR *) & sin, sizeof (sin));
        if (err != SOCKET_ERROR)
        {
            char *buffer = "Hello world !\n";
            err = send (sock, buffer, strlen (buffer), 0);
            if (err != SOCKET_ERROR)
            {
                printf ("%d bytes%s sent\n", (int) err, err > 1 ? "s" : "");
            }
            else
            {
                printf ("ERR: send()\n");
            }
        }
        else
        {
            printf ("ERR: connect()\n");
        }
        closesocket (sock);
    }
    else
    {
        printf ("ERR: socket()\n");
    }
    
}

int main (void)
{
#if defined (WIN32)
    WSADATA WSAData;
    int erreur = WSAStartup (MAKEWORD (2, 0), &WSAData);
#else
    int erreur = 0;
#endif
    client ();
#if defined (WIN32)
    WSACleanup ();
#endif
    system ("pause");
    
    return 0;
}
