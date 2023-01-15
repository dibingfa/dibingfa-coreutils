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
            "program": "${workspaceFolder}/src/yes",
            "cwd": "${workspaceFolder}",
            "args": ["-s", "1", "hello"]
        }
    ]
}
```

第六步：点击 debug

![image](https://user-images.githubusercontent.com/25787738/212536995-804b4534-6478-4e66-9965-ce147ddab552.png)
