# Compiling
```
make
```

# Test case
```
> cd build/bin/
> echo "Hello, world!" > source.c
> ./mv
[ERROR] mv: missing file operand
mv [src] [dst]
> ./mv source.c 
[ERROR] mv: missing file operand
mv [src] [dst]
> ./mv source.c source.c 
[ERROR] mv: 'source.c' and 'source.c' are the same file
> ./mv source.c ./source.c 
[ERROR] mv: 'source.c' and './source.c' are the same file
> ./mv source.c dest.c
> cat dest.c 
Hello, world!
> ls
dest.c  mv
```
