

int main(int argc, char **argv)
{
char *mot[100];
char *dir;
int errno;
if ((strcmp(mot[0], "cd")) == 0 ) {
    
    if ((strcmp(mot[1], "~")) == 0)
        dir = getenv("HOME");
        
        if ((strcmp(mot[1], "~")) != 0)
            
        {
            dir = mot[1] ;
            
           
            
            if (chdir(dir) < 0)
            {
                printf("\nDirectory change failed : %s\n",strerror(errno));
            }
               // continue ;         //affiche le prompt du mini-shell
}
}
return 0;
}
