[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/gc8KNZ8z)
# Introduction to Git/GitHub

You will ***not*** have to write any code for this computer assignment.

You will only have to check out the code from a Git repository and make a few changes to `introduction.cc`:

**Programming Notes:**

1) By this point, you should have created an account at [GitHub (https://github.com)](https://github.com).

*Helpful Git & GitHub Guides:*

* GitHub Guide: [Hello World](https://guides.github.com/activities/hello-world/)
* [2-Pager of Git Commands](https://education.github.com/git-cheat-sheet-education.pdf)
* [List of Git Tutorials](https://help.github.com/articles/good-resources-for-learning-git-and-github/)

2) You will be given a link to an invitation for this assignment generated by GitHub Classroom; copy the link to a browser to accept the assignment. It will look something like this:

`https://classroom.github.com/a/<alphanumeric code>`

Clicking the link takes you to a page asking if you wish to accept this assignment. Ensure you ***read*** the message carefully to confirm it says something similar to the following:

```text
UIC-HPC
Accept the assignment — 
<XXXX>

Once you accept this assignment, you will be granted access to the <XXXX>-<yourGitHubID> repository in the UIC-HPC organization on GitHub. 
```

The key thing you want to look for is that your ***GitHub ID*** is after the dash in the specified repository. If not automatically prompted, find and use the **sign-in** button on the upper right-hand side to log in.
 If you use a shared computer (i.e., lab computer), the browser may cache someone else login name. You can address this by clearing the browser cache and ensuring you are logged into GitHub in another tab in the same browser. If you still have problems, let your ***instructor*** and ***TA*** know ASAP. **DO NOT ACCEPT ASSIGNMENT IF LOGIN NAME IS WRONG!!!!**

After accepting, the system will take you to a page displaying something similar to the following:

```text
You accepted the assignment, <XXXX>. We're configuring your repository now. This may take a few minutes to complete. Refresh this page to see updates.
Your assignment is due by <Month> <Day>, <Year>, <Time> CST

**Note:** You may receive an email invitation to join UIC-HPC on your behalf. No further action is necessary.
```

3) Depending on where you do your development, you can either click on the link and work from your browser or use command line tools as demonstrated in class. Either way, you will need eventually to generate a local repository. You should use one of the public CS resources, such as `systems{1-4}.cs.anl.gov`, to get used to working remotely, which you will need to do once we move to the HPC systems.

4) You will then complete the assignment as follows:

* Add the following doc-box comment to your local repository and commit the changes. Then, push the modifications to the remote repository. Modify the comment to include your name, the assignment you are working on, and its due date. Place this comment at the top of every file you modify this semester. Including this comment will contribute to a higher grade on the assignment.

```c++
/*
    <Your Name>
    <Assignment>
    <Date>

    I certify that this is my work and, where appropriate, an extension of the starter code provided for the assignment.
*/
```

* You will then add the code below as the first line of code within the `main` routine of the file `introduction.cc`; you will then commit this change to your local repository, followed by a push the change to the remote repository.

```c++
cut << "I'm looking forward to learning about high performance computing!!" << endl;   // Yes, I know there is a typo!!!
```

* You will then create a `Makefile` for this assignment, generating a Makefile that compiles and builds an executable named *introduction*. The Makefile must produce an `introduction` by executing the command `make`.

```Makefile
# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic -Wno-unused-parameter

# Define the C++ source files
SOURCES = introduction.cc

# Define the C++ object files
OBJECTS = $(SOURCES:.cc=.o)

# Define the executable file 
MAIN = introduction

.PHONY: all clean

all: $(MAIN)
	@echo Congratulations $(MAIN) has been compiled!

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJECTS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

```

* You will now add the Makefile to your local repository, commit changes, and push to the remote repository.

* You will execute the `make` command, correct any compiler errors, commit changes, and push to the remote repository. If during the `make` you get an error `Makefile:19: *** missing separator.  Stop.` this is likely due to cut and paste where the `<tab>` required by **make** is replaced with `<spaces>`.

When your program is ready for grading, ***commit*** and ***push*** your local repository to the remote git classroom repository and follow the _**Assignment Submission Instructions**_. 


