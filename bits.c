/*
 * CS:APP Data Lab
 *
 * Kiana Harkema 106102554
 *
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y)
{
  return ~(~x & ~y);
}
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void)
{
  //Using a 32 bit int

  //Test word == 0101 0101 (even bits are initialized to 1)
  int testWord = 0x55;

  //Test Word is shifted 8 bits to the left to get 01010101 00000000
  testWord = testWord | testWord << 8;

  //When or statement is complete, the 0's trailing to the right are changed to 0101010101
  // Repeat w/ 16 to get the 32 bits

  testWord = testWord | testWord << 16;

  return testWord;
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
  //Negative 1 (two's complement) is represented in binary as 1111, which is not(0000)
  //Hex value is 0x0

  int testBinary = 0x0;
  return ~(testBinary);

}
/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x)
{
  int testBits;
  int allOddsToTrue = 0xaa;


  allOddsToTrue = (allOddsToTrue << 8) | allOddsToTrue;
  allOddsToTrue = (allOddsToTrue << 16) | allOddsToTrue;

  //Now have a number with all odd bits set to true (1)

  //Perform or against all odds to the number x -> results should be 1111 1111 1111 1111 if the all even bits are 0
  testBits = allOddsToTrue | x;

  //Once switching all the bits, the testbits should all be 0, if not return 0
  testBits = ~testBits;

  return !testBits;


}
/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x)
{

  int allOddsToTrue = 0xaa;

  allOddsToTrue = (allOddsToTrue << 8) ^ allOddsToTrue;
  allOddsToTrue = (allOddsToTrue << 16) ^ allOddsToTrue;

  //Now have a 32 bit number with each odd bit represented by a 1

  //And the mask against x to determine if any odd bit is 1 -> if a odd bit is 1, performing a logical negation will return a 0 (false)
  //However, this means the function should return 1 (true)

  return !!(x&allOddsToTrue);

}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m)
{
    //Getting bit position for n
    int posN = n << 3;

    //Getting bit posiition for m
    int posM = m << 3;

    //Store 8 bits in 0xff mask (all ones)

    //Store bytes separetely within mask and clear to all 0's by anding against original number x
    int store = 0xff;
    int nByte = (store << posN)&x;
    int mByte = (store << posM)&x;

    //Combine the bytes
    int combine = (store << posN) | (store << posM);

    //Now need to shift bytes back to "swapped" position
    nByte  = (nByte >> posN)&store;
    mByte = (mByte >> posM)&store;
    nByte = nByte << posM;
    mByte  = mByte << posN;

    //Part of bit that didn't change
    combine  = ~combine & x;

    return combine| mByte | nByte;



}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
  int sum = x+y;

  //Get sign bit for x
  int xSign = x >> 31;

  //Get sign bit for y
  int ySign = y >> 31;

  //Get sign bit for sum of x and y
  int sumSign = sum >> 31;

  //Check whether x and y have the same sign w/ ex or statement
  //Will return true if the signs are the same
  int isSameSign = !(xSign ^ ySign);

  //Check if sumSign and signs for both x and y are the same
  //Will return true if the signs are the same and there is no overflow
  int checkOverflow = (xSign ^ sumSign);

  //If they are the same signs and there is no overflow, return true
  return !(isSameSign & checkOverflow);




}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  int mask = !x + ~0x00;

  //Case 1: x != 0 and y should be returned -> z should be masked out
  //Case 2: x == 0 and x should be returned -> y should be masked out

  return ((~mask) & z) | ((mask) & y);
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */

int isAsciiDigit(int x)
{
  //Negative sign only occurs if x is not an ascii digit
  int negativeSign = 1<<31;

  //Or to get negative 0x39 with a negative sign
  //Complment to
  int upperLimit = ~(negativeSign | 0x39);

  int lowerLimit = ~0x30;

  //Add x to the limits and check the sign

  upperLimit = negativeSign & (upperLimit+x) >> 31;
  lowerLimit = negativeSign & (lowerLimit+1+x) >> 31;

  //If either condition is true, the condition is negative and this or statement would be false
  return !(upperLimit | lowerLimit);
}
/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c)
{
    //Store bit position of n
    int posN = n << 3;

    //Store n in mask 0xff
    int store = 0xff << posN;

    //Place c in correct position in the mask
    int placeC = c << posN;

    return (x & ~store) | placeC;
}
/* reverseBits - reverse the bits in a 32-bit integer,
              i.e. b0 swaps with b31, b1 with b30, etc
 *  Examples: reverseBits(0x11111111) = 0x88888888
 *            reverseBits(0xdeadbeef) = 0xf77db57b
 *            reverseBits(0x88888888) = 0x11111111
 *            reverseBits(0)  = 0
 *            reverseBits(-1) = -1
 *            reverseBits(0x9) = 0x90000000
 *  Legal ops: ! ~ & ^ | + << >> and unsigned int type
 *  Max ops: 90
 *  Rating: 4
 */
int reverseBits(int x)
{


  //Swapping even and odd bits
  int reverseMask = 0x55;
  int reverseMask2 = 0x33;
  int reverseMask3 = 0x0f;
  int reverseMask4 = 0x00;
  int reverseMask5 = 0xff;


  reverseMask = reverseMask << 8 | reverseMask;
  reverseMask = reverseMask << 16 | reverseMask;
  x  = ((x >> 1) & reverseMask) | ((x & reverseMask) << 1);

  //Swapping bit pairs
  reverseMask2 = reverseMask2 << 8 | reverseMask2;
  reverseMask2 = reverseMask2 << 16 | reverseMask2;
  x = ((x >> 2) & reverseMask2) | ((x & reverseMask2) << 2);

  //Swapping nibbles
  reverseMask3 = reverseMask3 << 8 | reverseMask3;
  reverseMask3 = reverseMask3 << 16 | reverseMask3;
  x = ((x >> 4) & reverseMask3) | ((x & reverseMask3) << 4);


  //Swapping bytes
  reverseMask4 = reverseMask4 << 8 | 0xff;
  reverseMask4 = reverseMask4 << 16 | reverseMask4;
  x = ((x >> 8) & reverseMask4) | ((x & reverseMask4) << 8);


  reverseMask5 = reverseMask5 << 8 | reverseMask5;
  x = ((x >> 16) & reverseMask5) | ((x & reverseMask5) << 16);


  return x;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y)
{
  int sum  =  x + y;

  //Get sign bit for x
  int xSign = x >> 31;

  //Get sign bit for y
  int ySign = y >> 31;

  //Get sign bit for sum of x and y
  int sumSign = sum >> 31;

  //Check what kind of overflow is occuring w/ ex or statement
  int checkOverflow = ((sumSign ^ xSign) & (sumSign ^ ySign)) >> 31;

  //If positive overflow get max value by shifting 31
  return((sum >> (checkOverflow  & 31))  + (checkOverflow << 31));
}
/*
 * Extra credit
 */
/*
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf)
{
  unsigned mask = 0x7fffffff;
  unsigned minValue = 0x7f800001;
  unsigned result;


  //Set sign to 0 to make absvalue
  result  = uf & mask;
  //Value is NaN
  if (result >= minValue)
  {
    return uf;
  }
  else
  {
    return result;
  }

}
/*
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf)
{
  //IEEE Representation of uf
  unsigned signBit = uf >> 31;
  unsigned exp = (uf >> 23) & 0xff;
  unsigned frac = uf & 0x7fffff;
  //32 bit number -> 127 bias
  unsigned bias = 0x7f;
  unsigned result = frac;


  //Check if number is NaN or infinite
  if (exp == 0xff)
  {
    return 0x80000000u;
  }

  //Check whether number is denormalized
  if (exp < bias)
  {
    return 0x0;
  }

  exp = exp - bias;

  if (exp >= 31)
  {
      return 0x80000000u;
  }

  if (exp > 22)
  {
    result = frac << (exp - 23);
  }
  else
  {
    result = frac >> (23 - exp);
  }


  //Complete two's complement
  result = result + (1 << exp);

  if (signBit == 1)
  {
    result = -result;
  }

  return result;

}
/*
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf)
{
  int signBit = uf  & 0x80000000;
  int exp = uf & 0x7f800000;
  int frac = uf & 0x007fffff;


  //Check whehter NaN or infinity
  //exp == frac bit are all ones
  if (exp == 0x7f800000)
  {
    return uf;
  }

  //Checks whether frac is denormalized
  if((!exp) || (exp == 0x00800000))
  {
    frac = frac | exp;
    frac = (uf & 0x00ffffff) >> 1;
    frac = frac + (((uf & 3) >> 1) & (uf & 1));
    return signBit | frac;
  }

  return signBit | ((exp -1) & 0x7f800000)| frac;
}
