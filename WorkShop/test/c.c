# include <stdio.h>
# include <stdlib.h>
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
/*void exeCommand(char *argv[], int argc)
{
    if (argc==1)
    {
        printf("Put name of one commande\n");
    }
    else if (argc==2)
    {
        if (isEqual(argv[1],"ls") || isEqual(argv[1],"ls-l"))
            ls(argv[1]);
    }
    else if (argc==3)
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
    else if (argc==4)
    {
        //ln
        if (isEqual(argv[1],"ln"))
        {
            ln(argv[2],argv[3]);
        }
    }
    else if (argc==5)
    {
        //cat>
        if (isEqual(argv[3],">") && isEqual(argv[1],"cat"))
        {
            Cat2(argv[2],argv[4]);
        }
    }
    else if((argc>3) && (presentET(argv,argc)))
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
    else
    {
        printf("Command not found\n");
    }
}*/
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

int main(int argc, char *argv[])
{
    if((argc>3) && (presentET(argv,argc)))
    {
        if ((presenceCommande(argv[1])) && ((presenceCommande(argv[3]))  || (presenceCommande(argv[4]) || (presenceCommande(argv[5]))  ))       )
        {
            // premier parte du &&
            if (isEqual(argv[1],"ls")) printf("s");
            else if (isEqual(argv[1],"rm"))printf("s");
            else if (isEqual(argv[1],"mv"))printf("s");
            else if (isEqual(argv[1],"touch"))printf("s");
            else if (isEqual(argv[1],"cat"))printf("s");
            else if (isEqual(argv[1],"cd"))printf("s");
            else if (isEqual(argv[1],"echo"))printf("s");
            else if (isEqual(argv[1],"ln"))printf("s");
            else if (isEqual(argv[1],"man"))printf("s");
            
            // deuxieme partie du &&
            if(argc>3)
            {
            if (presenceCommande(argv[3]))
            {
                if (isEqual(argv[3],"ls"))printf("s");
                else if (isEqual(argv[3],"rm"))printf("s");
                else if (isEqual(argv[3],"mv"))printf("s");
                else if (isEqual(argv[3],"touch"))printf("s");
                else if (isEqual(argv[3],"cat"))printf("s");
                else if (isEqual(argv[3],"cd"))printf("s");
                else if (isEqual(argv[3],"echo"))printf("s");
                else if (isEqual(argv[3],"ln"))printf("s");
                else if (isEqual(argv[3],"man"))printf("s");
            }
            }
            if (argc>4)
            {
            if (presenceCommande(argv[4]))
            {
                if (isEqual(argv[4],"ls"))printf("s");
                else if (isEqual(argv[4],"rm"))printf("s");
                else if (isEqual(argv[4],"mv"))printf("s");
                else if (isEqual(argv[4],"touch"))printf("s");
                else if (isEqual(argv[4],"cat"))printf("s");
                else if (isEqual(argv[4],"cd"))printf("s");
                else if (isEqual(argv[4],"echo"))printf("s");
                else if (isEqual(argv[4],"ln"))printf("s");
                else if (isEqual(argv[4],"man"))printf("s");
            }
            }
            if (argc>5)
            {
            if (presenceCommande(argv[5]))
            {
                if (isEqual(argv[5],"ls"))printf("s");
                else if (isEqual(argv[5],"rm"))printf("s");
                else if (isEqual(argv[5],"mv"))printf("s");
                else if (isEqual(argv[5],"touch"))printf("s");
                else if (isEqual(argv[5],"cat"))printf("s");
                else if (isEqual(argv[5],"cd"))printf("s");
                else if (isEqual(argv[5],"echo"))printf("s");
                else if (isEqual(argv[5],"ln"))printf("s");
                else if (isEqual(argv[5],"man"))printf("s");
            }
            }
        }
    }
    //printf("%d\n",presentET(argv,argc));
    return 1;
}
