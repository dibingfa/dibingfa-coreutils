# dibingfa-coreutils
coreutils by dibingfa

gnu coreutils: https://github.com/coreutils/coreutils

man 3 getopt: https://linux.die.net/man/3/getopt

### coreutils 编译

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
make CFLAGS='-Wno-error=suggest-attribute=const' -j4
```

第五步：VS Code 配置 launcher.json
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "type": "gdb",
            "request": "launch",
            "name": "GDB",
            "program": "${workspaceFolder}/src/echo",
            "stopOnEntry": false,
            "arguments": "hello"
        }
    ]
}
```

第六步：点击 debug

![image](https://user-images.githubusercontent.com/25787738/212536995-804b4534-6478-4e66-9965-ce147ddab552.png)
