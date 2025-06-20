MiniGit: A Lightweight Version Control System
Overview
MiniGit is a custom version control system built with C++, designed to work a lot like Git but on a smaller scale. It lets you track local files, make commits, create branches, and even do merges and diffs — all from the command line. It saves data using the local file system and applies several core data structure and algorithm (DSA) concepts like hashing, trees, directed acyclic graphs (DAGs), and file comparison.
Key Data Structures
Blob: This is how file content is stored   each file is saved as a blob in the .minigit/objects/ directory. The file name is a SHA-1 hash based on its content. What makes this interesting is that files aren’t duplicated unnecessarily; if the content hasn’t changed, the same blob is reused.


Tree: Think of a tree as a folder. It stores references to blobs (files) and other trees (subfolders). Every new commit gets a new tree object representing the current file structure.


Commit: It includes metadata like who made the commit, when, and what files are included. Each commit points to a specific tree, and each is uniquely hashed.


Branch: A branch acts like a named label pointing to a specific commit. It's how Git (and MiniGit) keeps track of different lines of development.


Staging Area: Before committing, files go into the staging area — a sort of prep zone where changes are gathered before they’re officially saved.


Log History: You can walk through previous commits by following the links each commit has to its parent. When you run a git log-like command, it shows all past commits in reverse order, starting from the latest.


Diff: This command helps compare the current version of a file with an older one (or two commits with each other), highlighting what’s been added or removed line by line.


Core DSA Concepts
Hashing: SHA-1 hashing is used for uniquely identifying blobs, trees, and commits.


Trees: The structure reflects directories and is built recursively.


DAGs: Commits form a directed acyclic graph — each commit can have a parent (or multiple, in merges), and this structure helps trace history or find common ancestors.


File Diffing: Files are compared line by line to show differences, useful during commits or merges.


Design Choices
Storage: Everything is stored under a .minigit/ folder in your project directory.


Hashing: Uses SHA-1 from OpenSSL for generating unique IDs.


Trees: Tree objects help organize folders and files in a structured way.


Merging: A simplified version of Git’s three-way merge, including basic conflict handling.


Diff Viewer: Shows clear line-by-line differences for better understanding of changes.


In this assignment we have created a MiniGit to track the changes we have made to our files in an efficient manner but what the difference between this version and the actual Git is that there is no remote repository to work with in this version and the conflict resolution is done manually. To use this MiniGit we have the same commands as the actual git like init with a little twist .

Usage
./minigit init  - used to create a repository
./minigit add <path> - used to add files to the index
./minigit commit -m "message" - commits the changes made to the repo
./minigit log - shows all the git commit history
./minigit branch <name> - creates a branch to work on a new feature
./minigit checkout <branch-or-commit> - make the head pointer point to the current branch or commit 
./minigit merge <branch> - will merge your work on your branch with the main file
./minigit diff <commit1> [<commit2>] - will show the difference between the current version and commit 1.

Limitations of MiniGit
No Remote Repository: not able to collaborate remotely,, limiting it to local use.
Manual Conflict Resolution: Merge conflicts require manual intervention, which can be draining.
Performance: Inefficient for large files or repositories due to in-memory file reading and basic diff algorithm.
Limited Features: Missing advanced Git features like stashing, rebasing, or tags.
Error Handling: Basic checks; lacks robust handling for file permissions or corrupted repositories.
No Binary File Support: Diffing assumes text files, ignoring binary files.
Future Improvements 
Remote Support: Add push/pull to sync with remote repos for collaboration.
Interactive Tools: Improve diff/merge with colored output and conflict markers.
Stash Command: Save and restore uncommitted changes for smoother workflows.
Config File: Store user settings like name/email for personalized commits.
Tags: Add lightweight tags to mark releases or key commits.
Undo Options: Support reset/revert to undo changes or commits.
Compression: Compress objects to save disk space.
Binary Files: Handle non-text files better in add/diff/merge.
Logging: Add operation logs and stats for debugging and insights.
Branch Tools: Include branch deletion, listing, and renaming.
