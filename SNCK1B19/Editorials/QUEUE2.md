#PROBLEM LINK:

[Practice][111]  
[Contest][222]

**Author:** [kingofnumbers][4444]  
**Editorialist:** [admin5][6666]

#DIFFICULTY:
Easy

#PREREQUISITES:
Basic implementation, Greedy

#PROBLEM:
At **T = 0**, you are given **M** people in queue, and  **N** more people gonna come at their given time **A[1], A[2] ... A[N]**, and in each **L** time unit restaurant will become vacant and the person currently at the front of the queue takes it, you need to find minimum time you have to spend standing in the queue.

#QUICK EXPLANATION:
- Sort the time at people come in ascending order.
- Calculate wating time only when a person come (**A[i]**) and at **T = 0** and **T = K** as well.

#EXPLANATION:
Calculate the wating time only when a person come instead of every value of **K** because you can enter in restaurant when restaurant become vacant, at **T = 0** there is already **M** people in queue so we can't enter in between them, that's why it is sufficient to check only when a person come.  

First sort the given array **A** of arriving times of people.  
You can calculate the waiting time at any point of **T** let suppose when **T = X**.  

Waiting time at **X = (M - (T / L)) * L + (L - (T % L))**  
in it we add **(L - (T % L))** iff **(M - (T / L)) > 0**  

and increase **M** by **1** when a person come after calculating the waiting time for that particular time **T** because we can stand in queue before him.

So just need to find minimum waiting time.

#Time Complexity
Time complexity is **O(N*log(N))** per test case.

#SOLUTIONS:
Editorialist's solution can be found 
[here][444].  

Feel free to Share your approach, If it differs. Suggestions are always welcomed. :)

[111]: http://www.codechef.com/problems/QUEUE2
[222]: https://www.codechef.com/SNCK1B19/problems/QUEUE2

[444]: https://www.codechef.com/viewsolution/21285135

[4444]: https://www.codechef.com/users/kingofnumbers
[6666]: https://www.codechef.com/users/admin5