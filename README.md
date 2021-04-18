# School_projects

### PSU

    ```diff
    + My_ls:
    ```
        Compilation:
                    make
                    ./my_ls
        How_to_use:
                  ./my_ls  ==  cmd "ls" in shell
                  ./my_ls -l == cmd "ls -l" in shell
        This project is able to deal with "-l" "-a" etc.
        
    MiniShell 1&2:
          Compilation:
                      make
                      ./mysh
          This programme is able to use "cd", "tree", "ls", "env" as commands.
          And MiniShell2 is able to deal with the:
          •semicolons(;)
          •pipes(|)
          •redirections(>, <, <<, >>) in a shell.
          
          I mainly used the "fork" to build a son progress then output the result we get from computer
          example:
  ![Alt Text](https://github.com/claraxuxu/School_projects/blob/master/exemples/minishell1.png)
          
    42sh:
        Compilation:
                    make
                    ./42sh
        This is a Unix SHELL.
        My program could deal with almost all the commands that you usually use in a shell.
        
        •spaces and tabs
        •$PATH and environment,•errors and return value
        •redirections (‘<’, ‘>’, ‘<<’ and ‘>>’)
        •pipes (‘|’)
        •builtins: cd, echo, exit, setenv, unsetenv,•separators: ‘;’, ‘&&’, ‘||’
        
        Expemple:. /42sh
            42sh>  cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo “OK”
    navy:
        Compilation:
                    make
                    ./navy pos1
                    ./navy [pid of first] pos2
        This is the Battleship game, play on two terminals, connect with the pid
        Here is an exemple:
![Alt Text](https://github.com/claraxuxu/School_projects/blob/master/exemples/navy.png)
        
          
