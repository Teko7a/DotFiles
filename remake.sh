# ! /bin/bash
echo "install aur softwares"

paru -S `cat ./softwareAUR.txt` --noconfirm --ignore

echo "[OK] installed all you want!"

echo "install pip!"
wget https://bootstrap.pypa.io/get-pip.py
python get-pip.py
python -m pip install --upgrade pip

read -p 'This is Dangerous! Confirm [y/n]? '  confirm

if [ $confirm == 'y' ]; then
  echo "[OK] resetting..."
  # this will set a backup file end with '~' if 'mv' crushed
  cp -rb `cat ./mvList.txt` ~/.config
  cp -rb ./homeFiles/.* ~
else
  echo "[G O O D B Y E]"
fi

echo "oh-my-zsh!"
sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"

echo "[OK] all ready!"
