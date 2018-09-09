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
void man_mkdir()
{
    printf("MKDIR(1)                  BSD General Commands Manual                 MKDIR(1)\n");
    printf("\n");
    printf("NAME\n");
    printf("mkdir -- make directories\n");
    printf("\n");
    printf("SYNOPSIS\n");
    printf("mkdir [-pv] [-m mode] directory_name ...\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("The mkdir utility creates the directories named as operands, in the order\n");
    printf("specified, using mode rwxrwxrwx (0777) as modified by the current\n");
    printf("umask(2).\n");
    printf("\n");
    printf("The options are as follows:\n");
    printf("\n");
    printf("    -m mode\n");
    printf("        Set the file permission bits of the final created directory to\n");
    printf("        the specified mode.  The mode argument can be in any of the for-\n");
    printf("        mats specified to the chmod(1) command.  If a symbolic mode is\n");
    printf("        specified, the operation characters ``+'' and ``-'' are inter-\n");
    printf("        preted relative to an initial mode of ``a=rwx''.\n");
    printf("\n");
    printf("    -p      Create intermediate directories as required.  If this option is\n");
    printf("        not specified, the full path prefix of each operand must already\n");
    printf("        exist.  On the other hand, with this option specified, no error\n");
    printf("        will be reported if a directory given as an operand already\n");
    printf("        exists.  Intermediate directories are created with permission\n");
    printf("        bits of rwxrwxrwx (0777) as modified by the current umask, plus\n");
    printf("        write and search permission for the owner.\n");
    printf("\n");
    printf("    -v  Be verbose when creating directories, listing them as they are created.\n");
    printf("\n");
    printf("        The user must have write permission in the parent directory.\n");
    printf("\n");
    printf("        DIAGNOSTICS\n");
    printf("        The mkdir utility exits 0 on success, and >0 if an error occurs.\n");
    printf("\n");
    printf("        SEE ALSO\n");
    printf("        rmdir(1)\n");
    printf("\n");
    printf("        COMPATIBILITY\n");
    printf("        The -v option is non-standard and its use in scripts is not recommended.\n");
    printf("\n");
    printf("        STANDARDS\n");
    printf("        The mkdir utility is expected to be IEEE Std 1003.2 (``POSIX.2'') compat-ible.\n");
    printf("\n");
    printf("        HISTORY\n");
    printf("        A mkdir command appeared in Version 1 AT&T UNIX.\n");
}
void man_touch()
{
    printf("TOUCH(1)                  BSD General Commands Manual                 TOUCH(1)\n");
    printf("       NAME                                                                    \n");
    printf("       touch -- change file access and modification times                       \n");
    printf("       SYNOPSIS\n");
    printf("       touch [-A [-][[hh]mm]SS] [-acfhm] [-r file] [-t [[CC]YY]MMDDhhmm[.SS]]\n");
    printf("       file ...\n");
    printf("\n");
    printf("       DESCRIPTION\n");
    printf("       The touch utility sets the modification and access times of files.  If\n");
    printf("       any file does not exist, it is created with default permissions.\n");
    printf("\n");
    printf("       By default, touch changes both modification and access times.  The -a and\n");
    printf("       -m flags may be used to select the access time or the modification time\n");
    printf("       individually.  Selecting both is equivalent to the default.  By default,\n");
    printf("       the timestamps are set to the current time.  The -t flag explicitly spec-\n");
    printf("       ifies a different time, and the -r flag specifies to set the times those\n");
    printf("       of the specified file.  The -A flag adjusts the values by a specified\n");
    printf("       amount.\n");
    printf("\n");
    printf("       The following options are available:\n");
    printf("\n");
    printf("       -A      Adjust the access and modification time stamps for the file by\n");
    printf("       the specified value.  This flag is intended for use in modifying\n");
    printf("       files with incorrectly set time stamps.\n");
    printf("\n");
    printf("       The argument is of the form ``[-][[hh]mm]SS'' where each pair of\n");
    printf("       letters represents the following:\n");
    printf("\n");
    printf("       -       Make the adjustment negative: the new time stamp is\n");
    printf("       set to be before the old one.\n");
    printf("       hh      The number of hours, from 00 to 99.\n");
    printf("       mm      The number of minutes, from 00 to 59.\n");
    printf("       SS      The number of seconds, from 00 to 59.\n");
    printf("\n");
    printf("       The -A flag implies the -c flag: if any file specified does not\n");
    printf("       exist, it will be silently ignored.\n");
    printf("\n");
    printf("      -a      Change the access time of the file.  The modification time of the\n");
    printf("       file is not changed unless the -m flag is also specified.\n");
    printf("\n");
    printf("       -c      Do not create the file if it does not exist.  The touch utility\n");
    printf("       does not treat this as an error.  No error messages are displayed\n");
    printf("       and the exit value is not affected.\n");
    printf("\n");
    printf("       -f      Attempt to force the update, even if the file permissions do not\n");
    printf("       currently permit it.\n");
    printf("\n");
    printf("       -h      If the file is a symbolic link, change the times of the link\n");
    printf("       itself rather than the file that the link points to.  Note that\n");
    printf("       -h implies -c and thus will not create any new files.\n");
    printf("\n");
    printf("       -m      Change the modification time of the file.  The access time of the\n");
    printf("       file is not changed unless the -a flag is also specified.\n");
    printf("\n");
    printf("       -r      Use the access and modifications times from the specified file\n");
    printf("       instead of the current time of day.\n");
    printf("\n");
    printf("       -t      Change the access and modification times to the specified time\n");
    printf("       instead of the current time of day.  The argument is of the form\n");
    printf("       ``[[CC]YY]MMDDhhmm[.SS]'' where each pair of letters represents\n");
    printf("       the following:\n");
    printf("\n");
    printf("       CC      The first two digits of the year (the century).\n");
    printf("       YY      The second two digits of the year.  If ``YY'' is\n");
    printf("       specified, but ``CC'' is not, a value for ``YY''\n");
    printf("       between 69 and 99 results in a ``CC'' value of 19.\n");
    printf("       Otherwise, a ``CC'' value of 20 is used.\n");
    printf("       MM      The month of the year, from 01 to 12.\n");
    printf("       DD      the day of the month, from 01 to 31.\n");
    printf("       hh      The hour of the day, from 00 to 23.\n");
    printf("       mm      The minute of the hour, from 00 to 59.\n");
    printf("       SS      The second of the minute, from 00 to 61.\n");
    printf("\n");
    printf("       If the ``CC'' and ``YY'' letter pairs are not specified, the val-\n");
    printf("       ues default to the current year.  If the ``SS'' letter pair is\n");
    printf("       not specified, the value defaults to 0.\n");
    printf("\n");
    printf("       EXIT STATUS\n");
    printf("       The touch utility exits 0 on success, and >0 if an error occurs.\n");
}
void man_ls ()
{
    printf("LS(1)                     BSD General Commands Manual                    LS(1)\n");
    printf("\n");
    printf("NAME\n");
    printf("ls -- list directory contents\n");
    printf("\n");
    printf("SYNOPSIS\n");
    printf("ls [-ABCFGHLOPRSTUW@abcdefghiklmnopqrstuwx1] [file ...]\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("For each operand that names a file of a type other than directory, ls\n");
    printf("displays its name as well as any requested, associated information.  For\n");
    printf("each operand that names a file of type directory, ls displays the names\n");
    printf("of files contained within that directory, as well as any requested, asso-\n");
    printf("ciated information.\n");
    printf("\n");
    printf("If no operands are given, the contents of the current directory are dis-\n");
    printf("played.  If more than one operand is given, non-directory operands are\n");
    printf("displayed first; directory and non-directory operands are sorted sepa-\n");
    printf("rately and in lexicographical order.\n");
    printf("\n");
    printf("The following options are available:\n");
    printf("\n");
    printf("-@      Display extended attribute keys and sizes in long (-l) output.\n");
    printf("\n");
    printf("-1      (The numeric digit ``one''.)  Force output to be one entry per\n");
    printf("line.  This is the default when output is not to a terminal.\n");
    printf("\n");
    printf("-A      List all entries except for . and ...  Always set for the super-\n");
    printf("    user.\n");
}
void man_cat ()
{
    printf("CAT(1)                    BSD General Commands Manual                   CAT(1)\n");
    printf("\n");
    printf("NAME\n");
    printf("cat -- concatenate and print files\n");
    printf("\n");
    printf("SYNOPSIS\n");
    printf("cat [-benstuv] [file ...]\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("The cat utility reads files sequentially, writing them to the standard\n");
    printf("output.  The file operands are processed in command-line order.  If file\n");
    printf("is a single dash (`-') or absent, cat reads from the standard input.  If\n");
    printf("file is a UNIX domain socket, cat connects to it and then reads it until\n");
    printf("EOF.  This complements the UNIX domain binding capability available in\n");
    printf("inetd(8).\n");
    printf("\n");
    printf("       The options are as follows:\n");
    printf("\n");
    printf("       -b      Number the non-blank output lines, starting at 1.\n");
    printf("\n");
    printf("       -e      Display non-printing characters (see the -v option), and display\n");
    printf("               a dollar sign (`$') at the end of each line.\n");
    printf("\n");
    printf("       -n      Number the output lines, starting at 1.\n");
    printf("\n");
    printf("       -s      Squeeze multiple adjacent empty lines, causing the output to be\n");
    printf("               single spaced.\n");
    printf("\n");
    printf("       -t      Display non-printing characters (see the -v option), and display\n");
    printf("               tab characters as `^I'.\n");
    printf("\n");
    printf("       -u      Disable output buffering.\n");
    printf("\n");
    printf("       -v      Display non-printing characters so they are visible.  Control\n");
    printf("               characters print as `^X' for control-X; the delete character\n");
    printf("               (octal 0177) prints as `^?'.  Non-ASCII characters (with the high\n");
    printf("               bit set) are printed as `M-' (for meta) followed by the character\n");
    printf("               for the low 7 bits.\n");
    printf("\n");
    printf("        EXIT STATUS\n");
    printf("        The cat utility exits 0 on success, and >0 if an error occurs.\n");
}
void man_rm()
{
    printf("RM(1)                     BSD General Commands Manual                    RM(1)\n");
    printf("\n");
    printf("NAME\n");
    printf("rm, unlink -- remove directory entries\n");
    printf("\n");
    printf("SYNOPSIS\n");
    printf("rm [-dfiPRrvW] file ...\n");
    printf("unlink file\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("The rm utility attempts to remove the non-directory type files specified\n");
    printf("on the command line.  If the permissions of the file do not permit writ-\n");
    printf("ing, and the standard input device is a terminal, the user is prompted");
    printf("(on the standard error output) for confirmation.\n");
    printf("\n");
    printf("        The options are as follows:\n");
    printf("\n");
    printf("        -d     Attempt to remove directories as well as other types of\n");
    printf("               files.\n");
    printf("\n");
    printf("        -f     Attempt to remove the files without prompting for confirma-\n");
    printf("               tion, regardless of the file's permissions.  If the file does\n");
    printf("               not exist, do not display a diagnostic message or modify the\n");
    printf("               exit status to reflect an error.  The -f option overrides any\n");
    printf("               previous -i options.\n");
    printf("\n");
    printf("        -i     Request confirmation before attempting to remove each file,\n");
    printf("               regardless of the file's permissions, or whether or not the\n");
    printf("               standard input device is a terminal.  The -i option overrides\n");
    printf("               any previous -f options.\n");
    printf("\n");
    printf("\n        -P     Overwrite regular files before deleting them.  Files are \n");
    printf("               overwritten three times, first with the byte pattern 0xff,\n");
    printf("               then 0x00, and then 0xff again, before they are deleted.\n");
    printf("\n");
    printf("        -R     Attempt to remove the file hierarchy rooted in each file\n");
    printf("               argument.  The -R option implies the -d option.  If the -i\n");
    printf("               option is specified, the user is prompted for confirmation\n");
    printf("               before each directory's contents are processed (as well as\n");
    printf("               before the attempt is made to remove the directory).  If the\n");
    printf("               user does not respond affirmatively, the file hierarchy\n");
    printf("               rooted in that directory is skipped.\n");
    printf("\n");
    printf("         -r    Equivalent to -R.\n");
    printf("\n");
    printf("         -v    Be verbose when deleting files, showing them as they are\n");
    printf("               removed.\n");
    printf("\n");
    printf("         -W    Attempt to undelete the named files.  Currently, this option\n");
    printf("               can only be used to recover files covered by whiteouts.\n");
    printf("\n");
}
void man_ln()
{
    printf("LN(1)                     BSD General Commands Manual                    LN(1)\n");
    printf("\n");
    printf("NAME\n");
    printf("link, ln -- make links\n");
    printf("\n");
    printf("SYNOPSIS\n");
    printf("ln [-Ffhinsv] source_file [target_file]\n");
    printf("ln [-Ffhinsv] source_file ... target_dir\n");
    printf("link source_file target_file\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("\n");
    printf("    The ln utility creates a new directory entry (linked file) which has\n");
    printf("    the same modes as the original file.  It is useful for maintaining\n");
    printf("    multiple copies of a file in many places at once without using up\n");
    printf("    storage for the ``copies''; instead, a link ``points'' to the origi-\n");
    printf("    nal copy.  There are two types of links; hard links and symbolic\n");
    printf("    links.  How a link ``points'' to a file is one of the differences\n");
    printf("    between a hard and symbolic link.\n");
    printf("\n");
    printf("The options are as follows:\n");
    printf("\n");
    printf("    -F    If the target file already exists and is a directory, then\n");
    printf("          remove it so that the link may occur.  The -F option should be\n");
    printf("          used with either -f or -i options.  If none is specified, -f\n");
    printf("          is implied.  The -F option is a no-op unless -s option is\n");
    printf("          specified.\n");
    printf("\n");
    printf("    -h    If the target_file or target_dir is a symbolic link, do not\n");
    printf("          follow it.  This is most useful with the -f option, to replace\n");
    printf("          a symlink which may point to a directory.\n");
    printf("\n");
    printf("    -f    If the target file already exists, then unlink it so that the\n");
    printf("          link may occur.  (The -f option overrides any previous -i\n");
    printf("          options.)\n");
    printf("\n");
    printf("    -i    Cause ln to write a prompt to standard error if the target\n");
    printf("          file exists.  If the response from the standard input begins\n");
    printf("          with the character `y' or `Y', then unlink the target file so\n");
    printf("          that the link may occur.  Otherwise, do not attempt the link.\n");
    printf("          (The -i option overrides any previous -f options.)\n");
    printf("\n");
    printf("    -n    Same as -h, for compatibility with other ln implementations.\n");
    printf("\n");
    printf("    -s    Create a symbolic link.\n");
    printf("\n");
    printf("    -v    Cause ln to be verbose, showing files as they are processed.\n");
}
void man_cd()
{
    printf("BUILTIN(1)                BSD General Commands Manual               BUILTIN(1)\n");
    printf("\n");
    printf("NAME\n");
    printf("    builtin, !,  . , @, {, }, alias, alloc, bg, bind, bindkey, break,\n");
    printf("    breaksw, builtins, case, cd, chdir, command, complete, continue, default,\n");
    printf("    dirs, do, done, echo, echotc, elif, else, end, endif, endsw, esac, eval,\n");
    printf("    exec, exit, export, false, fc, fg, filetest, fi, for, foreach, getopts,\n");
    printf("    glob, goto, hash, hashstat, history, hup, if, jobid, jobs, kill, limit,\n");
    printf("    local, log, login, logout, ls-F, nice, nohup, notify, onintr, popd,\n");
    printf("    printenv, pushd, pwd, read, readonly, rehash, repeat, return, sched, set,\n");
    printf("    setenv, settc, setty, setvar, shift, source, stop, suspend, switch,\n");
    printf("    telltc, test, then, time, times, trap, true, type, ulimit, umask,\n");
    printf("    unalias, uncomplete, unhash, unlimit, unset, unsetenv, until, wait,\n");
    printf("    where, which, while -- shell built-in commands\n");
    printf("\n");
    printf("SYNOPSIS\n");
    printf("builtin [-options] [args ...]\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("        Shell builtin commands are commands that can be executed within the run-\n");
    printf("        ning shell's process.  Note that, in the case of csh(1) builtin commands,\n");
    printf("        the command is executed in a subshell if it occurs as any component of a\n");
    printf("        pipeline except the last.\n");
    printf("\n");
    printf("        If a command specified to the shell contains a slash ``/'', the shell\n");
    printf("        will not execute a builtin command, even if the last component of the\n");
    printf("        specified command matches the name of a builtin command.  Thus, while\n");
    printf("        specifying ``echo'' causes a builtin command to be executed under shells\n");
    printf("        that support the echo builtin command, specifying ``/bin/echo'' or\n");
    printf("        ``./echo'' does not.\n");
    printf("\n");
    printf("        While some builtin commands may exist in more than one shell, their oper-\n");
    printf("        ation may be different under each shell which supports them.  Below is a\n");
    printf("        table which lists shell builtin commands, the standard shells that sup-\n");
    printf("        port them and whether they exist as standalone utilities.\n");
    printf("\n");
    printf("        Only builtin commands for the csh(1) and sh(1) shells are listed here.\n");
    printf("        Consult a shell's manual page for details on the operation of its builtin\n");
    printf("        commands.  Beware that the sh(1) manual page, at least, calls some of\n");
    printf("        these commands ``built-in commands'' and some of them ``reserved words''.\n");
    printf("        Users of other shells may need to consult an info(1) page or other\n");
    printf("        sources of documentation.\n");
    printf("\n");
    printf("        Commands marked ``No**'' under External do exist externally, but are\n");
    printf("        implemented as scripts using a builtin command of the same name.\n");
}
void man(char arg[])
{
    if (isEqual (arg,"ls"))
    {
        man_ls();
    }
    else if(isEqual(arg,"cat"))
    {
        man_cat();
    }
    else if (isEqual(arg,"cd"))
    {
        man_cd();
    }
    else if (isEqual(arg,"rm"))
    {
        man_rm();
    }
    else if (isEqual(arg,"touch"))
    {
        man_touch();
    }
    else if (isEqual(arg,"ln"))
    {
        man_ln();
    }
    else if (isEqual(arg,"mkdir"))
    {
        man_mkdir();
    }
    else
    {
        printf("Command not found");
    }
}
int main (void)
{
    man("ls");
    return 1;
}
