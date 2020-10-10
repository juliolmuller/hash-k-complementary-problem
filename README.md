<h1 align="center">
  :hash: The k-Complementary Problem
</h1>

- **Project proposed by:** [Lucila Bento, Vinícius de Sá & Jayme Szwarcfiter](https://www.academia.edu/20715778/Hashing_na_solu%C3%A7%C3%A3o_de_problemas_at%C3%ADpicos)
- **Project developed by:** [Julio L. Muller](https://github.com/juliolmuller)
- **Released on:** Out 5, 2020
- **Updated on:** Out 5, 2020
- **Latest version:** 1.0.0
- **License:** MIT

The main objective of this project is to develop a solution in C language to the **k-complementary problem** or the **Pair Sum Problem** using the *hash table* data structure. This was based on a [brazilian paper](https://www.academia.edu/20715778/Hashing_na_solu%C3%A7%C3%A3o_de_problemas_at%C3%ADpicos) with other 3 problems that can be solved with hash tables.

Being constant `k` a positive integer number and being `A` an unordered list of `|A| = n` integers, the ***k*-Complementary Problem** consists on determining all `{x, y}` pairs of elements within `A`, since the sum of `x` and `y` is equal to `k`.

Given an positive integer `k` and a list `A` of `n` unordered integers, we must find out whether there is a pair `{x, y} ⊂ A` such that `x + y = k`. This is a particular case of the well-known *Subset Sum Problem*, in which there are no restrictions on the size of the subsets summing `k`.

If we use, as an example, the inputs `A = [1, -4, 18, 11, 2, 9, -3, 5, 560, 10]` and `k = 20`, the outputs will be the pairs of numbers that satisfy the condition: `{2, 18}`, `{9, 11}` and `{10, 10}`.

For a naive solution, we just need to check all pairs `{x, y}` of elements of `A`. If `x + y` equals `k`, return it and stop. Although no extra space is required, the number of additions and comparisons to be performed is *O*(n²) in the worst case.

We want to do better. First note that, if we select an element `x` of `A`, we can look for its complement `y = k - x` in `A`, and the problem becomes now a search problem. If, for each `x`, we need to traverse the whole list to check whether it contains its complement, then our algorithm still demands *O*(n²) time. A better alternative would be to first sort the list `A`, and then, for each `x ∈ A`, look for its complement using binary search, whereupon our time complexity would be *O*(n log n).

We can use a hash set to store the elements of `A`. The amount of space we need is that to store `n` integers (scattered along their respective buckets) plus an underlying array with `n / α` positions. For a constant load factor `α`, that means *O*(n) space, while the average time of all dictionary operations is as good as *O*(1) under the simple uniform hashing assumption. The overall expected time of such algorithm is therefore also *O*(n), corresponding to the *O*(n) insertions and lookups in the hash set, in the worst case.

## :trophy: Lessons Learned

- **Hash Tables** data structure;
- Transforming a *O*(n²) into a *O*(n) solution;

## :hammer: Technologies & Resources

- *C* language
- Minimalist GNU for Windows

## :bell: Compiling and Running the Program

To execute the program, first you need to compile its source code using a **C compiler**. As I am on Windows, I'm using *[MinGW](http://www.mingw.org/)* that allows me to use `gcc` for compilation:

```bash
# Compiles the application to "kc.exe"
$ gcc main.c -o kc

# Run the application
$ kc

# Run the application using files as standard input
$ kc < test1.txt
$ kc < test2.txt
```
