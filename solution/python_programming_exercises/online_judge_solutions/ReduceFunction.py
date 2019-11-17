# https://www.hackerrank.com/challenges/reduce-function/problem

from fractions import gcd

def product(fracs):
    t = reduce(lambda x,y: x*y, fracs, Fraction('1/1'))
    Gcd = gcd(t.numerator, t.denominator)
    return t.numerator//Gcd, t.denominator//Gcd
