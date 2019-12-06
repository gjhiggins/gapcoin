The prime numbers are not regularly spaced.

For example from 2 to 3 the gap is 1. (2 is a prime number, the one and only even prime number)

From 3 to 5 the gap is 2.

From 7 to 11 it is 4.

Between 2 and 50 we have the following pairs of 2-gap primes: 3-5, 5-7, 11-13, 17-19, 29-31, 41-43

A prime gap of length `n` is a run of `n-1` consecutive composite (i.e. divisible) numbers between two successive primes (see: http://mathworld.wolfram.com/PrimeGaps.html).

We will write a function `gap` with parameters:

- `g` (an integer >= 2) which indicates the gap we are looking for
- `m` (an integer >= 2) which gives the start of the search (`m` inclusive)
- `n` (an integer >= `m`) which gives the end of the search (`n` inclusive)

As an example: `gap(2, 2, 50)` will return `[3, 5]` which is the first pair of prime numbers between 2 and 50 that has a 2-gap.

The function should return the first pair of prime numbers spaced with a gap of `g` between the limits `m`, `n` if these numbers exist, otherwise `nil` or `null` or `None` or `Nothing` depending on the programming language in which the `gap` function is implemented.

Examples:

    gap(2, 5, 7) yields [5, 7]

    gap(2, 5, 5) yields nil

    gap(4, 130, 200) yields [163, 167]

    gap(6, 100, 110)` yields nil

Example 4 returns `nil` because the numbers between 100 and 110 include the primes 101, 103, 107 and 109. By the same token, [101-107] is not a 6-gap because the sequence includes 103 and neither is [103-109] a 6-gap because it includes 107.

The `gap` function returns only the *first occurrence* (if any) of the specified size gap. In example 3, [193, 197] is also a 4-gap pair of primes between 130 and 200 but it’s not the first occurrence of a 4-gap pair of primes in the sequence.

---

[Prime numbers and cryptography - The Times Malta](https://timesofmalta.com/articles/view/Prime-numbers-and-cryptography.672957)

A prime gap is the difference between two successive prime numbers. For example, the numbers 317 and 331 are both prime, but no number in between is prime, so we have a prime gap of 14. By the Prime Number Theorem, the average prime gap between any two consecutive prime numbers among the first n whole numbers is the natural logarithm of n. The merit of a prime gap is thus defined as the prime gap divided by this average prime gap. For example, the merit of the prime gap between 317 and 331 is 2.43, which means that this prime gap is more than twice the average prime gap among those between 1 and 317. In December 2017, the GapCoin network discovered a prime gap of length 8350 following an 87-digit prime. This prime gap has merit 41.94, which means that it is almost 42 times as large as the average prime gap. This is the largest prime gap merit discovered to date.

[Snake andLadder based Algorithm for Steganographic Application of Specific Streamline Bitson Prime GapMethod](https://research.ijcaonline.org/volume94/number3/pxc3895567.pdf)

