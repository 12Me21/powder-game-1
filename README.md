# Compiling
Note: __requires linux__  

Run `make` to compile.  
(If your cpu has multiple cores, you can can make it faster if you pass `-j -l` to make.)

## Optimizations
set environment variable `opt` to compile with optimizations enabled (this will take longer)

## Compiling for windows
__requires `gcc-mingw-w64`__  
To compile for windows, set env var `win` before calling make.

## Examples
- `make` - linux build: `pg1`
- `opt=1 make` - optimized linux build: `fast-pg1`
- `win=1 make` - windows build: `pg1.exe`
- `win=1 opt=1 make` - optimized windows build: `fast-pg1.exe`
