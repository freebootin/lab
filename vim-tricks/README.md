# Tips and Tricks for Vi/m

## Use control commands inside INSERT mode.

You can use `ctrl+o` to issue normal commands without leaving INSERT mode. Example:

`Ctrl+o 80i- Esc`

- `Ctrl+o` tells vim to expect a normal command,
- `80` is the repetition,
- `i` to insert,
- `-` the character you want to insert,
- `Esc` to leave INSERT mode.

Alternatively you could use:

`Ctrl+o :norm 80ia`
