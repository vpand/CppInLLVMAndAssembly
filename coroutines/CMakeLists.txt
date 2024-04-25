message("Configuring coroutine episode...")
add_executable(episode_coroutine_coreturn coreturn.cpp)
add_executable(episode_coroutine_workflow workflow.cpp)

if (WIN32)
set(Flag_DisExpcet /EHs-c-)
else()
set(Flag_DisExpcet -fno-exceptions)
endif()

# disable c++ exception to minimize llvm-ir code
target_compile_options(episode_coroutine_coreturn PRIVATE ${Flag_DisExpcet})
target_compile_options(episode_coroutine_workflow PRIVATE ${Flag_DisExpcet})
