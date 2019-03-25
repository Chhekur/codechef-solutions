#PROBLEM LINK:

[Practice][111]  
[Contest][222]

**Author:** [mgch][4444]  
**Editorialist:** [admin5][6666]

#DIFFICULTY:
Simple

#PREREQUISITES:
Basic implementation

#PROBLEM:
You are given a sequence of positive integers **A<sub>1</sub>,A<sub>2</sub>,…,A<sub>N</sub>** and **K**, you can replace at most **K** element of sequence with any positive integer.  
and check whether it is achievable or not **A<sub>1</sub><sup>2</sup>+A<sub>2</sub><sup>2</sup>+⋯+A<sub>N</sub><sup>2</sup> ≤ A<sub>1</sub>+A<sub>2</sub>+⋯+A<sub>N</sub>** .

#QUICK EXPLANATION:
- Sort the given sequence of numbers in descending order.
- Replace first **K** elements with **1**.
- check whether it is achievable or not **A<sub>1</sub><sup>2</sup>+A<sub>2</sub><sup>2</sup>+⋯+A<sub>N</sub><sup>2</sup> ≤ A<sub>1</sub>+A<sub>2</sub>+⋯+A<sub>N</sub>** .

#EXPLANATION:
You are given a sequence of positive integers **A<sub>1</sub>,A<sub>2</sub>,…,A<sub>N</sub>** and **K**.  
Here we need to minimize the numbers which are large enough because contribution of large numbers to make given condition false than the small number.  

**A<sub>1</sub><sup>2</sup>+A<sub>2</sub><sup>2</sup>+⋯+A<sub>N</sub><sup>2</sup> ≤ A<sub>1</sub>+A<sub>2</sub>+⋯+A<sub>N</sub>**  

in this equation we need to minimize the sum of squares so after sorting the given sequence of integers in descending order we can replace first **K** elements with 1 because 1<sup>2</sup> = 1, we can't get minimum than this.  

Check whether given condition is true or not.

#Time Complexity
Time complexity is **O(N*log(N))** per test case.

#SOLUTIONS:
Editorialist's solution can be found [here][444].   


Feel free to Share your approach, If it differs. Suggestions are always welcomed. :)

[111]: http://www.codechef.com/problems/CHFAR
[222]: https://www.codechef.com/SNCK1B19/problems/CHFAR

[444]: https://www.codechef.com/viewsolution/21264568

[4444]: https://www.codechef.com/users/mgch
[6666]: https://www.codechef.com/users/admin5