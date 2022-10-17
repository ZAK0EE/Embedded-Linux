# This is an attempt of creating a shell core which is extensible for more!
# Compiling
```
make
```
# Run
```
./build/bin/Femto_Shell 
```

# Features
- The shell has a handful of built-in commands, you can see a brief about them using:
```
Please enter your command > help
```

- Supports for local variables and exporting them to the environment variables
```
Please enter your command > a=24 
Please enter your command > b=test
Please enter your command > set
local_var[0]: a = 24
local_var[1]: b = test
Please enter your command > export a
Please enter your command > env
```

- Supports executing external commands:
```
Please enter your command > echo pretty good
pretty good
Please enter your command > ls -l /home
total 24
drwx------  2 root root 16384 أغس 27 22:11 lost+found
drwxr-xr-x  2 1001 1001  4096 سبت  3 10:56 test
drwxr-xr-x 22 ziad ziad  4096 أكت 17 17:17 ziad
```
- Supports multi-commands
```
Please enter your command > echo it supports multi-command; a=1000;set;            ls 
it supports multi-command
local_var[0]: a = 1000
build  include	libfiles  Makefile  README.md  src
```
