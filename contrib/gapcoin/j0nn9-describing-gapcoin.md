## GAPCOIN GAP

Gapcoin is a new prime number based p2p cryptocurrency, which tries to eliminate the sticking points of other scientific currencies like Primecoin or Riecoin. It’s a fork of Satoshi Nakamotos Bitcoin, a decentralized payment system which is independent of banks, governments and other centralized regulators. With Gapcoin, you will be able to anonymously send money around the globe in no time.

The big improvement in comparison to Bitcoin is that instead of burning electricity for its own sake, Gapcoin’s Proof of Work function actually does useful work by searching for large prime gaps.

### What are the advantages of Gapcoin compared with other prime number based cryptocurrencies?

First of all, Gapcoin follows Riecoin’s way and uses enough Miller-Rabin tests with random bases to avoid composite numbers being accepted as Prove of Work, like Primecoin mistakenly could.

But the real improvement is due to its easy “pool-mineable” Hashing algorithm. This means that creating a Gapcoin pool will be as easy as creating a scrypt one!

### Why is that important?

When you look at Riecoin, there are only two pools. Even Primecoin, the first scientific cryptocurrency, only has three reliable pools. This is due to the difficulty of creating a fair reward system for the custom hashing algorithms of Prime- and Riecoin.

In Primecoin, which is searching for long prime chains, you can easily modify your miner to search for smaller chains. In fact, it is mostly about a simple one-line-editing. As an example, just turn a 10 into a 7 in xolominer and you will get scads of 7-chains, but your chance to find a block has diminished.

To avoid this, pools supply better payment for shares with longer chain-lengths.

In Riecoin, it is even worse. Riecoin searches for prime tuples of length 6. Pools do accept tuples with less primes, but a 6-tuple only can occur in certain places. (Look at this post for a detailed explanation.) 4-tuples, by comparison, are more frequent. There are places, where a 4-tuple can occur, but no 6-tuple, which Riecoin truly needs. So pools have to check every submitted share whether the miner really searches for 6-tuples or not. Those facts are what make it so hard to create a Prime- or Riecoin pool.

With Gapcoin, there won’t be any problems like these. While in Riecoin and Primecoin you can choose whether to search for bigger shares or smaller ones, Gapcoin is searching for prime gaps in general. The distribution of prime gaps is still a mystery for mathematicians, that’s why you can’t modify your miner to look for special results. Consequently, every submitted share can be paid equally.

### How is Proof of Work actually designed?

A PoW algorithm has to fit two specifications:

- It must be cryptographically secure (a PoW must not be reusable)
- It must be hard to calculate, but easy to verify

Verifying a prime gap is easy, you only have to check every number between the start and the end to be composite.

Calculating is harder, much harder!

Large prime gaps occur a lot lesser than smaller ones. According to E. Westzynthius, in `e^n` prime gaps there will be one gap that is `n` times greater than the average prime gap.

### So the difficulty will simply be the length of the prime gap?

Not exactly. The average length of a prime gap with the starting prime `p`, is `log(p)`, which means that the average prime gap size increases with lager primes. Then, instead of the pure length, we use the *merit* of the prime gap, which is the ratio of the gap’s size to the average gap size.

Let `p` be the prime starting a prime gap, then `m = gapsize/log(p)` will be the merit of this prime gap.

Also a pseudo-random number is calculated from `p` to provide finer difficulty adjustment.

Let `rand(p)` be a pseudo-random function with `0 > rand(p) > 1` Then, for a prime gap starting at prime `p` with size `s`, the difficulty will be `s/log(p) + 2/log(p) * rand(p)`, where `2/log(p)` is the average distance between a gap of size `s` and `s + 2` (the next greater gap) in the proximity of `p`.

When it actually comes to mining, there are two additional fields added to the block header, named “shift” and “adder”. We will calculate the prime `p` as `sha256(blockheader) * 2^shift + adder`. As an additional criterion the adder has to be smaller than `2^shift` to avoid that the PoW could be reused.

### Could we break any world records?

Sure, if the difficulty reaches 35.4245, every block will be a new world record: Top 20 Prime Gaps

### But how are prime gaps useful?

Prime numbers are interesting for lots of mathematicians around the globe, and they’re also important to every day cryptography (see RSA).

Researches about prime gaps could not only lead to new breakthroughs in the bounded gap, it may also help proving the Twin Prime Conjecture and maybe even the millennium problem, the Riemann hypothesis. Who knows?
