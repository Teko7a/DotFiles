ip link set wlp4s0 up
wpa_passphrase cwl archlinux > net.conf
wpa_supplicant -c net.conf -i wlp4s0 &
dhcpcd &
