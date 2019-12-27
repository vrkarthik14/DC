# DC

DC lab programs externals final list packages

sudo apt install libopenmp-dev

sudo apt install libopenmpi-dev

sudo apt install libgd-dev

compiling

gcc -fopenmp filename.c

attach -lm -lgd incase math.h or gd.h is used

mpicc filename.c

mpirun -np 6 ./a.out
