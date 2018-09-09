#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
//Supprime un dossier plein vide
void remove_directory(char const *name)
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
            remove_directory(buffer);
        }
    }
    closedir(directory);
    remove(name);
}
int main (int argc, char *argv[])
{
    if (argc==2)
    {
        remove_directory(argv[1]);
        printf("Success Delete dir %s\n",argv[1]);
    }
    else
    {
        printf("Put argument\n");
    }
    return 0;
}
