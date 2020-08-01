---
title: "Adhoc"
author: Durgesh

html:
  offline: false

export_on_save:
  html: true

print_background: true
---

### Forming a Magic Square

* for 3x3 matrix sum is 15
* center element should be 5
* total magic squares are 8

All of the posted solutions require pre-computing all eight magic squares. I wanted to offer a few suggestions on how to generate them -- or at least show what I did.

We can start with two observations: a) the "middle" of any 3x3 magic square must be 5, and b) the "magic sum" must be 15.

Here's a way to think about the "magic sum". The sum of numbers 1-9 is 45. The three horizontal rows will include all 9 numbers (and thus sum to 45). And since there are three rows, each row will sum to 45/3 = 15.

It takes a bit of pen and paper to see that the middle must be 5 (or at least, it took me some trial and error). But once we know these two things, we can think in terms of the 4 "pairs" that can go on opposite sides of the 5:
```
1 and 9
2 and 8
3 and 7
4 and 6
```
So for example, if 4 goes Top/Left, we know that 6 must go Bottom/Right (since the "magic sum" must be 15, and 5 is in the middle)

A bit more on pen/paper will show that only two of these pairs fit in the "corners":
```
2 and 8
4 and 6
```
The other two pairs must be "wedged" inside the corner paris (e.g., top middle, bottom middle). And once we set our four corners, there is only 1 way to place the rest of the numbers.

This is enough to show that there are 8 magic matrices. There are 4 possible ways to place the 4 and 6 pair (the 4 could go in Top/Left, Top/Right, Bottom/Right, Bottom/Left). Then once we place the 4 and 6, there are two different ways we could place the 2 and 8.

To acutally generate these matrices, I started with one "seed" (which happend to be the first magic matrix I found):
```
[4 3 8]
[9 5 1]
[2 7 6]
```
From ths seed, we can rotate it clockwise 4 times (so the 4 appears in each corner). And then from each rotation, we can place the remaining digits either clockwise, or counterclockwise around the 5 (going counterclockwise is equivalent to getting the "mirror" of the matrix along a diagonal).

These two matrix manipulations are also great helper functions to have handy on other problems.