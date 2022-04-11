## Matrix multiplication and exponectiation with Java / C++

Comparison of runtime performance in Java and C++

Both programs perform the same operation of Matrix operations
- Matrix multipication.
- Matrix addition.
- Multiply matrix by a constant.

Those operations were used in order to compute matrix Exp(A),
using Series expantion for function exp up to a given sum element.

Programs where written to perform the given task as similarly as possible, 
taking language specification.
Memory management is more difficult in C++ but it result in better performace overall as shown in results.

Benchmark specification:
- linux version - Linux 5.13.0-35-generic x86_64
- Java version - javac 11.0.14
- C++ version - c++ (Ubuntu 11.2.0-7ubuntu2) 11.2.0

Programs where tested on randomly generated files which match following specifiation:
single integer with operations accuracy.
two integers informing about matrix dimentions.
doubles / integers holding starting value of given matrix.

## Results
Tests where conducted using -O3 flag for C++
And with Just In Time Compilation for Java as well as without.
Given result come from time command for linux "real"

| Test name   |      C++      |  Java with JIT | Java without JIT
|:----------|:-------------:|:------:|:------:|
| test1.in |  0,002s | 0,161s | 0,167s|
| test2.in |  0,002s | 0,136s | 0,204s|
| test3.in |  0,006s | 0,223s | 0,327s|
| test4.in |  0,053s | 0,369s | 1,242s|
| test5.in |  0,851s | 1,257s | 17,621s|
| test6.in |  1,226s | 1,924s | 36,287s|
| test7.in |  1,806s | 1,892s | 35,936s|
| test8.in |  1,613s | 4,334s | 38,753s|
| test9.in |  1,429s | 2,522s | 48,717s|
    
In conclusion, on small test, JVM runtime accounted for about 0,16s
During bigger tests c++ performed around 40 - 60 % better in runtime.
JIT for Java results in drastic time reduction for tasks completed many times.