'''
foobar:~/ abhishek252167$ ls
elevator-maintenance
journal.txt
start_here.txt
foobar:~/ abhishek252167$ cd elevator-maintenance
foobar:~/elevator-maintenance abhishek252167$ cat readme.txt
Elevator Maintenance
====================

You've been assigned the onerous task of elevator maintenance - ugh! It wouldn't be so bad, except that all the elevator documentation has been lying in a disorganized pile at the bottom of a filing cabinet for years, and you don't even know what elevator version numbers you'll be working on. 

Elevator versions are represented by a series of numbers, divided up into major, minor and revision integers. New versions of an elevator increase the major number, e.g. 1, 2, 3, and so on. When new features are added to an elevator without being a complete new version, a second number named "minor" can be used to represent those new additions, e.g. 1.0, 1.1, 1.2, etc. Small fixes or maintenance work can be represented by a third number named "revision", e.g. 1.1.1, 1.1.2, 1.2.0, and so on. The number zero can be used as a major for pre-release versions of elevators, e.g. 0.1, 0.5, 0.9.2, etc (Commander Lambda is careful to always beta test her new technology, with her loyal henchmen as subjects!).

Given a list of elevator versions represented as strings, write a function solution(l) that returns the same list sorted in ascending order by major, minor, and revision number so that you can identify the current elevator version. The versions in list l will always contain major numbers, but minor and revision numbers are optional. If the version contains a revision number, then it will also have a minor number.

For example, given the list l as ["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"], the function solution(l) would return the list ["1.0", "1.0.2", "1.0.12", "1.1.2", "1.3.3"]. If two or more versions are equivalent but one version contains more numbers than the others, then these versions must be sorted ascending based on how many numbers they have, e.g ["1", "1.0", "1.0.0"]. The number of elements in the list l will be at least 1 and will not exceed 100.

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
solution.solution(["1.11", "2.0.0", "1.2", "2", "0.1", "1.2.1", "1.1.1", "2.0"])
Output:
    0.1,1.1.1,1.2,1.2.1,1.11,2,2.0,2.0.0

Input:
solution.solution(["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"])
Output:
    1.0,1.0.2,1.0.12,1.1.2,1.3.3

-- Java cases --
Input:
Solution.solution({"1.11", "2.0.0", "1.2", "2", "0.1", "1.2.1", "1.1.1", "2.0"})
Output:
    0.1,1.1.1,1.2,1.2.1,1.11,2,2.0,2.0.0

Input:
Solution.solution({"1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"})
Output:
    1.0,1.0.2,1.0.12,1.1.2,1.3.3

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.
foobar:~/elevator-maintenance abhishek252167$ cat constraints.txt
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
foobar:~/elevator-maintenance abhishek252167$ edit solution.py
foobar:~/elevator-maintenance abhishek252167$ verify solution.py
Verifying solution...
All test cases passed. Use submit solution.py to submit your solution
foobar:~/elevator-maintenance abhishek252167$ submit solution.py
Are you sure you want to submit your solution?
[Y]es or [N]o: y
Submitting solution...
Awesome! Commander Lambda was so impressed by your efforts that she's made you her personal assistant. You'll be helping her directly with her work, which means you'll have access to all of her files-including the ones on the LAMBCHOP doomsday device. This is the chance you've been waiting for. Can you use your new access to finally topple Commander Lambda's evil empire?
Submission: SUCCESSFUL. Completed in: 1 hr, 11 mins, 10 secs.

Level 2 complete
You are now on level 3
Challenges left to complete level: 3

Level 1: 100% [==========================================]
Level 2: 100% [==========================================]
Level 3:   0% [..........................................]
Level 4:   0% [..........................................]
Level 5:   0% [..........................................]

To invite a friend to try a challenge, send the link below. This is a single-use code, so choose wisely.

Refer a friend: "https://foobar.withgoogle.com/?eid=NJWRW" (Unused)

Type request to request a new challenge now, or come back later.
'''

def solution(l):
    def cmpv(v1, v2):
        v1 = map(int, v1.split('.'))
        v2 = map(int, v2.split('.'))
        le = min(len(v1), len(v2))
        for i in xrange(le):
            if v1[i] - v2[i] != 0:
                return v1[i] - v2[i]
        return len(v1) - len(v2)
    l = sorted(l, cmp=cmpv)
    return l