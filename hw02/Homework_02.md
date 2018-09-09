# Homework 02

This homework includes short answer questions and a programming assignment. The short answer
questions are worth 5 points each. The programming assignment is worth 30 points. The short
answer questions may cover topics that are in the text, but were not covered in the lectures. Push
a preliminary version of the programming assignment to Github before Wednesday’s class. Push
the final version of your source code, Makefile, and a text file with your short answer questions to
Github before 5PM Friday.

1. What is the difference between `int` and `const int` ?
	- just like java's `final` specifier, `const` make the int variable unchangable.
2. what's the difference between function definition and function declaration? 
  	- function definition: actual code of written c/c++ method 
  	- function declaration: one line of code where programmer *declare* the function before it is being used, to let compiler know that the function exists.
3. Why would you use unsigned integer?
  	- to store larger number compared to signed int
4. What is wrong with following C++ code? How would you fix it?
```cpp
int sum;
for (int i=0; i<1000; ++i){
    sum += 1;
}
printf("Sum of 0 to 999 is %d\n", sum);
```

int sum is not initialized to zero, since c++ initialization of variable will take random values from memory and assign it to new variable, zero needs to be manually assgined. 
instead, `int sum = 0;`

5. What is wrong with following C++ code? How would you fix it?
```cpp
int n = 1;
if(n = 0) {
print("n is zero\n");
```
change `if (n=0) to if (n==0),` so it is comparison instead of assignment.

6. How do you find out how many bytes are used to store a particular datatype in C++? How many bytes are used to store char, short, int, and long variables on your system? What operating system are you using?

- data size can be found out by using `size(var_name)` in c++.
	- char: 1
	- short: 2
	- int: 4
	- long: 8
- Operating of my choice is Linux Ubuntu 18.04.1 LTS  
