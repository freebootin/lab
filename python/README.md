# Python Notes

I'm not a fan of python, but if I must use it then I should at least know what I'm doing.

## Don't install modules/packages globally.

When using `pip` to install modules/packages, use `pip install --user` to install into the `home` directory.  Usually this dumps the code into `~/.local/` somewhere.  You want to do this because many/most/too many Unix based OS's depend on `python` and at least some modules.  If you start installing things globally then you run the risk of updating or overwriting some OS specific package.  That could potentially break your OS install. So use `pip install --user` or a virtual environment like `venv` instead.

## Packages for useful functionality

Preference should always be for the standard library though.
Unless noted, these should all work cross platform (Linux/BSD/Windows/Mac).

- `watchdog` for event monitoring.
- `pynput` for reading/controlling the keyboard/mouse. 
