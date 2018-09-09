# include <stdio.h>
# include <stdlib.h>
# include <sys/dir.h>
//crée un dossier
int main (int argc, char *argv[])
{
    if (argc==2)
    {
        mkdir(argv[1]);
        printf("Succes Create dir %s\n",argv[1]);
    }
    else
    {
        printf("Put argument\n");
    }
    return 0;
}
