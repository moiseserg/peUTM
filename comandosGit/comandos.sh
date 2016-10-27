## https://git-scm.com/docs/gittutorial
# It is a good idea to introduce yourself to Git with your name and public email 
# address before doing any operation. The easiest way to do so is:

$ git config --global user.name "Your Name Comes Here"
$ git config --global user.email you@yourdomain.example.com



# Assume you have a tarball project.tar.gz with your initial work. You can place it under Git revision control as follows.

$ tar xzf project.tar.gz
$ cd project
$ git init

# Git will reply

# Initialized empty Git repository in .git/
# You’ve now initialized the working directory—​you may notice a new directory created, named ".git".

# Next, tell Git to take a snapshot of the contents of all files under the current directory (note the .), with git add:

$ git add .

# This snapshot is now stored in a temporary staging area which Git calls the "index". You can permanently store the contents of the index in the repository with git commit:

$ git commit
# This will prompt you for a commit message. You’ve now stored the first version of your project in Git.


## Making changes
# Modify some files, then add their updated contents to the index:

$ git add file1 file2 file3


#You are now ready to commit. You can see what is about to be committed using git diff with the --cached option:

$ git diff --cached
# (Without --cached, git diff will show you any changes that you’ve made but not yet added to the index.) You can also get a brief summary of the situation with git status:

$ git status
On branch master
Changes to be committed:
Your branch is up-to-date with 'origin/master'.
  (use "git reset HEAD <file>..." to unstage)

	modified:   file1
	modified:   file2
	modified:   file3

# If you need to make any further adjustments, do so now, and then add any newly modified content to the index. Finally, commit your changes with:

$ git commit
# This will again prompt you for a message describing the change, and then record a new version of the project.

# Alternatively, instead of running git add beforehand, you can use

$ git commit -a
# which will automatically notice any modified (but not new) files, add them to the index, and commit, all in one step.

# A note on commit messages: Though not required, it’s a good idea to begin the commit message with a single short 
#(less than 50 character) line summarizing the change, followed by a blank line and then a more thorough description. 
#The text up to the first blank line in a commit message is treated as the commit title, and that title is used 
# throughout Git. For example, git-format-patch[1] turns a commit into email, and it uses the title on the Subject
# line and the rest of the commit in the body.


