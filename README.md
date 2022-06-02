# 42Seoul_minishell
## Introduction
The existence of shells is linked to the very existence of IT. At the time, all coders agreed
that communicating with a computer using aligned 1/0 switches was seriously
irritating. It was only logical that they came up with the idea to communicate with
a computer using interactive lines of commands in a language somewhat close
to english.
With Minishell, you’ll be able to travel through time and come back to problems
people faced when Windows didn’t exist.
## Mandatory part
Your shell should:
- Not interpret unclosed quotes or unspecified special characters like \ or;.
- Not use more than one global variable, think about it and be ready to explain why
you do it.
- Show a prompt when waiting for a new command.
- Have a working History.
- Search and launch the right executable (based on the PATH variable or by using
relative or absolute path)
- It must implement the builtins:
  - echo with option -n
  - cd with only a relative or absolute path
  - pwd with no options
Minishell As beautiful as a shell
  - export with no options
  - unset with no options
  - env with no options or arguments
  - exit with no options
- ’ inhibit all interpretation of a sequence of characters.
- " inhibit all interpretation of a sequence of characters except for $.
- Redirections:
  - < should redirect input.
  - \> should redirect output.
  - “<<” read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!
  - “>>” should redirect output with append mode.
- Pipes | The output of each command in the pipeline is connected via a pipe to the input of the next command.
- Environment variables ($ followed by characters) should expand to their values.
- $? should expands to the exit status of the most recently executed foreground
pipeline.
- ctrl-C ctrl-D ctrl-\ should work like in bash.
- When interactive:
  - ctrl-C print a new prompt on a newline.
  - ctrl-D exit the shell.
  - ctrl-\ do nothing.
 
Anything not asked is not required.
For every point, if you have any doubt take bash as a reference.
### Make
```shell
make
make fclean
make re
...
```
### Usage
```shell
./minishell
minishell$ echo hi
minishell$ ls -l | grep m | more
...
```
