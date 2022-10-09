# Compiling
```
make
```

# Test case
```
> cd ./build/bin/
> echo "Hello, world!" > source.c
> ./cp
[ERROR] cp: missing file operand
cp [src] [dst]
> ./cp source.c
[ERROR] cp: missing file operand
cp [src] [dst]
> ./cp source.c source.c
[ERROR] cp: 'source.c' and 'source.c' are the same file
> ./cp source.c ./source.c 
[ERROR] cp: 'source.c' and './source.c' are the same file
> ./cp source.c dest.c
> cat dest.c
Hello, world!

```
