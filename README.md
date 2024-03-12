# C - Simple Shell
![snaphot.PNG](./snapshot.PNG)
## Compilation
- The shell will be compiled this way:

```c 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Testing
- In interactive mode:

```
$ ./hsh
($) ls
Tools  README.md  env.c  execute_command.c  main.h  search_in_file_path.c  shell.c  split_line.c
($)
($) ./Tools/bin/pid
PPID: 106
PID: 109
($) exit
$
```
- In non interactive mode:

```c
$ echo "ls" | ./hsh
Tools  README.md  env.c  execute_command.c  main.h  search_in_file_path.c  shell.c  split_line.c
$
$ cat test_ls_2
ls
$
$ cat test_ls_2 | ./hsh
Tools  README.md  env.c  execute_command.c  main.h  search_in_file_path.c  shell.c  split_line.c

$
```
## Issues
+ There are some several errors and issues to fix and one of the notified one is the `segmentation fault` when you run and built in `env` command.
+ Many of the features similar to the standard shells such as `bash`, `sh`, etc have not yet been implemented.

**Note:** This is the first version of the implementation, any collaboration to improvement of this project is warmly and humbly welcomed!
