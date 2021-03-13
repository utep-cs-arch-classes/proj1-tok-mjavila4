Project 1: Tokenizer
====================
# User-Input:

This lab uses memory allocation and user-input to correctly and efficiently store space seperated tokens.
The command prompt is ready for user-input when the '$' is present.
The user may input any string of characters along with non-characters in the given command line.
All implementations of tokenize function as normal and provide the correct outputs.

# History:

This code stores all user-input in a singly-linked-list data structure.
To view a past input line, use command '!3' for example to output previous line 3.
While all definitons function as normal, the combining of the interface and history structure contain many
errors and as a result, are not present in final code. The major flaw within this code is the lack of ability to
run multiple input buffers inside of main while also passing them as parameters and while loop comparisons.
