# C Programming in BSD

This is just a collection of things I learned while learning C on a FreeBSD box.

- To read from `stdin` use `gets_s` as `gets` has been removed from FreeBSD's `libc`.  There is also `fgets` which does the same thing, but from an arbitrary file descriptor. 
