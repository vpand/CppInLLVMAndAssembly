message("Configuring coroutine episode...")

add_executable(episode_coroutine_coreturn coreturn.cpp)
add_executable(episode_coroutine_coawait  coawait.cpp)
add_executable(episode_coroutine_coawait_async  coawait_async.cpp)
add_executable(episode_coroutine_coyield  coyield.cpp)
add_executable(episode_coroutine_coyield_async  coyield_async.cpp)
add_executable(episode_coroutine_workflow workflow.cpp)

if (WIN32)
set(Flag_DisExpcet /EHs-c-)
else()
set(Flag_DisExpcet -fno-exceptions)
endif()

# disable optimization to make final machine assembly code more readable
set(CMAKE_BUILD_TYPE Debug)

# disable c++ exception to minimize llvm-ir code
target_compile_options(episode_coroutine_coreturn PRIVATE ${Flag_DisExpcet})
target_compile_options(episode_coroutine_coawait  PRIVATE ${Flag_DisExpcet})
target_compile_options(episode_coroutine_coawait_async  PRIVATE ${Flag_DisExpcet})
target_compile_options(episode_coroutine_coyield  PRIVATE ${Flag_DisExpcet})
target_compile_options(episode_coroutine_coyield_async  PRIVATE ${Flag_DisExpcet})
target_compile_options(episode_coroutine_workflow PRIVATE ${Flag_DisExpcet})
