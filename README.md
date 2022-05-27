# Dot Files
What? You did reset your os once again? 😅

Thanks to GITHUB, it's easiest thing to restore! 🔏

# Things you need to do firstly
## git
 - install git (or you wont look this file unless using browser 😭).
 - configure your git with:

```bash
ssh-keygen -t rsa -b 4096 -C 'tekola@qq.com'
```

> As a remind, you need to just change the email address ad yours ...

## clone me!

> This will cost much time.

```bash
git clone git@github.com:Teko7a/DotFiles.git --recurse-submodules --remote-submodules
```

## aur (deprecated)

> recently I found that `archlinuxcn` isn't perfect...

 - configure your AUR! `sudo vim /etc/pacman.conf`, add following:

```bash
[archlinuxcn]
SigLevel = Never
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
```
 - also, the mirror list is of necessity. `sudo vim /etc/pacman.d/mirrorlist`

```bash
Server = https://mirrors.ustc.edu.cn/manjaro/stable/$repo/$arch
Server = https://mirrors.tuna.tsinghua.edu.cn/manjaro/stable/$repo/$arch
Server = https://mirrors.sjtug.sjtu.edu.cn/manjaro/stable/$repo/$arch
Server = https://mirrors.zju.edu.cn/manjaro/stable/$repo/$arch
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch
Server = http://mirrors.163.com/archlinux/$repo/os/$arch
Server = http://mirrors.aliyun.com/archlinux/$repo/os/$arch
```

 - and run (or everything will become too slooooooow 💀):

```bash
sudo pacman-mirrors -i -c China -m rank
```

Well, now, you can update and use aur! 

```bash
sudo pacman -Syyu
sudo pacman -S base-devel yay paru
```

And, just run
```bash
paru -S --noconfirm `cat softwareAUR.txt`
```

BTW, update this file daily:

```bash
paru && paru -Qeq > ./softwareAUR.txt
```

## pip

```bash
curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
sudo python get-pip.py
pip install -U pip
```

# fonts

```bash
paru -S ttf-linux-libertine ttf-inconsolata ttf-joypixels ttf-twemoji-color noto-fonts-emoji ttf-liberation ttf-droid wqy-bitmapfont wqy-microhei wqy-microhei-lite wqy-zenhei adobe-source-han-mono-cn-fonts adobe-source-han-sans-cn-fonts adobe-source-han-serif-cn-fonts
```

I've already put the rest to [./AURlist.txt](./AURlist.txt)!

# oh-my-zsh

```bash
sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```
