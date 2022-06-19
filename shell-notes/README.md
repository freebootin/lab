# Notes About Shell

This is a collection of notes about `/bin/sh`, `bash`, `zsh`, `ksh`, etc.

- The `local` keyword exists on both `dash` and the FreeBSD `/bin/sh` implementation.  Good to know, as `local` was the 'killer feature' I used `bash` for.
- When you start calling user defined functions inside user defined functions, that might be a sign you need to upgrade from a shell scripting language.
- How much does your choice in interactive shell actually matter? For programming/non-interactive `/bin/sh` whould really be the only choice, but for interactive it really could be anything.
