# templatized-doubly-linked-list
C++ Implementation of a doubly-linked list data structure, made generic by use of template classes.

Dynamic Templatized Linked List v1.0
By Siraj Qazi
-------------------------------------
Changelog Updated on Sept 15, 2018


Build 1.0:
Sept 15, 2018, 1:23AM PST

   - Initial build
   - First stable version
   - Implemented all standard linked-list operations

Build 2.0:
Sept 15, 2018, 2:49AM PST

   - Fixed all index out-of-bounds errors, particularly in the search functions.
   - [FEATURE UPDATE] Added Continuous Input Mode: Now data can be added continuously to the list with new nodes being created dynamically at run-time. 
   Note: CIM requires the number of entries in advance that will be continuously input.
   - UI Changes
   - Minor bug fixes
   
   
   Build 3.0:
Sept 15, 2018 1:16PM PST

   - [FEATURE UPDATE] File I/O introduced. Now linked lists can be written to and read from a file.
   - File data validity check: A file with string data will not be read when in <INT> or <FLOAT> mode of      operation.
   - Separated complete list deletion to an independent deleteList() Function.
   - Cleaned main() function to do only minimal tasks.
   - UI Changes
   - Bug Fixes



Build 3.1
Sept 16, 2018 10:01PM PST

   - [ARCHITECTURAL CHANGE] Now a doubly-linked list. Nodes can be traversed from start to end or from end to start.
   To use the doubly-linked list functions (like reverse-traversal), #include the doubly_linked_list.h file in the Source.cpp file.
   - Added function to print list in reverse (Due to the previous pointer)
   - Fixes and improvements
   
   

Build 4.2φ
Nov 5, 2018 10:26PM PST

   - Added Input and Check header files
   - Made crash prone (user is now bound to give correct input as per input type selected)
   - Added an object of type Input and a function void input(Generic, char) in nested class LinkedList of templated Generic class Node in doubly_linked_list.h file
   - std::cin replaced with function input() at several locations in doubly_linked_list.h file
   - Minor Bug Fixes
