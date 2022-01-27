# CIS-343-Homework-1
Homework assignment 1 for CIS 343 at Grand Valley State University


A vector (or arraylist) is an automatically resizing data structure.  For this assignment we will be creating a lightweight vector.  It should automatically increase in size but will not decrease.


I have provided the following files:

* **lite_vector.h** - this is the interface for the vector.  Read the signatures and comments to learn how to use the data structure, and how it works.
* **student_lite_vector.c** - this is where your code will go.  Note there is a static function in here (one that is visibile only in this file).  This is a way in C to make private any functions you don't wish users of your code to have access to.  Here we don't want the users to call lv_resize() manually, so we make it only visible within the *.c file.
* **acutest.h** - a unit testing framework included completely in a header file.
* **test.c** - unit tests.  Make sure these all pass to ensure basic functionality.  Note that passing all tests does not mean you automatically get 100%; you need to write your code as robust as possible.  Memory problems and other issues can still result in reduced points.
* **main.c** - a sample file that shows how to use the vector.

You should complete the student_lite_vector.c file.  Make **NO** changes to the *.h files or my test file.


Compile the *.c files together and run the resulting executable to run the tests.  Do not attempt to compile the main.c and test.c files together, they both have main methods and only one may be linked at once.


Notes:

* Feel free to look up C functions that might help you (memcpy might be a good one...).  Look up documentation, not StackOverflow articles about it (at least at first).
* Don't go looking for how to do this online.  Learn how to do it.  If you can understand these problems you will begin to understand a lot of other topics as well.  Break it down into small chunks.
* Talk to one another.  Share your code on this one.  Show each other what works and what doesn't.  But comment that in your source and know that I may ask you to explain any part.
* The goal is understanding, not just a grade.
* Read the comments.  Don't start until you have full understanding of the provided code.

Grading:

* You must pass all tests - 60 points
* All functions must check that the parameters given are valid and must return valid values
* You must not have any errors or warnings - 10 points
* You must comment your code according to the GV style guide - 10 points
* You must also pass any tests I did not provide - 10 points

Due Date:

The first class period two weeks after assigned in class.
