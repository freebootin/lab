# Notes About Shell

This is a collection of notes about `/bin/sh`, `bash`, `zsh`, `ksh`, etc.

- The `local` keyword exists on both `dash` and the FreeBSD `/bin/sh` implementation.  Good to know, as `local` was the 'killer feature' I used `bash` for.
- When you start calling user defined functions inside user defined functions, that might be a sign you need to upgrade from a shell scripting language.
