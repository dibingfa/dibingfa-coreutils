# dibingfa-coreutils
coreutils by dibingfa

gnu coreutils: https://github.com/coreutils/coreutils

man 3 getopt: https://linux.die.net/man/3/getopt

## 进度表

- [ ] basename
- [ ] cat
- [ ] chcon
- [ ] chgrp
- [ ] chmod
- [ ] chown
- [ ] chroot
- [ ] cksum
- [ ] comm
- [ ] cp
- [ ] csplit
- [ ] cut
- [ ] date
- [ ] dd
- [ ] df
- [ ] dir
- [ ] dircolors
- [ ] dirname
- [ ] du
- [x] **echo**: -r -b -g etc for red blue green to print String
- [ ] env
- [ ] expand
- [ ] expr
- [ ] factor
- [ ] false
- [ ] fmt
- [ ] fold
- [ ] getlimits
- [ ] ginstall
- [ ] groups
- [ ] head
- [ ] hostid
- [ ] id
- [ ] join
- [ ] kill
- [ ] link
- [ ] ln
- [ ] local.mk
- [ ] logname
- [ ] ls
- [ ] make-prime-list
- [ ] md5sum
- [ ] mkdir
- [ ] mkfifo
- [ ] mknod
- [ ] mktemp
- [ ] mv
- [ ] nice
- [ ] nl
- [ ] nohup
- [ ] nproc
- [ ] numfmt
- [ ] od
- [ ] paste
- [ ] pathchk
- [ ] pinky
- [ ] pr
- [ ] printenv
- [ ] printf
- [ ] ptx
- [ ] pwd
- [ ] readlink
- [ ] realpath
- [ ] rm
- [ ] rmdir
- [ ] runcon
- [ ] seq
- [ ] sha1sum
- [ ] sha224sum
- [ ] sha256sum
- [ ] sha384sum
- [ ] sha512sum
- [ ] shred
- [ ] shuf
- [ ] sleep
- [ ] sort
- [ ] split
- [ ] stat
- [ ] stdbuf
- [ ] stty
- [ ] sum
- [ ] sync
- [ ] tac
- [ ] tail
- [ ] tee
- [ ] test
- [ ] timeout
- [ ] touch
- [ ] tr
- [ ] true
- [ ] truncate
- [ ] tsort
- [ ] tty
- [ ] uname
- [ ] unexpand
- [ ] uniq
- [ ] unlink
- [ ] uptime
- [ ] users
- [ ] vdir
- [ ] wc
- [ ] who
- [ ] whoami
- [x] **yes**: -n（show line number）-s（sleep NUM seconds between）

## coreutils 编译

第一步：ubuntu 16.04

第二步
```
./bootstrap
./configure FORCE_UNSAFE_CONFIGURE=1 --disable-gcc-warnings
```

第三步：修改 Makefile
```
CFLAGS = -g -O0
```

第四步
```
make
```

第五步：VS Code 配置 launcher.json
```
{
    "version": "0.2.0",
    "configurations": [

        {
            "type": "cppdbg",
            "request": "launch",
            "name": "GDB",
            "program": "${workspaceFolder}/src/echo",
            "cwd": "${workspaceFolder}",
            "args": ["hello"]
        }
    ]
}
```

第六步：点击 debug

![image](https://user-images.githubusercontent.com/25787738/212536995-804b4534-6478-4e66-9965-ce147ddab552.png)
