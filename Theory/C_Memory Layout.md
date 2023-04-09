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