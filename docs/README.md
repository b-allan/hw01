# Homework \#1

### Homework Instructions

#### Getting started

1. Accept the assignment delivered via GitHub class by following the URL found in the class meeting invite in Office 365.
1. Open a terminal window (e.g., Cygwin64 terminal window, or Macintosh Terminal app) and create a convenient place to clone this (and future) assignments.
1. _If you have **not** done so already_, update some global git attributes:
    * `git config --global user.email youremail@live.missouristate.edu`
    * `git config --global user.name "Your Name"`
1. Clone your hw01 repository with the `git clone your-specific-repo-url` where `your-specific-repo-url` is copied from "Clone or download" button found on the home page of your repository in GitHub.
1. Navigate into the directory created by your `git clone` command and create the develop branch with the `git checkout -b develop` command.
1. Push your new branch to GitHub with the `git push --set-upstream origin develop` command.
1. Create a pull request that seeks to merge changes in your develop branch into your master branch. (Clearly there are no changes yet, but we're just setting up the pull request early; each subsequent commit you make to your develop branch will update the pull request automatically with the new changes. Furthermore, we do this so that we can carry out the next step.)
1. Add `professordaehn` as reviewers to your repository. Additionally, assign yourself as the Assignee to this pull request.

#### Tasks

After completing the steps in the aforementioned "Getting started" section, you are tasked with the following changes to `Main.cpp:`

**Password Verifier**

Imagine you are developing a software package that requires users to enter their own passwords. Your software requires that users' passwords meet the following criteria:

* The password should be at least 6 characters long.
* The password should contain at least one uppercase and at least one lowercase letter.
* The password should have at least 1 digit.

Write a program that asks for a password and then verifies that it meets the stated criteria. If it doesn't the program should display a message telling the user why.

**Expected Output**

When your solution is executed, it must match, verbatim, the following output, depending upon the use case:

_User accepts auto-generated password_

```bash
Enter your full name, including middle initial: Stu D. Ent
Your auto-generated password is: tnEDutS10
Would you like to change your password now [Y|N]? N
Thank you. It is recommended that you change your password the next time you log into our system.
```

_User changes password successfully_

```bash
Enter your full name, including middle initial: Stu D. Ent
Your auto-generated password is: tnEDutS10
Would you like to change your password now [Y|N]? Y
Enter your password: Passw0rd
Thank you. Please use your new password the next time you log into our system.
```

_User changes password unsuccessfully_

```bash
Enter your full name, including middle initial: Stu D. Ent
Your auto-generated password is: tnEDutS10
Would you like to change your password now [Y|N]? Y
Enter your password: password
We're sorry. Your password does not meet our requirements:
    * Your password does not contain at least one uppercase and one lowercase letter
    * Your password does not contain at least 1 digit
Your password was not changed; it remains: tnEDutS10
As a reminder, your password should
    * be at least 6 characters long
    * contain at least one uppercase and at least one lowercase letter
    * contain at least 1 digit
It is recommended that you change your password the next time you log into our system.
```

**Algorithm for auto-generated passwords**

The auto-generated passwords are generated from the user's name as follows:

1. The user's name is reversed, removing any white space or period characters ('.')
    1. If the user entered their name in all uppercase or all lower case, the algorithm treats the name as if it were entered with the proper case as shown in the above examples.
1. The length of the name entered -- including any white space and punctuation -- is appended to the end of the auto-generated password.
    1. If the user entered a name that is less than 6 characters, the number 6 is appended to the end of the reversed name until the password is 6 characters long.
    
To earn full credit, your program _must_

* be **modular**; you should have separate functions for calculating each of the required statistics
* **not have any global variables** other than some useful named constants that may be used in more than one function
* use **meaningful aliases** for primitive data types (e.g., as shown in `Demo.cpp` where we have `using temperature = double;`)
* make intelligent decisions about **parameter passing mechanisms**, i.e., choosing when to pass parameters by value, by reference or by constant reference

### Submission Details

A pull request that seeks to merge to the changes found in your develop branch into the master branch is due by midnight, Saturday (9/9/2017). The pull request _must_ list `professordaehn`. Your reviewer has until midnight of the Sunday (9/10/2017) to request changes. If change requests are made, you have until midnight of Wednesday (9/13/2017) to make the changes. Do **not** merge your pull request unless and until `professordaehn` as approved the pull request.

### Grading Rubric

This homework is worth 5 points. Below is a rubric that is used to assess your grade for this assignment.

**3 Points**: Assignment Submission

Grade  | Minimum Requirements
-------|---------------------
 00.0% | Student did not accept the assignment.
 20.0% | Student completed the work on time, but did not work in a develop branch or did not make a proper pull request.
 40.0% | Student completed the work on time, successfully made a pull request but did not respond to change requests made by the reviewer.
 60.0% | Student completed the work on time and attempted to respond to change requests, albeit unsuccessfully.
 80.0% | Student successfully completed all requirements following change requests.
100.0% | Student successfully completed all requirements of the assignment on first submission

**1 Point**: Program Design/Modularity

The program was modular, used appropriate parameter passing mechanisms and type aliases.

**1 Point**: Program Style

The program was written in a consistent, appropriate programming style, including, but not limited to

* use of standardized header comments
* consistent indentation
* consistent curly brace placement
* use of appropriate, semantically rich variable names and constants