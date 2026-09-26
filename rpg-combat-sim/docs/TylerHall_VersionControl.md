# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ Course Name <-- Replace all text in brackets ]

- **[ Tyler Hall ]**
- **[ 09/06/26 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ clear ]: Clear the Screen
- [ pwd ]: Print the "Working Directory"
- [ ls ]: List files and folders
- [ ls -a ]: List files and folders, including invisible files
- [ ls -alh ]: List all files and folders, in human readable form
- [ cd <directory> ]: Change directory
- [ cd / ]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ../.. ]: Change directory, go up two folder levels
- [ cd ~/Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ When I typed `cd ` and dragged a folder into the Terminal, 
the full path to that folder was automatically added.
After pressing Enter, the Terminal changed the current working 
directory to the folder I dragged in. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ 1. **Local Version Control** Stores different versions of files on a single computer.
This allows a user to track and restore previous versions, 
but does not provide collaboration with other developers on different computers

2. **Centralized Version Control** Stores project files and their version history 
1. on one central server. Multiple developers can access and update the same project, 
1. but if that server goes down, users may not be able to access the repository.

3. **Distributed Version Control** Gives each developer a complete copy of the 
1. repository and its version history on their own computer. Developers can work 
1. locally and later share their changes with others.
.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ `git clone <repository-url>` ]: Clone a repository
- [ `git config --global user.name "Your Name"` ]: Set up a global user name
- [ `git config --global user.email "your@email.com"` ]: Set up a global email address to match your GitHub account email
- [ `git status` ]: Show the current state of your working directory and staging area
- [ `git add .` ]: Add all modified and new files to the staging area for the next commit
- [ `git commit -m "Your commit message"` ]: Make a commit with a new message
- [ `git log` ]: Show your commit history
- [ `git help` ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ Copy the repository's HTTPS URL from GitHub. 
In Terminal, navigate to the folder where you want the repo and run 
`git clone <repository-url>`.  
Then use `cd <repository-name>` to enter the cloned repository and begin working. ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [A .gitignore file tells Git which files and folders 
  should not be tracked or uploaded to the repository.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [.DS_Store is a file automatically created by macOS to store folder settings. 
  We should ignore it because it is not needed for the project.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [The .vs folder, similar to .DS_Store, should be ignored because it contains Visual 
  Studio settings and temporary files that are specific to my computer.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
[https://gist.github.com/bradtraversy/cc180de0edee05075a6139e42d5f28ce]

**Three Types of Version Control**  
[https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control]

**Git Commands**  
[https://git-scm.com/docs]

**Connecting to GitHub using Terminal**  
[https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository]

**Using .gitignore and Why it's Important**  
[https://docs.github.com/en/get-started/git-basics/ignoring-files]