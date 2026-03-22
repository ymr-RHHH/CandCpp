

# C++ from Scratch

[【从零开始学C++ CoffeeBeforeArch】](https://www.bilibili.com/video/BV1kWmWYhEBK/?share_source=copy_web&vd_source=dd23e37f34be8abeabaf405e07d31ab0)



## What is C++?

- C++ is a compiled language that is statically typed

- Best reference: https://cppreference.com
- We can find projects of this course at https://github.com/coffeebeforearch



- Starting with code is a good idea!

  - type this code with vim at a Linux OS to `main.cpp`
    ```cpp
    // first cpp program 
    
    // main function is the core of all c++ projects, every c++ program will start at the main function
    
    // Function is just a named body of code. Whenever we call this function by whatever name we
    // have given, it will execute all the code inside of the function body(everything within curly brackets)
    
    int main()   
  {
        return 0;  
    }
    // the return value of main is typically used to signify whether or not a program completed 
    // successfully. Zero means the program completed without errors.
    // We can use `echo $?` to get the return value for the last executable we ran.
    ```
  
  - back to the shell, and execute `gcc main.cpp -o main` , then we'll get a output executable file named `main`
  - use `./main` to call the main



## Printing

- Printing is a foundtional operation that we want to perform inside of our programs.

  - Implement a logger
  - Printing some information of our application

- Fortunately, we don't have to reinvent the wheel with printing. We can use some thing that are built into out **C++ standard library** , it provide something like：

  - Data structures
  - Algorithms (work with the data structure)

- Also **C++ standard library** has provided a means for input and output

  - input and output to the screen
  - input and output to files

- Using `std::cout` to print some characters to the screen

  ```c++
  // print.cpp
  #include<iostream> // before we use std::cout , we need to include its definition.
                                    // before we use somthing , we need to know what that thing is.
  // In fact, compilation has a couple of steps to it:
  // - Preprocessing
  //   - At this step, the job of the software is find these header files and paste them inside of this file.
  //   - `gcc -E print.cpp -o print.ii `
  // - Compilation
  // - Assembly
  // - Linking
  
  int main()
  {
      std::cout << "hello world \n";   // std:: is a name space, we will learn more about it in the subsequent courses.
      return 0;
  }
  ```

  



## Variables

- Our programs are filled with values, and it would be convenient if we had a way to assign names to those values that would help us write more expressive code!

  In cpp, we can do this though **Variables**

  Variables allow us to give a value a partcular name. 

  - How to define a variable
  - How to initialize them
  - How to play around with them

  https://cppreference.com/w/cpp/language/types.html

  ```cpp
  // variables.cpp
  
  int main()
  {
      // Before we use a variable, we must define it
      // Remember, all of values in c++ have an associated type, all variables are just names of values
      
      int var1;  // defination of var1 
      var1 = 10; // give a value for var1
      int var2 = 7; // We can also define and initialize a variable at same time
      int sum = var1 + var2;
      
      double d_var1 = 10.9; //  10.9 this value is stored by default using double
      // if we want store a decimal by float we can use:
      float f_var1 = 11.2f;
      
      // In c++, we can use atomatic type deduction
      // This just falls along the line that we shouldn't be talling our compiler things that it already know
      // It's just kind of waste of time
      auto auto_var = 10.1; // double
      auto auto_var = 999; // int
      // Auto is a good syntactic sugar, and makes writing code a whole lot nicer without changing 
      // the actual behavior 
      // For example, if we start to working with more complex typed, like iterators, instead of having to 
      // writing out entire iterator name every single time, just an auto is ok.
      
      // But when we use auto, we must initialize and define the variable at the same time.
      // If just define variable and not initialize , the compiler will not know what type it is.
      // auto var;  //error
  }
  ```

  

## Conditional Statements

- We don't want to execute every single line of code inside of our programs. We often want our programs to be able to make decisions.

  In C++(or in other programming languages), we can use conditional statements to achieve this arm.  

  - `if` ... `else`...

  ```c++
  // condition.cpp
  
  int main()
  {
      int a=1,b=3;
  
      if(a<b) // it will compare a and b, and return true or false
      {
          a = a+b;  // if true, just execute this code segment
      }
      else
      {
          b = a+b;  // if false, just execute this code segment
      }
  }
  ```

  



## std::array

- std::array is just a container from **standard library**

- https://cppreference.com/w/cpp/container/array.html

- In our programs, we often want to group our values into the same variable. For example, we maybe collecting data over time (maybe temperatures), and we don't want to creat a  unique variable for every single measurement, so we don't want to have 365 different floating or double numbers for those temperatures. We'd ideally like to collect them together into a singal variable, and we can access individual components of. 

  ```c++
  #include<array> //before we use array, we shoule include the defination of it
  #include<iostream>
  int main()
  {
      std::array<int,3> my_array;
      my_attay = {1,2,3};
  
      return 0;
  }
  ```

  

## for loops

- In our programs, we often need to perform some action multiple times:

  - Add some numbers over and over
  - Print an array
  - Matrix multiplication 

  We can do that through loops. And for loops is just a kind of loops.

- In C++, we have two ways to write a for loop

  - The first type is the C-style for loop, its syntax is exactly the same as that in the C language.

    ```cpp
    #include<iostream>
    int main()
    {
        // add 1 to 10
        int sum = 0;
        for(int i = 1; i<=10; i++)
        {
            sum += i;
        }
        std::cout << "value of sum:"<<sum<<"\n";
    }
    ```

  - The second one is Python-style for loops (range-based for loops) , since C++11 we can use it.

    It's used for operating over a range of values such as all elements in a container. So the place where we often use range-based for loop is with STL library containers, such as `std::array`. **It's really nice for interating over these containers**, and it makes code a bit more simple and expressice. 

    ```cpp
    #include<iostream>
    #include<array>
    
    int main()
    {
      std::array<int,5> my_array = {1,2,3,4,5};
      
      // We just want to extract some integer from our array, but if we 
      // use tradtional C-style for loop, we must use another counter,
      // and it maybe makes the problem of memory out-of-bounds access.
      // But range-based for loop is more easy:
      for(int value : my_array)
      {
        std::cout<< value << " ";
      }
    
      return 0;
    }
    ```

    



## while loops

> For loops allows us to express what we want to iterate over the range of values.
>
> But in fact, we don't always know how many iterations we want to run a loop. Maybe the number of iterations is based on some sort of external input. So we want to just continue running some piece of code until some condition happens. And we can express that in C/C++ by while loops

- while loop

  ```cpp
  #include<iostream>
  
  int main()
  {
      int work_item = 10;
      
      while(work_item > 0) // if the condition is true, we will still repeat excuting this code
      {
          std::cout<< "work item:"<<work_item<<"\n";
          work_item -= 1;
      }
      
      return 0;
  }
  ```

- do-while loop

  ```cpp
  #include<iostream>
  
  int main()
  {
      int work_item = 10;
      
      do
      {
          std::cout<< "work item:"<<work_item<<"\n";
          work_item -= 1;
      }while(work_item > 0); // This code will be executed at least once, regardless of whether the 
                                         // condition is true or false
      return 0;
  }
  ```

  

## Function

- Function just allows us to give a name to a sequence of statements that we want to execute.

- Why we need function?

  - We often want to repeatedly perform some action inside of our program, but maybe we don't want to perform that action inside if a loop. 
  - We want to avoid the code duplication. We don't need similar code do similar things.

  ```cpp
  #include<iostream>
  #include<array>
  
  void print_array(std::array<int,3> my_array)  // this is indeed a bit dull, and the solution will be 
  {                                                                       //covered in the subsequent lessons.
      std::cout<< "array is: \n";
      for(int value : my_array)
      {
          std::cout<< value << " ";
      }
      std::cout<< "\n";
  }
  
  
  int sum_array(std::array<int,3> my_array)
  {
      int sum = 0;
      for(int value : my_array)
      {
          sum += value;
      }
      return sum;
  }
  
  int main()
  {
      std::array<int,3> myArray = {3,4,5};
      print_array(myArray);
      std::cout<<"sum of this array is "<<sum_array(myArray)<<"\n";
      
      return 0;
  }
  ```



## Function Overloading

> Now, one of questions is that sometimes comes up is how do we handle cases where we have  functions that are doing the similar thing, but maybe working on different types or having a different numbers of parameters?
>
> Do we need to creat a new name for each of these function and keep track different names for functions that are essentially performing the same kind of logical operation?
>
> In C we should do this, but in C++ we can say NO! Because we have function overloading (with an overloading resolution), where we rely on our compiler to choose the right version of a function for us.

- https://cppreference.com/w/cpp/language/overload_resolution.html

- The core idea here is that we're relying on our compiler to look up the right function for us and that's going to be on this thing called our function signature. So our compiler is figure out which function to call based on a combination of say our function name and the number in order of our parameters inside of our parameter list. 

  ```cpp
  #include<iostream>
  #include<array>
  
  void print_array(std::array<float,5> my_array)
  {
    for(auto value : my_array)
    {
      std::cout <<"float  :"<< value << " ";
    }
    std::cout << "\n";
  }
  
  int main()
  {
    std::array<int,5> int_array = {1,2,3,4,5};
    std::array<float,5> float_array = {1.1f,2.2f,3.3f,4.4f,5.5f};
  
    print_array(int_array);     // we don't need to creat another function name
    print_array(float_array);
  
    return 0;
  }
  ```

 

## Function Templates

> In the previous class, we learned function overloading and resolution. But we hace noticed that we were starting to get some code duplication from our functions themselves: We had two version of print_array function, but both of these functions had the same function body, so we just had this kind of wasted effort here of  writing multiple functions that we essentially doing the same thing (The only difference is in their parameter list).

- https://cppreference.com/w/cpp/language/templates.html

- Now, we often address this kind of code duplication related to functions by **function templates**. 

- Functions allows us to write a template of a function rather than concrete implementations for a specific type. 

  > We can write a template and tell our compiler "Hey! I want the version of this function where the type is an array of int, or an array of floats, or an array of doubles ", instead of having to manually write out these different forms of the function. 

  ```cpp
  // function_template.cpp
  #include<iostream>
  #include<array>
  #include<typeinfo>
  
  // We use the key word "template" to delcare this function is a template
  template<typename T>
  void print_array(T my_array) // T is just a placeholder
  {
    for(auto value : my_array)
    {
      std::cout << typeid(value).name() << ":" << value << " ";
    }
    std::cout << "\n";
  }
  
  int main()
  {
    std::array<int,5> int_array = {1,2,3,4,5};
    std::array<float,5> float_array = {1.1f,2.2f,3.3f,4.4f,5.5f};
    
    //  Explicitly specifying template parameters
    print_array<std::array<int,5>>(int_array);
    print_array<std::array<float,5>>(float_array);
      
    std::cout << "\n";
    // Maybe after C++11， we could implicitly specified template parameters
    print_array(int_array);
    print_array(float_array);
    
    return 0;
  }
  ```

  - But in C++20 , we can simplify the syntax

    ```cpp
    #include<iostream>
    #include<array>
    #include<typeinfo>
    
    void print_array(auto my_array)
    {
      for(auto value : my_array)
      {
        std::cout << typeid(value).name() << ":" << value << " ";
      }
      std::cout << "\n";
    }
    
    int main()
    {
      std::array<int,5> int_array = {1,2,3,4,5};
      std::array<float,5> float_array = {1.1f,2.2f,3.3f,4.4f,5.5f};
      
      print_array(int_array);
      print_array(float_array);
      
      return 0;
    }
    ```

    This is only available in c++20, or if we turn on or enable concepts. And when we compile this file, we should use "gcc filename.cpp -lstdc++ -o filename -std=c++20" 



## Template Specialization

> We can use function template to avoid manually writting the duplicate code for multiple  types. But here is a question: Sometimes , we don't want to have the exact same function body for every single type. Sometimes there's a case where we need a specialization of this function.
>
> We can through template specialization to solve this problem.

- https://en.cppreference.com/w/cpp/language/function_template.html

```cpp
#include<iostream>
#include<array>
#include<typeinfo>

void print_array(auto my_array)
{
  for(auto value : my_array)
  {
    std::cout << typeid(value).name() << ":" << value << " ";
  }
  std::cout << "\n";
}

// We need to handle the case of array<int, 5>
template<>
void print_array(std::array<int,5> my_array)
{
  for(auto value : my_array)
  {
    std::cout << typeid(value).name() << ":" << value << " ";
  }
  std::cout << "  special case <int,5>\n";
}

int main()
{
  std::array<int,5> int_array = {1,2,3,4,5};
  std::array<float,5> float_array = {1.1f,2.2f,3.3f,4.4f,5.5f};
  
  
  print_array(int_array);
  print_array(float_array);
  
  return 0;
}
```



## Iterators















