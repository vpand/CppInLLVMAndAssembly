# cmake
cmake_minimum_required(VERSION 3.20)
project(CppInLLVMAndAssembly)

# c++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_BUILD_TYPE Release)

# clangvmp
if (NOT ClangVMP_Dir)
  set(ClangVMP_Dir $ENV{HOME}/VPAssistant/product/clangvmp)
endif()
if (NOT EXISTS ${ClangVMP_Dir})
  message(WARNING "Please specify the ClangVMP installation directory with ClangVMP_Dir.")
endif()
if (WIN32)
  # on Windows, we must prefer clang-cl/lld-link to build exe
  # for more information, see https://github.com/vpand/vmpusermanual/blob/main/ClangVMP.md#cmake-for-windows
  set(CMAKE_CXX_COMPILER ${ClangVMP_Dir}/bin/clang-cl.exe)
  set(CMAKE_LINKER ${ClangVMP_Dir}/bin/lld-link.exe)
  if (NOT EXISTS CMAKE_CXX_COMPILER)
    message(WARNING "Please install the ClangVMP as a Visual Studio installation type.")
  endif()
else()
  set(CMAKE_CXX_COMPILER ${ClangVMP_Dir}/bin/clang++)
endif()

# sub project

# clangvmp function and environment check
add_subdirectory(clangvmp)
add_subdirectory(llvmir)
# episodes
add_subdirectory(coroutines)
