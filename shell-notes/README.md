# Notes About Shell

This is a collection of notes about `/bin/sh`, `bash`, `zsh`, `ksh`, etc.

- The `local` keyword exists on both `dash` and the FreeBSD `/bin/sh` implementation.  Good to know, as `local` was the 'killer feature' I used `bash` for.
- When you start calling user defined functions inside user defined functions, that might be a sign you need to upgrade from a shell scripting language.
- How much does your choice in interactive shell actually matter? For programming/non-interactive `/bin/sh` whould really be the only choice, but for interactive it really could be anything.
- It appears that you cannot call an exported BASH function from inside a shell script. This seems to be true regardless of the shebang line. 
- It is possible to have a "multi-call shellscript", similar to how busybox runs.  This can be done by checking the $0 variable (the process name) and running code based on its value.
