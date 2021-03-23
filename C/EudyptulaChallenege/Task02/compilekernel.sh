#!/usr/bin/env bash
# Task 02: A simple program to compile a custom kernel on Fedora 33
# Script is Fedora specific, however, it should not be difficult to
# modify it  for Debian based distros and few tweaks will make the
# script work for those distros.

GIT=$(command -v \git)
URL="https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/"
CLONEDIR="torvalds"

LSMOD=$(command -v \lsmod)
YES=$(command -v \yes)

SED=$(command -v \sed)
MAKE=$(command -v \make)
TIME=$(command -v \time)
SLEEP=$(command -v \sleep)
GRUB=$(command -v \grub2-mkconfig)

# clone torvalds tree
$GIT clone $URL $CLONEDIR

cd $CLONEDIR

BASEDIR="$(echo $PWD)"

echo "-------------------------------------"
echo " Generating a list of loaded modules "
echo "-------------------------------------"
$LSMOD > /tmp/$(uname -r)-modules
# create config file based on the list of currently loaded modules
echo "------------------------------------------------"
echo " Creating a config file based on loaded moudles "
echo "------------------------------------------------"
$YES "" | make LSMOD=/tmp/$(uname -r)-modules localmodconfig

$SED -i '/# CONFIG_LOCALVERSION_AUTO'/c\CONFIG_LOCALVERSION_AUTO=y' $BASEDIR/.config
# Fedora 33 specific change needed to compile the kernel successfully
$SED -i '/CONFIG_DEBUG_INFO_BTF'/c\# CONFIG_DEBUG_INFO_BTF is not set' $BASEDIR/.config

# compile the kernel
echo "----------------------"
echo " Compiling the kernel "
echo "----------------------"
$TIME $MAKE -j$(nproc)

echo "------------------------------------------- "
echo " About to install kernel modules and kernel "
echo " Press CTRL-C to abort within 10 seconds "
echo "--------------------------------------------"

$SLEEP 10

# install the modules and kernel
echo "--------------------------------------"
echo " Installing kernel and kernel modules "
echo "--------------------------------------"
$MAKE modules_install install

$SLEEP 4

# update grub to take notice of newly installed kernel
echo "--------------------------------------------"
echo " Updating grub to take notice of new kernel "
echo "--------------------------------------------"
$GRUB -o /boot/efi/EFI/fedora/grub.cfg
