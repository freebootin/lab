# Changing Screen Brightness On CLI

This requires xrandr.

1. First find the name of your display. Use `xrandr --prop | grep " connected"`
1. The first word will be the name of the display ex. `LVDS-1` or `HDMI-0`
1. To find the brightness use `xrandr --prop --verbose | grep -A10 " connected" | grep "Brightness"`. This will show your screen brightness from 0.0 to 1.0.
1. To change the brightness use `xrandr --output 'your-display-name' --brightness x.x`, where x.x is from 0.0 to 1.0.
