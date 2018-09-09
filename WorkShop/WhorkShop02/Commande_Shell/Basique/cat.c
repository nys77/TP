#include <stdio.h>
#include <stdlib.h>
size_t len (char *s)
{
    size_t len =0;
    for (size_t i =0 ; *(s+i)!='\0' ; i++ )
    {
        len++;
    }
    return len;
}
int isEqual(char *s , char *z)
{
    if (len(s)!=len(z))
        return 0;
    for (size_t i =0 ; i< len(s) ; i++ )
    {
        if (*(s+i)!=*(z+i))
        {
            return 0;
        }
    }
    return 1;
}
void Print_Doc (char name[])
{
    FILE *file = fopen ( name, "r" );
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            printf("%s", line); /* write the line */
        }
        fclose ( file );
    }
    else
    {
        perror ( name ); /* why didn't the file open? */
    }
}
void Cat2(char name1[], char name2[])
{
    int status;
    status=remove(name2);
    FILE* fichier = NULL;
    fichier = fopen(name2, "w");
    if (fichier != NULL)
    {
        FILE *file = fopen ( name1, "r" );
        if ( file != NULL )
        {
            char line [ 128 ]; /* or other suitable maximum line size */
            
            while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
            {
                fputs(line, fichier); /* write the line */
            }
            fclose ( file );
        }
        else
        {
            perror (name1); /* why didn't the file open? */
        }
        fclose(fichier);
    }
}
int main(int argc, char *argv[])
{
 if (isEqual(argv[1],"cat"))
 {
  if (argc ==3)
  {
      if (isEqual(argv[1],"cat"))
      {
          Print_Doc(argv[2]);
      }
  }
  else if (argc==2 && (isEqual((argv[1]),"cat")))
    {
        printf("Put name of the file after cat\n");
    }

  else if (argc==5)
  {
      if (isEqual(argv[3],">"))
      {
        Cat2(argv[2],argv[4]);
      }
  }
  else if (argc==4)
  {
      Print_Doc(argv[2]);
      printf()
  }
  else
  {
      printf("Put good syntaxe like cat+NameFile\n");
  }
 }
}
