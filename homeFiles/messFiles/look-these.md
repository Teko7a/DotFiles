# use docker to start a raw spacevim
docker pull spacevim/spacevim
sudo docker run -it --rm spacevim/spacevim nvim

# to paint
kolourpaint

# to count
cloc

# better htop
glances

# better curl / wget
axel

# easy man
tldr

# vim-diff-mode
vim -d Ac.cpp Wa.cpp

# watch battery
acpi

# save fonts
fc-cache -fv

# prime fuck unordered_map
```txt
107897
126271
```

# use this to control volumn!
pavucontrol

# do system config in bash
bmenu

# do android projection

```cpp
paru -S android-tools scrcpy
```

```bash
adb --version
adb devices
adb shell ip a
adb tcpip 5555
adb devices
adb connect 192.168.0.100:5555
scrcpy
```

# Tencent-meetings
wemeet

# convert a picture into blur and set it as lock wallpaper

 + require: xautolock, imagemagick

```bash
convert wp.png -blur 0x5 i3lockblur.png
```

```bash
#!/bin/zsh
# /usr/bin/i3lcokblur
i3lock -i /home/patricky/.i3lock/pictures/i3lockblur.png
exit 0
```

```bash
# i3config file
# Lock screen
bindsym $mod+q exec --no-startup-id i3lockblur
exec --no-startup-id xautolock -time 10 -locker i3lockblur
```
