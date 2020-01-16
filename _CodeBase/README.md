# _CodeBase
This directory contains base source code to be used with assignments as described in relevant assignment description. 
You're not allowed to make any changes to these base sources, which needs to be used in their initial states. 

The folder **``_Libs/``** contains some general libraries to support you in the development of solutions. One of these 
libraries is **``memstat.hpp``** which many of you already are familiar with from previous courses. It helps keeping track 
of allocations and deallocations of memory and the library is included by default in each **``main()``** for every assignment.  

Always consider using smart pointers wherever possible but in cases where dynamic allocation in necessary the tool helps
you to avoid memory leaks. **memstat** was originally created by Mikael Nilsson, but has undergone some updates prior the
start of this course in order to properly enable cross platform support. 