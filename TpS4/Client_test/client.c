typedef struct  sockaddr  SOCKADDR;
typedef struct  sockaddr_in SOCKADDR_IN;
typedef int SOCKET;
char rep[1000];
char* build_query(const char *url, size_t len)
{
   //contruit la chaine "GET http://perdu.com HTTP/1.0\n\r\n\r"
    char *x = malloc(*(len) * sizeof(char));
    int size = snprintf(x, *len, "%s%s%s", *url , "\n\r","\n\r");
    if(size >= BUF_LEN) {
        realloc(&x,(size + 1) * sizeof(char));
        snprintf(x, *len, "%s%s%s", *url , "\n\r", "\n\r");
    }
    return x;
}

/*void getaddrinfo()
{
    
    //retour l'adresse ip.
    static char buf[ADDR_MAX];
    struct ifaddrs *list;
    struct ifaddrs *it;
    
    if (getifaddrs(&list) != 0) {
        perror("getifaddrs");
        return EXIT_FAILURE;
    }
    it = list;
    while (it != NULL) {
        struct sockaddr_in *addr;
        
        addr = (struct sockaddr_in *)it->ifa_addr;
        if (addr != NULL && it->ifa_addr->sa_family == AF_INET) {
            if (inet_ntop(AF_INET, &addr->sin_addr, buf, ADDR_MAX) == NULL) {
                perror("inet_ntop");
                exit(EXIT_FAILURE);
            }
            printf("%s: %s\n", it->ifa_name, buf);
        }
        it = it->ifa_next;
    }
    freeifaddrs(list);
}*/
void get_page(const char *name, const char *url, const char *port)
{
    SOCKET sock;
    sock= socket(AF_INET, SOCK_STREAM, 0);
    if(sock!= -1)
    {
        printf("socket créée \n");
        printf(" ENtrez le nom d'un site : ");
        char lien[100];
        scanf("%s", lien);
        
        printf(" le nom de votre site est %s \n", lien);
        /*const char*url= lien;
        struct hostent*host= gethostbyname(url);
        SOCKADDR_IN  sin;
        bcopy(host->h_addr, &(sin.sin_addr), host->h_length);
        
        sin.sin_family= AF_INET;
        sin.sin_port= htons(PORT);
        //pas besoin de bind, j attaque le connect
        */
        struct addrinfo hints;
        struct addrinfo *result, *rp;
        
        // hints describes what we want
        // first fill the structure with 0s
        memset(&hints, 0, sizeof (struct addrinfo));
        // We only want IPv4, use AF_UNSPEC if you don't care which one
        hints.ai_family = AF_INET;
        // We want TCP
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = 0;
        hints.ai_protocol = 0;
        
        // name and port are strings (domaine name and port, obviously)
        // result will contain the result
        addrinfo_error = getaddrinfo(name, port, &hints, &result);
        
        // Error management
        if ( addrinfo_error != 0 ) {
            errx(EXIT_FAILURE, "Fail getting address for %s on port %s: %s",
                 name, port, gai_strerror(addrinfo_error));
            
        if(connect(sock, (SOCKADDR*)&hints, sizeof sin)!= -1)
        {
            printf("connexion établie ! \n");
            //j envoie ma requete
            
            //if(send(sock, "GET / HTTP 1.0\n\n", 20,0)!=-1)//
            if(send(sock, "GET / HTTP 1.0 \n\n", 16, 0)!=-1)
            {
                printf(" requete envoyée! \n");
                while(recv(sock, rep, 1000,0)>0)
                {
                    printf("je reçois !\n");
                    
                    printf("%s", rep);
                    
                }else perror("pas de réponse...");
            }else perror("requete non transmise  \n");
            
        }else perror(" la connexion a echoué !\n");
        
    }else perror("chkeltiha f la creation ! ");
}

int main() {
    get_page("perdu.com", "http://perdu.com", "80");
    return 0;
}
