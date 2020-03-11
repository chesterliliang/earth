# How to get started with the code
## 1.Directory struct
```
.
|--src
    |--comm //read write function
    |--platform //interface api on different platform
|--doc //necessary docs
|--tools //tools for test
|--test //test vectors
|--readme.md

```

## 2.Build and RUN
```
git clone https://github.com/chesterliliang/prime-c-lib.git

make
```

or if you prefer cmake

```
cd build
cmake .
make
```

If you can run the code binary on you platform, here is the reference:
```
./prime
```
or you may need sudo to aceess uart
```
sudo ./prime
```
Check UART device on Linux and OSX
```
dmesg | grep tty.S*
ls /dev/tty.S*
```
## 3. Trouble Shooting

Submit issues on github.
