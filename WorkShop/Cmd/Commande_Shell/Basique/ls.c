#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#include<pwd.h>
#include <grp.h>
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
int main(int argc, char *argv[])
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
    if (argc>1)
    {
    if (isEqual(argv[1],"ls-l"))
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
        printf("%4d ",fileStat.st_size);
        c=ctime(&fileStat.st_mtime);
        for(i=4;i<=15;i++)
            printf("%c",c[i]);
        printf(" ");
        printf("%s\n",myfile->d_name);
    }
    }
    else if (isEqual("ls",argv[1]))
    {
        while((myfile=readdir(mydir))!=NULL)
        {
           stat(myfile->d_name,&fileStat);
           printf("%s    ",myfile->d_name);
        }
    }
    }
    //printf("%c   ",*((argv[0])+2));
    printf("%s\n",argv[1]);
    printf("%zu\n",len(argv[1]));
    closedir(mydir);
        
    return 0;
}
