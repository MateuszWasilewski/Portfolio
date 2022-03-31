This folder holds new version of my personal backpropagation project.

It can be used either by writing new *.cpp file which utilizes the Model class.

In order to run with minimal overhead just run file run.sh which 
- compiles main.cpp file,
- runs it,
- deletes executable file.


Function WriteWeights completely overwrites file with given name so use it carefully.

For me each training epoch with given example model took arour ~ 1.5 s but your mileage may vary.

Notes after a while.
Code code be improved by compiling cpp files independently and linking them after all. (using makefile / cmake)
Code clarity and comments could be improved.