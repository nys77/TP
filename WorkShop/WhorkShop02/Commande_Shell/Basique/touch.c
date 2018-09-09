# include <stdio.h>
# include <stdlib.h>
// crée un fichier 
int main (int argc, char *argv[])
{
    if (argc==2)
    {
        FILE* fichier = NULL;
        if (access(argv[1],0))
        {
            fichier = fopen(argv[1], "w");
            printf("Succes create %s \n",argv[2]);
        }
        else
        {
            printf("File Already Existe\n");
        }
        fclose(fichier);
    }
    else
    {
        printf("Put argument\n");
    }
    return 0;
}
