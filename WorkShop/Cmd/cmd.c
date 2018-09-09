#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#include<pwd.h>
#include <grp.h>
#include <string.h>
# include <sys/dir.h>
#include "man.h"
char PWD[1024];
char PATH[1024];
int presentET (char *argv[], int len)
{
    for (int i= 1; i<len;i++)
    {
        if (isEqual(argv[i],"ET"))
        {
            return 1;
        }
    }
    return 0;
}
int presentOU (char *argv[], int len)
{
    for (int i= 1; i<len;i++)
    {
        if (isEqual(argv[i],"OU"))
        {
            return 1;
        }
    }
    return 0;
}
int presenceCommande (char *s)
{
    if((isEqual(s,"ls")) || (isEqual(s,"cd")) || (isEqual(s,"ln")) || (isEqual(s,"echo")) || (isEqual(s,"mkdir")) || (isEqual(s,"touch")) || (isEqual(s,"cat")) || (isEqual(s,"rm")) || (isEqual(s,"mv")))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int FileIsExist(char name[])
{
    if (access(name,0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void rm (char name[])
{
    if ((FileIsExist(name)))
    {
        int status;
        status=remove(name);
        if(status==0)
        {
            printf("Succes delete %s\n", name);
        }
        else
        {
            printf("Unsuccessfull\n");
        }
    }
    else
    {
        printf("File Not exist %s \n",name);
    }
}
void mv (char name[])
{
    DIR *directory;
    struct dirent *entry;
    struct stat file_stat;
    char buffer[1024] = {0};
    directory = opendir(name);
    if ( directory == NULL )
    {
        fprintf(stderr, "cannot open directory %s\n", name);
    }
    while ( (entry = readdir(directory)) != NULL )
    {
        if ( strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0 ) {
            continue;
        }
        snprintf(buffer, 1024, "%s/%s", name, entry->d_name);

        stat(buffer, &file_stat);


        if ( S_ISREG(file_stat.st_mode) )
        {
            remove(buffer);
        }
        else if ( S_ISDIR(file_stat.st_mode) )
        {
            mv(buffer);
        }
    }
    printf("Succes for delete %s \n",name);
    closedir(directory);
    remove(name);
}
void ls (char com[])
{
    struct passwd *pw;
    struct group *gp;
    DIR *mydir;
    char *c;
    int i;
    struct dirent *myfile;
    struct stat fileStat;
    mydir=opendir(".");
    stat(".",&fileStat);
    if (len(com)>0)
    {
        if (isEqual(com,"ls-l"))
        {
            while((myfile=readdir(mydir))!=NULL)
            {
                stat(myfile->d_name,&fileStat);
                printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
                printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
                printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
                printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
                printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
                printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
                printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
                printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
                printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
                printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
                printf(" ");
                printf("%d ",fileStat.st_nlink);
                pw=getpwuid(fileStat.st_uid);
                printf("%s ",pw->pw_name);
                gp=getgrgid(fileStat.st_gid);
                printf("%s ",gp->gr_name);
                printf("%4lld ",fileStat.st_size);
                c=ctime(&fileStat.st_mtime);
                for(i=4;i<=15;i++)
                    printf("%c",c[i]);
                printf(" ");
                printf("%s\n",myfile->d_name);
            }
        }
        else if (isEqual("ls",com))
        {
            while((myfile=readdir(mydir))!=NULL)
            {
                stat(myfile->d_name,&fileStat);
                printf("%s    ",myfile->d_name);
            }
            printf("\n");
        }
    }
    closedir(mydir);
}
void touch(char name[])
{
    FILE* fichier = NULL;
    if (!(FileIsExist(name)))
    {
        fichier = fopen(name, "w");
        printf("Succes create %s \n",name);
    }
    else
    {
        printf("File Already Existe\n");
    }
    fclose(fichier);
}
void cat (char name[])
{
    FILE *file = fopen ( name, "r" );
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */

        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            printf("%s", line); /* write the line */
        }
        fclose (file);
    }
    else
    {
        perror (name); /* why didn't the file open? */
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
            fclose (file);
        }
        else
        {
            perror (name1); /* why didn't the file open? */
        }
        fclose(fichier);
    }
}
void cd(char  args[]){
  if (chdir(args) < 0){
		perror("minsh");
	}
	getcwd(PWD, sizeof(PWD));	// Update present working directory
  printf("%s\n",PWD);
}
void echo(char  args[]){
		printf("%s", args);
    printf("\n");
}
void ln(char fil[], char lien[])
{
  FILE* fichier = NULL;
  fichier = fopen(lien, "w");
  if (fichier!=NULL)
  {
    FILE* f =fopen(fil,"r");
    if (f!=NULL)
    {
      char line [ 128 ]; /* or other suitable maximum line size */

      while ( fgets ( line, sizeof line, f ) != NULL ) /* read a line */
      {
          fputs(line, fichier); /* write the line */
      }
      fclose (f);
    }
  }
  fclose(fichier);
}
void exeCommand(char *argv[], int argc)
{
    if (argc==1)
    {
        printf("Put name of one commande\n");
    }
    else if (argc==2 && !(presentET(argv,argc)))
    {
        if (isEqual(argv[1],"ls") || isEqual(argv[1],"ls-l"))
            ls(argv[1]);
    }
    else if (argc==3 && !(presentET(argv,argc)))
    {
        // rm
        if (isEqual(argv[1],"rm"))
        {
            rm(argv[2]);
        }
        //mv
        else if(isEqual(argv[1],"mv"))
        {
            mv(argv[2]);
        }
        //touch
        else if (isEqual(argv[1],"touch"))
        {
            touch(argv[2]);
        }
        //mkdir
        else if(isEqual(argv[1],"mkdir"))
        {
            mkdir(argv[2],S_IRWXU);
            printf("Succes Create dir %s\n",argv[1]);
        }
        //cat
        else if(isEqual(argv[1],"cat"))
        {
            cat(argv[2]);
        }
        //man
        else if (isEqual(argv[1],"man"))
        {
            man(argv[2]);
        }
        //cd
        else if (isEqual(argv[1],"cd"))
        {
            cd(argv[2]);
        }
        //echo
        else if (isEqual(argv[1],"echo"))
        {
            echo(argv[2]);
            //printf("\n");
        }
        else
        {
            printf("Command not found\n");
        }
    }
    else if (argc==4 && !(presentET(argv,argc)))
    {
        //ln
        if (isEqual(argv[1],"ln"))
        {
            ln(argv[2],argv[3]);
        }
    }
    else if (argc==5 && !(presentET(argv,argc)))
    {
        //cat>
        if (isEqual(argv[3],">") && isEqual(argv[1],"cat"))
        {
            Cat2(argv[2],argv[4]);
        }
    }
    else if((argc>=3) && (presentET(argv,argc)))
    {
        if ((presenceCommande(argv[1])) && ((presenceCommande(argv[3]))  || (presenceCommande(argv[4]) || (presenceCommande(argv[5]))  ))       )
        {
            // premier parte du &&
            if (isEqual(argv[1],"ls")) ls(argv[1]);
            else if (isEqual(argv[1],"rm")) rm(argv[2]);
            else if (isEqual(argv[1],"mv")) mv(argv[2]);
            else if (isEqual(argv[1],"touch")) touch(argv[2]);
            else if (isEqual(argv[1],"cat")) cat(argv[2]);
            else if (isEqual(argv[1],"cd")) cd(argv[2]);
            else if (isEqual(argv[1],"echo")) echo(argv[2]);
            else if (isEqual(argv[1],"ln")) ln(argv[2],argv[3]);
            else if (isEqual(argv[1],"man")) man(argv[2]);

            // deuxieme partie du &&
            if(argc>3)
            {
            if (presenceCommande(argv[3]))
            {
                if (isEqual(argv[3],"ls")) ls(argv[3]);
                else if (isEqual(argv[3],"rm")) rm(argv[4]);
                else if (isEqual(argv[3],"mv")) mv(argv[4]);
                else if (isEqual(argv[3],"touch")) touch(argv[4]);
                else if (isEqual(argv[3],"cat")) cat(argv[4]);
                else if (isEqual(argv[3],"cd")) cd(argv[4]);
                else if (isEqual(argv[3],"echo")) echo(argv[4]);
                else if (isEqual(argv[3],"ln")) ln(argv[4],argv[5]);
                else if (isEqual(argv[3],"man")) man(argv[4]);
            }
            }
            if(argc>4)
            {
            if (presenceCommande(argv[4]))
            {
                if (isEqual(argv[4],"ls")) ls(argv[4]);
                else if (isEqual(argv[4],"rm")) rm(argv[5]);
                else if (isEqual(argv[4],"mv")) mv(argv[5]);
                else if (isEqual(argv[4],"touch")) touch(argv[5]);
                else if (isEqual(argv[4],"cat")) cat(argv[5]);
                else if (isEqual(argv[4],"cd")) cd(argv[5]);
                else if (isEqual(argv[4],"echo")) echo(argv[5]);
                else if (isEqual(argv[4],"ln")) ln(argv[5],argv[6]);
                else if (isEqual(argv[4],"man")) man(argv[5]);
            }
           }
           if(argc>5)
           {
            if (presenceCommande(argv[5]))
            {
                if (isEqual(argv[5],"ls")) ls(argv[5]);
                else if (isEqual(argv[5],"rm")) rm(argv[6]);
                else if (isEqual(argv[5],"mv")) mv(argv[6]);
                else if (isEqual(argv[5],"touch")) touch(argv[6]);
                else if (isEqual(argv[5],"cat")) cat(argv[6]);
                else if (isEqual(argv[5],"cd")) cd(argv[6]);
                else if (isEqual(argv[5],"echo")) echo(argv[6]);
                else if (isEqual(argv[5],"ln")) ln(argv[6],argv[7]);
                else if (isEqual(argv[5],"man")) man(argv[6]);
            }
           }
        }
    }
    else
    {
        printf("Command not found\n");
    }
}
int main(int argc, char *argv[])
{
    int i=0;
    exeCommand(argv,argc);
    return 1;
}
