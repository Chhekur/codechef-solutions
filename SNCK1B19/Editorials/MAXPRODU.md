#PROBLEM LINK:

[Practice][111]  
[Contest][222]

**Author:** [admin3][4444]  
**Editorialist:** [admin5][6666]

#DIFFICULTY:
Easy

#PREREQUISITES:
Basic implementation, Greedy

#PROBLEM:
You are given two integers **N** and **K**, you have to partition **N** into **K** distinct positive integers **X<sub>1</sub> + X<sub>2</sub>+ .... + X<sub>K</sub> = N**.  
You have to find the maximum possible value of the product **(x21−x1)⋅(x22−x2)⋅…⋅(x2K−xK)** and print it modulo 1e9+7.


#EXPLANATION:

with **K** we can get the minimum sum **1 + 2 + 3 ... K = K*(K+1) / 2**  

here we observed that if **N < K*(K + 1) /2**, we can't partition **N** into **K** distinct positive integers, so the answer will be **-1**.

Otherwise we need to find out the valid **K** distinct elements, for doing this
- first take **K** elements **1,2,3....K**
- now calculate the difference between **N** and **K * (K + 1) / 2** because we have already taken elements from **1 .. K** so we got the sum **K * (K + 1) / 2**  
**d = N - (K * (K + 1) / 2)**  
now we need this more to get sum equals to **N**
- now need equal distribution of **d** among **K** elements, So  
**c = d / K**   
**r = d % K** (if **d** is not divisible by **K**)
- increase all **K** chosen elements by **c** and increase last **r** elements by **1**
- we got **K** elements with sum equals to **N**

Just calculate the answer of calculated **K** elements and take it's modulo **1e9+7**.

#Time Complexity
Time complexity is **O(K)** per test case.

#SOLUTIONS:
Editorialist's solution can be found 
[here][444].  

Feel free to Share your approach, If it differs. Suggestions are always welcomed. :)

[111]: http://www.codechef.com/problems/MAXPRODU
[222]: https://www.codechef.com/SNCK1B19/problems/MAXPRODU

[444]: https://www.codechef.com/viewsolution/21289003

[4444]: https://www.codechef.com/users/admin3
[6666]: https://www.codechef.com/users/admin5