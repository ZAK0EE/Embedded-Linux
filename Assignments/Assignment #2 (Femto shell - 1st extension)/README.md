# Creating static library & compiling
```
cd libfiles
gcc -c *.c
ar -rs libfemtomath.a *.o
cd ..
gcc -o femto_shell  main.c -I ./include/ -lfemtomath -L ./libfiles/

```

# Creating dynamic library & compiling
```
cd libfiles
gcc -c -fPIC *.c
gcc -shared *.o -o libfemtomath.so
cd .. 
gcc -o femto_shell  main.c -I ./include/ -lfemtomath -L ./libfiles/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libfiles

```
# Test case
```
./femto_shell
Enter your command > Hello
You said: Hello
Enter your command > rand
1980884315
Enter your command > fact
Enter a number: 5
Result is: 120
Enter your command > Hello
You said: Hello
Enter your command > fib
Enter a number: 7
The sequence is: 0, 1, 1, 2, 3, 5, 8
Enter your command > exit
Good bye!

```
