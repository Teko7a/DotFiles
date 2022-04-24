# DotFiles
What? You did reset your os once again? 😅

Thanks to GITHUB, it's easiest thing to restore! 🔏

# Things you need to do firstly
## git
 - install git (or you wont look this file unless using browser 😭).
 - config your git with:

```bash
ssh-keygen -t rsa -b 4096 -C 'tekola@qq.com'
```

> of course, I think there is nobody will use your dotfiles ...  But as a remind, you need to just change the email address ad yours ...

## clone me!

```bash
git clone --recurse-submodules git@github.com:Teko7a/DotFiles.git
```

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
# install aur helper
# and build tools
sudo pacman -Syyu
sudo pacman -S base-devel yay paru
```

And, just run
```bash
paru -S --noconfirm `cat softwareAUR.txt`
```

btw, update this file daily:

```bash
paru
paru -Qeq > ./softwareAUR.txt
```

## pip

```bash
curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
sudo python get-pip.py
pip install -U pip
```

# fonts

.. just as a remind, i think you've already read the file
[look-these.md](./messFiles/look-these.md)

Look the file [fonts](./fontsGIT.txt) will lead you.

# oh-my-zsh

Use this! 💗

```bash
git clone git@github.com:ohmyzsh/ohmyzsh.git ~/.oh-my-zsh
```

# neovim
After auto download, you need to:

 - Run `sudo yarn global neovim` and goto `coc.nvim`, then run `yarn install`.

 - goto the `markdown-preview.nvim/app`，and run `yarn install`

# virtual machine

run `neofetch` to get your kernel version first, and install `linux510-virtualbox-host-modules` (replace the `510` to your kernel version)
