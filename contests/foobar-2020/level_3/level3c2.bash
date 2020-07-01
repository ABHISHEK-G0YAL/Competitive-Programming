foobar:~/ abhishek252167$ request
Requesting challenge...
Commander Lambda has six suits, three dress uniforms, four casual outfits, and one Dress-Uniform-For-Important-Speeches-Only. You know this because you've already had to take all of them to the dry cleaner's. Twice!
New challenge "Fuel Injection Perfection" added to your home folder.
Time to solve: 96 hours.
foobar:~/ abhishek252167$ ls
fuel-injection-perfection
journal.txt
start_here.txt
foobar:~/ abhishek252167$ cd fuel-injection-perfection
foobar:~/fuel-injection-perfection abhishek252167$ ls
Solution.java
constraints.txt
readme.txt
solution.py
foobar:~/fuel-injection-perfection abhishek252167$ cat readme.txt
Fuel Injection Perfection
=========================

Commander Lambda has asked for your help to refine the automatic quantum antimatter fuel injection system for her LAMBCHOP doomsday device. It's a great chance for you to get a closer look at the LAMBCHOP - and maybe sneak in a bit of sabotage while you're at it - so you took the job gladly. 

Quantum antimatter fuel comes in small pellets, which is convenient since the many moving parts of the LAMBCHOP each need to be fed fuel one pellet at a time. However, minions dump pellets in bulk into the fuel intake. You need to figure out the most efficient way to sort and shift the pellets down to a single pellet at a time. 

The fuel control mechanisms have three operations: 

1) Add one fuel pellet
2) Remove one fuel pellet
3) Divide the entire group of fuel pellets by 2 (due to the destructive energy released when a quantum antimatter pellet is cut in half, the safety controls will only allow this to happen if there is an even number of pellets)

Write a function called solution(n) which takes a positive integer as a string and returns the minimum number of operations needed to transform the number of pellets to 1. The fuel intake control panel can only display a number up to 309 digits long, so there won't ever be more pellets than you can express in that many digits.

For example:
solution(4) returns 2: 4 -> 2 -> 1
solution(15) returns 5: 15 -> 16 -> 8 -> 4 -> 2 -> 1

Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit Solution.java

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Python cases --
Input:
solution.solution('15')
Output:
    5

Input:
solution.solution('4')
Output:
    2

-- Java cases --
Input:
Solution.solution('4')
Output:
    2

Input:
Solution.solution('15')
Output:
    5

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.
foobar:~/fuel-injection-perfection abhishek252167$ cat constraints.txt
Java
====
Your code will be compiled using standard Java 8. All tests will be run by calling the solution() method inside the Solution class

Execution time is limited.

Wildcard imports and some specific classes are restricted (e.g. java.lang.ClassLoader). You will receive an error when you verify your solution if you have used a blacklisted class.

Third-party libraries, input/output operations, spawning threads or processes and changes to the execution environment are not allowed.

Your solution must be under 32000 characters in length including new lines and and other non-printing characters.

Python
======
Your code will run inside a Python 2.7.13 sandbox. All tests will be run by calling the solution() function.

Standard libraries are supported except for bz2, crypt, fcntl, mmap, pwd, pyexpat, select, signal, termios, thread, time, unicodedata, zipimport, zlib.

Input/output operations are not allowed.

Your solution must be under 32000 characters in length including new lines and and other non-printing characters.
foobar:~/fuel-injection-perfection abhishek252167$ edit solution.py
foobar:~/fuel-injection-perfection abhishek252167$ verify solution.py
Verifying solution...
Test 1 passed!
Test 2 passed!
Test 3 failed  [Hidden]
Test 4 failed  [Hidden]
Test 5 failed  [Hidden]
Test 6 failed  [Hidden]
Test 7 failed  [Hidden]
Test 8 passed! [Hidden]
Test 9 passed! [Hidden]
Test 10 passed! [Hidden]
foobar:~/fuel-injection-perfection abhishek252167$ cat solution.py
map​ ​=​ ​{}
def​ ​solution(n):
​ ​​ ​​ ​​ ​n​ ​=​ ​int(n)
​ ​​ ​​ ​​ ​if​ ​map.get(n):
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​return​ ​map[n]
​ ​​ ​​ ​​ ​if​ ​n​ ​==​ ​1:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​0
​ ​​ ​​ ​​ ​elif​ ​n​ ​%​ ​2​ ​==​ ​0:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​1​ ​+​ ​solution(n​ ​/​ ​2)
​ ​​ ​​ ​​ ​else:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​1​ ​+​ ​min(solution(n​ ​+​ ​1),​ ​solution(n​ ​-​ ​1))
​ ​​ ​​ ​​ ​return​ ​map[n]
foobar:~/fuel-injection-perfection abhishek252167$ verify solution.py
Verifying solution...
Test 1 failed : BLACKLISTED_CODE
Test 2 failed : BLACKLISTED_CODE
Test 3 failed  [Hidden]: BLACKLISTED_CODE
Test 4 failed  [Hidden]: BLACKLISTED_CODE
Test 5 failed  [Hidden]: BLACKLISTED_CODE
Test 6 failed  [Hidden]: BLACKLISTED_CODE
Test 7 failed  [Hidden]: BLACKLISTED_CODE
Test 8 failed  [Hidden]: BLACKLISTED_CODE
Test 9 failed  [Hidden]: BLACKLISTED_CODE
Test 10 failed  [Hidden]: BLACKLISTED_CODE
foobar:~/fuel-injection-perfection abhishek252167$ cat solution.py
import​ ​sys
sys.setrecursionlimit(15000)
map​ ​=​ ​{}
def​ ​solution(n):
​ ​​ ​​ ​​ ​n​ ​=​ ​int(n)
​ ​​ ​​ ​​ ​if​ ​map.get(n):
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​return​ ​map[n]
​ ​​ ​​ ​​ ​if​ ​n​ ​==​ ​1:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​0
​ ​​ ​​ ​​ ​elif​ ​n​ ​%​ ​2​ ​==​ ​0:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​1​ ​+​ ​solution(n​ ​/​ ​2)
​ ​​ ​​ ​​ ​else:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​1​ ​+​ ​min(solution(n​ ​+​ ​1),​ ​solution(n​ ​-​ ​1))
​ ​​ ​​ ​​ ​return​ ​map[n]
foobar:~/fuel-injection-perfection abhishek252167$ verify solution.py
Verifying solution...
All test cases passed. Use submit solution.py to submit your solution
foobar:~/fuel-injection-perfection abhishek252167$ cat solution.py
map​ ​=​ ​{}
stack​ ​=​ ​[]
def​ ​solution(n):
​ ​​ ​​ ​​ ​n​ ​=​ ​int(n)
​ ​​ ​​ ​​ ​stack.append(n)
​ ​​ ​​ ​​ ​while​ ​len(stack)​ ​>​ ​0:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​n​ ​=​ ​stack[-1]
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​if​ ​map.get(n):
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​stack.pop()
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​elif​ ​n​ ​==​ ​1:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​0
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​stack.pop()
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​elif​ ​n​ ​%​ ​2​ ​==​ ​0:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​if​ ​map.get(n​ ​/​ ​2)​ ​is​ ​not​ ​None:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​1​ ​+​ ​map[n​ ​/​ ​2]
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​stack.pop()
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​else:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​stack.append(n​ ​/​ ​2)
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​else:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​if​ ​map.get(n​ ​+​ ​1)​ ​is​ ​not​ ​None​ ​and​ ​map.get(n​ ​-​ ​1)​ ​is​ ​not​ ​None:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​map[n]​ ​=​ ​1​ ​+​ ​min(map[n​ ​+​ ​1],​ ​map[n​ ​-​ ​1])
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​stack.pop()
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​else:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​stack.append(n​ ​-​ ​1)
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​stack.append(n​ ​+​ ​1)
​ ​​ ​​ ​​ ​return​ ​map[n]
foobar:~/fuel-injection-perfection abhishek252167$ submit solution.py
Are you sure you want to submit your solution?
[Y]es or [N]o: y
Submitting solution...
Submission: SUCCESSFUL. Completed in: 12 hrs, 27 secs.

Current level: 3
Challenges left to complete level: 1

Level 1: 100% [==========================================]
Level 2: 100% [==========================================]
Level 3:  66% [===========================...............]
Level 4:   0% [..........................................]
Level 5:   0% [..........................................]

Type request to request a new challenge now, or come back later.
foobar:~/ abhishek252167$