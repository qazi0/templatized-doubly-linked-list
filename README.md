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
