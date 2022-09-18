# Creating static library
```
make libfemtomath.a --directory=./libfiles/ --file=../Makefile
```

# Creating dynamic library
```
make libfemtomath.so --directory=./libfiles/ --file=../Makefile
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libfiles
```

# Compiling
```
make LIBS=femtomath LIB_PATH=./libfiles/
```


# Test case
```
./Femto_Shell
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
