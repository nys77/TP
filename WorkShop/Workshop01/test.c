# include <stdio.h>
# include <stdlib.h>
///Desktop/WorkShop/Workshop01/Hello_Wolrd.txt/
struct stat
{
    long st_size;
};
void Hello_Wold()
{
    FILE* fichier = NULL;
    fichier = fopen("Hello_Wolrd.txt", "w");
    if (fichier != NULL)
    {
        fputs("Hello_Wolrd ", fichier);
        fclose(fichier);
    }
}
double arondie(double nbr)
{
    
    int tmp=0;
    long tmplong=nbr;
    double verr=(double)tmplong;
    
    nbr=nbr*100;
    tmp=(int)nbr;
    nbr=(double)tmp;
    nbr=nbr/100;
    verr=nbr-verr;
    
    if(verr>=0.5){
        nbr=nbr+1;}
    
    return nbr;
}
double FileSize ()
{
    char chemin[1000];
    printf("Quel Fichier?");
    scanf("%19s ", chemin);
    FILE *fichier;
    double size;
    fichier=fopen(chemin,"rb");
    if(fichier)
    {
        fseek (fichier, 0, SEEK_END);   // non-portable
        size=ftell(fichier);
        fclose (fichier);
        if(size<1000)
        {
        }
        if ((size>=1000) && (size<1000000))
        {
            size=size/1024;
        }
        if ((size>=1000000) && (size<1000000000))
        {
            size=size/1024/1024;
            
        }
        if ((size>=1000000000) && (size<1000000000000))
        {
            size=size/1024/1024;
        }
        size=arondie(size);
    }
    return size;
    //printf( "Votre nom est %s !\n", chemin );
}
void Print_at_Position (char name[] , size_t pos)
{
    size_t i=0;
    FILE *file = fopen ( name, "r" );
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            while (i<128)
            {
                if (i==pos)
                {
                   printf("Caractere at %zu : %c\n", pos,line[i]);
                }
                i++;
            }
            pos=pos-128;
        }
        fclose ( file );
    }
    else
    {
        perror ( name ); /* why didn't the file open? */
    }
}
void Print_Doc (char name[])
{
    FILE *file = fopen ( name, "r" );
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            printf("Ligne : %s\n", line); /* write the line */
        }
        fclose ( file );
    }
    else
    {
        perror ( name ); /* why didn't the file open? */
    }
}
int len (char s[])
{
    int len =0;
    for (size_t i=0;s[i]!=' ' ;i++)
    {
        len++;
    }
    return len;
}
void get_Lines (char name[],int lines)
{
    FILE *file = fopen ( name, "r" );
    int i=0;
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        char save[128];
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            if (i==lines)
            {
            printf("Ligne : %s\n", line); /* write the line */
            printf("Size: %d\n", len(line));
            }
            i++;
        }
        fclose ( file );
    }
    else
    {
        perror ( name ); /* why didn't the file open? */
    }
}
int main(void)
{
    printf("=====Hello_World======\n");
    Hello_Wold();
    printf("Success create Hello_World.txt \n");
    //FileSize();
    //printf( "Votre taille est  = %f \n", FileSize());
    printf("=====Print_Doc======\n");
    Print_Doc("Hello_Wolrd.txt");
    printf("=====Print_At_Position======\n");
    Print_at_Position("Hello_Wolrd.txt",2);
    printf("=====Get_Lines======\n");
    get_Lines("Hello_Wolrd.txt",0);
    return 0;
}
