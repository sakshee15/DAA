#DAA Lab Assignment 1: Basic Problem Solving
There are two problem you need to solve for this assignment.
__Problem 1__
 write a program in C language with the following functionalities.
- The program keeps on accepting positive integers as input.
- if input number is -1, program should output largest number among last 10 numbers
entered.
- if input number is -2, program should output average of last 10 numbers entered.
- if input number is -3 then quit.
Try to give best possible algorithm in terms of the time and the space complexity. Com-
ment about the time and the space complexity of your algorithm.
__Problem 2__
Imagine you have a collection of n cards numbered from 1 to n. You need to arrange the
cards in a pile so that
- If you put the topmost card of the pile to the bottom and fetch the next card from
top of the pile it should be card numbered 1. The fetched cards are kept aside and not
inserted in the pile again.
- At any subsequent step you put the topmost card of the pile at the bottom and fetch
out the next card from the top, it should be the card numbered i + 1 where i is the
card fetched out in the last step.
- In this fashion every time you fetch out a card from the pile as described above till all
cards in the pile are exhausted.
Write a C program which takes n as input and outputs the sequence of card numbers in
the pile. For example if n = 5 the correct sequence of the cards is 3; 1; 5; 2; 4. How will you
generalize your algorithm if instead of one card in every step top k cards are moved to the
bottom of the pile instead of just 1 card?
 
 
