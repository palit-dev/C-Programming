# C Resources

## C Memory Layout

A C Program when executed consists of six memory components in order of higher to lower addresses:

1. **Command Line Arguments:** It is used to store command line arguments passed to the program while execution.
2. **Stack:** It is used to store function call and local function variables (excluding static) in accordance with LIFO. It usually grows down from higher to lower address.
3. **Heap:** It is used for dynamic memory allocation. It grows in the direction opposite to Stack i.e., from lower to higher address.
4. **Uninitialized Data Segment:** This stores all the variables like global and static that have been declared but not initialized. Every data in Uninitialized Data Segment or bss (Block started by Symbol) is initialized to 0 or null pointer.
5. **Initialized Data Segment:** This stores all the variables including Global and Static that has been declared and initialized.
6. **Code Segment:** The binary file created after compilation of C program consists of Instructions. These instructions are stored ini the Code segment with only read-only permission.



## Static Variable
A Static variable is allocated memory in the Data segment and not in the Stack. As a result, it preserves its value even after the control goes out of scope. 

The primary difference of static w.r.t global is that eventhough static preserves its value but the value cannot be accessed out of scope. However, global variables can be accessed from anywhere within the code.

## Dangling Pointer
Dangling Pointer occurs when a pointer is pointing to a data that has been deallocated from the memory. In such a case, the Program may show undesirable value and crash causing Segmentation fault.

## Memory Leak
If Memory allocated to a Pointer is not released after usage, then during each execution the program keeps consuming memory ultimately causing Out of Memory (OOM) and kernel panic. This is called Memory Leak.

## Enumeration
Enumeration or Enum in C is a special kind of data type defined by the user. It consists of constant integrals or integers that are given names by a user. The use of enum in C to name the integer values makes the entire program easy to learn, understand, and maintain by the same or even different programmer.

By default, the value of the first element in enum is 0. However, it can be changed explicitly. If only the first element value is set, the next elements are assigned consequtive values.

An enumerator variable can be allocated only the elements that it contains. otherwise, it raises error. Enumerators can also be used in switch cases.

```c
#include <stdio.h>  

enum days{Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};  

int main()
{
    // We can create a enumerator variable
    days e = Monday;

    // printing the values of weekdays
    for(int i=Sunday;i<=Saturday;i++)
        printf("%d, ",i);

    // Using enumerator in switch case
    switch(e)
    {
        case Monday: printf("Monday"); break;
        case Tuesday: printf("Tuesday"); break;
        default: printf("Some day");
    }
    return 0;

}
```

## Union

A union is a type of structure that can be used where the amount of memory used is a key factor. Union is a user-defined datatype. All the members of union share same memory location. Size of union is decided by the size of largest member of union.

```c
#include <stdio.h>
#include <string.h>

union Data {
   int i;
   float f;
} data, data1;

int main( ) {
   printf( "Memory size occupied by data : %d\t%d", sizeof(data), sizeof(data1));
   return 0;
}
```