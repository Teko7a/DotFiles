# DotFiles
What? You did reset your os once again? 😅

Thanks to GITHUB, it's easiest thing to restore!
🔏

# Things you need to do firstly
## git
 - install git (or you wont look this file unless using browser 😭).
 - config your git with:

```bash
ssh-keygen -t rsa -b 4096 -C 'tekola@qq.com'
```

> of course, I think there is nobody will use your dotfiles ...  But as a remind, you need to just change the email address ad yours ...

## aur

 - config your aur! `sudo vim /etc/pacman.conf`, add following:

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
sudo pacmna -S yay
yay -S paru
```

And, just use `paru -S softwareAUR.txt`.

btw, get this file as usual:

```bash
paru -Qeq > ./softwareAUR.txt
```

## pip

```bash
wget https://bootstrap.pypa.io/get-pip.py
python get-pip.py
python -m pip install --upgrade pip
```

# fonts

.. just a notification, i think you've already read the file `./messFiles/look-these.md`

Also, the file [fonts](./fontsGIT.txt) will lead you. This is a long file. you just need to `vim -d yourFont ./fonts.txt`

# oh-my-zsh

Use this! 💗

```bash
git clone git@github.com:ohmyzsh/ohmyzsh.git ~/.oh-my-zsh
```

# neovim

Run `sudo yarn global neovim`.

goto the `markdown-preview.nvim/app`，and run `yarn install`

# virtual machine

run `neofetch` to get your kernel version first, and install `linux510-virtualbox-host-modules` (replace the `510` to your kernel version)


