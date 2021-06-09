
https://www.geeksforgeeks.org/c-bitset-and-its-application/
https://www.geeksforgeeks.org/c-bitset-interesting-facts/

Part 1 (link) introduces basic bitwise operations. This is part 2 and it's mainly about (in)famous bitsets and example problems. Also, see links to very useful advanced stuff at the bottom. EDIT: here's video version of this blog (on my Youtube channel).

Built-in functions
In C++, __builtin_popcount(x) returns popcount of a number — the number of ones in the binary representation of x. Use __builtin_popcountll(x) for long longs.

There are also __builtin_clz and __builtin_ctz (and their long long versions) for counting the number of leading or trailing zeros in a positive number. Read more here. Now, try to solve these two simple tasks in O(1), then open the spoiler to check the solution:

Compute the biggest power of 2 that is a divisor of x. Example: f(12) = 4
1 << __builtin_ctz(x)

Compute the smallest power of 2 that is not smaller than x. Example: f(12) = 16
1 << (32 - __builtin_clz (x - 1))

but this is UB (undefined behavior) for x≤1 so you'll often need an if for x==1.

While popcount is often needed, I rarely use the other two functions. During a contest, I would solve the two tasks above in O(logx) with simple while-loops, because it's easier and more intuitive for me. Just be aware that these can be done in O(1), and use clz or ctz if you need to speed up your solution.

Motivation behind bitsets
Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.

You can compute the intersection of two workers (two sets) in O(30) by using e.g. two pointers for two sorted sequences. Doing that for every pair of workers is O(N2⋅30), slightly too slow.

We can think about the availability of a worker as a binary string of length 30, which can be stored in a single int. With this representation, we can count the intersection size in O(1) by using __builtin_popcount(x[i] & x[j]). The complexity becomes O(N2), fast enough.

What if we are given the availability for the whole year or in general for D days? We can handle D≤64 in a single unsigned long long, what about bigger D?

We can split D days into convenient parts of size 64 and store the availability of a single worker in an array of D64 unsigned long longs. Then, the intersection can be computed in O(D64) and the whole complexity is O(N2⋅D64).

code
So, we can simulate a long binary number with multiple unsigned long longs. The implementation isn't that bad but doing binary shifts would be quite ugly. Turns out all of this can be done with bitsets easily.

Bitsets
bitset<365> is a binary number with 365 bits available, and it supports most of binary operations. The code above changes into simple:

code
Some functions differ, e.g. x.count() instead of __builtin_popcount(x) but it's only more convenient. You can read and print binary numbers, construct a bitset from int or 

string bitset<100> a(17); bitset<100> b("1010");. You can even access particular bits with b[i]. Read more in C++ reference https://en.cppreference.com/w/cpp/utility/bitset.

Note that the size of the bitset must be a constant number. You can't read n and then declare bitset<n> john;. If n is up to 100, just create bitset<100>.

The complexity of bitwise operations is O(size32) or O(size64), it depends on the architecture of your computer.

Problems
P1. Different numbers — You are given a sequence of N≤107 numbers, each from interval [0,109]. How many different values appear in the sequence? Don't use set or unordered_set because they quite slow.

solution
P2. Knapsack — You are given N≤1000 items, each with some weight wi. Is there a subset of items with total weight exactly W≤106?

solution
P3. Triangles in a graph — Given a graph with n≤2000 vertices and m≤n⋅(n−1)/2 edges, count triples of vertices a,b,c such that there are edges a−b, a−c and b−c.

hint
P4. Chef and Queries — https://www.codechef.com/problems/CHEFQUE (easy)

P5. Odd Topic — https://www.codechef.com/AABH2020/problems/ODTPIC (medium), thanks to Not-Afraid for the suggestion

P6. Funny Gnomes — https://www.codechef.com/problems/SHAIKHGN (hard)

Bonuses
1) m & (m-1) turns off the lowest bit that was set to 1 in a positive number m. For example, we get 24 for m=26, as 11010 changes into 11000. Explanation on quora
2) A quite similar trick allows us to iterate efficiently over all submasks of a mask, article on cp-algorithms / e-maxx. This article also explains why masks-submasks iteration is O(3n).
3) DP on broken profile (grid dp) — https://cp-algorithms.com/dynamic_programming/profile-dynamics.html
4) SOS dp (sum over subset) — https://codeforces.com/blog/entry/45223 & https://www.youtube.com/watch?v=Lpvsd8WpbWc&t=5m4s
5) _Find_next function and complexity notation for bitsets — https://codeforces.com/blog/entry/43718
