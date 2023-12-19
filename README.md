# Github

## Git clone
- Create the repository on GitHub first.
- Use "git clone (github url)" when you want to clone a github repository into a local folder.

## Git status
- Make sure to be in the directory and to save your files first.
- Use "git status" to check if there have been any changes to files that were not added, committed, then pushed to the origin yet.

## Git add .
First step:
- Use "git add ." to add all of the changes made to any files. Only do this for files that you just created, not modified.

## Git commit -m " " -m " "
Second step:
- Use git commit -m "(message)" -m "(message) " to commit the add you did in step one.
- If you already created the file then you can type git commit -am " " to do step 1 and step 2 together.

## Git push
Third step:
- Use "git push" to push the commits to the origin.
- Press "cancel" then sign in to github with your username and password.

## Git pull
- Use "git pull" to pull any changes made in the origin to your local files.

## Git branching
- Branching is good to learn when working with others. It creates temporary repositorites to do some code in that will eventually be merged it into the main repository.
- Type "git branch" to list all branches
- - To create a new branch, type "git checkout -b (name)"
- Type "git checkout (branch)" to change between branches. For the (branch), you can just type the first letters and TAB to finish.
- "git diff" shows you what has been changed
- "git merge (branch)" merges the branches and pushes the changes
- "git branch -d (branch)" deletes the branch

## Undoing git
- "git reset" will undo any adds that you have.
- "git reset (file)" will undo any changes from the file you just made changes to.
- "git reset HEAD~1"  will undo the last commit
- "git log" gives a list of all previous commits. You can find the hash of a commit to paste into "git reset (hash)", which undos a specific commit.
- "git reset --hard (hash)" will completely remove all the changes in this specific commit.

# Linux

## Basic Commands
- "ls" will show all directories/files in current directory
- "cd" will change to ~
- "cd .." will change to the last directory
- "cd (directory)" will change to that directory
- "mkdir (directory)" will make a directory with that name
- "mv (file) (directory)" will move the file to that directory
- "mv (file) (file)" will change the file's name
- "sudo apt-get update" will update linux

## Python3
- Type "python3 (file)" in the terminal to run a python program

## C++
- Type "make (file.cpp)" or "g++ (file.cpp) -o (file)" to compile a .cpp file
- Type "./(file)" to run the .cpp file

### Debugging
- Type "sudo apt-get update" and "sudo apt-get install gdb"
- Type "g++ (file.cpp) -g" to create an a.out file
- Type "gdb a.out" or "gdb a.out --tui" and enter to start debugging
- "b (line #)" will set a breakpoint at this line
- "run" will start the debugging sequence
- "n" will go to the next line
- "p (variable)" will tell you the value of a current variable
- "s" will enter inside of a function call
- "backtrace" will show you when you entered what function
- "f" will tell you what line you're on

## PostgreSQL

### Installation / Entering PSQL
- Update linux & type "sudo apt-get install postgresql-contrib" in the terminal
- To get to psql, type "sudo su postgres" then "psql" in the terminal
  - Another way is to type "sudo -u postgres psql" in the terminal
  - Another way is to type "sudo -i -u postgres" & then "psql" in the terminal
  - Another way, and to enter as the user you want, is to type "sudo -u (user) psql" in terminal
- "\q" or "exit" will exit psql

### Users
- To create a user, type "CREATE USER (user) WITH PASSWORD '(password)';" in psql
  - Another way is to type  "sudo -u postgres createuser --interactive" in the terminal
- To add attributes to a user, type "ALTER USER (user) WITH (attribute);" in psql
- To show how many users there are, type "\du" in psql
- To delete a user, type "DROP USER (user);" in psql

### Databases
- To create a database type "CREATE DATABASE (database);" in psql
  - Another way is to type "sudo -u postgres createdb (database)" in the terminal
- (Necessary for every database): To configure the database type "psql -h localhost -p 5432 -U postgres (database)" in the terminal
- To allow a user to do anything with a database, type "GRANT ALL PRIVILEGES ON DATABASE (database) TO (user);"
- To switch to a database, type "\c (database)" in psql
- To know what user/database you're in, type "\conninfo" into the psql
- To show how many databases there are, type "\l" in psql
- To delete a database, type "DROP DATABASE (database);" in psql

### \i & \o Commands
- Must configue the database before using these commands (check above)
- Type "\i (file path)" to execute the commands from a file
- Type "\o (file path)" then "(queries)" then "\o" to send all query results to a file
