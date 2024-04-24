# CppInLLVMAndAssembly
Deep insight of C++ in LLVM-IR and Assembly perspective.

## CMake On Windows
In "x64 Native Tools Command Prompt for VS 2022" command prompt:
```shell
mkdir build
cd build
cmake .. -G Ninja
```

## CMake On macOS or Linux
```shell
mkdir build
cd build
cmake ..
```

## Build
```shell
cmake --build .

[1/6] Building CXX object llvmir\CMakeFiles\main-llvmir.dir\main.cpp.obj
Using config file ..\llvmir\clangvmp.json.
Using source file vmp config key : main.cpp.
llvmir: main
Created LLVM-IR partial file llvmir\CMakeFiles\main-llvmir.dir\main.cpp.ll.
[2/6] Building CXX object clangvmp\CMakeFiles\clangvmp-demo.dir\main.cpp.obj
Using config file ..\clangvmp\clangvmp.json.
Using source file vmp config key : main.cpp.
vmpre: main
vmp: main
+> Encoding UraniumVCPU function main (1/1)...
[5/6] Building CXX object coroutines\CMakeFiles\episode_coroutine.dir\main.cpp.obj
Using config file ..\coroutines\clangvmp.json.
Using source file vmp config key : main.cpp.
llvmir: Coroutine
llvmir: main
Created LLVM-IR partial file coroutines\CMakeFiles\episode_coroutine.dir\main.cpp.ll.
[6/6] Linking CXX executable coroutines\episode_coroutine.exe
```