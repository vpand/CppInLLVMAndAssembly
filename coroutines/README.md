# C++20 Coroutines
## Function vs Coroutine
```mermaid
sequenceDiagram
    FnCaller->>Function: Call
    FnCaller-->Function: [sync]
    Function->>FnCaller: Return
    loop coroutine state machine 
        CoCaller->>Coroutine: Call
        Coroutine-->>CoCaller: [sync/async]
        CoCaller-->>Coroutine: 
        Coroutine->>CoCaller: Suspend: co_await/co_yield
        CoCaller->>Coroutine: Resume: coroutine.resume
        Coroutine-->>CoCaller: ...
        CoCaller-->>Coroutine: 
        Coroutine->>CoCaller: Return: co_return
    end
```
## co_return
```llvm
define i64 @_ZN12CoroutineRef8coreturnEv()
define void @__await_suspend_wrapper__ZN12CoroutineRef8coreturnEv_init(ptr %0, ptr %1)
define void @__await_suspend_wrapper__ZN12CoroutineRef8coreturnEv_final(ptr %0, ptr %1)
define i32 @main()
define void @_ZN12CoroutineRef8coreturnEv.resume(ptr %0)
define void @_ZN12CoroutineRef8coreturnEv.destroy(ptr %0)
define void @_ZN12CoroutineRef8coreturnEv.cleanup(ptr %0)
```
```
FILE          LINE    SYMBOL
F: cotask     L: 11   S: promise_type
F: cotask     L: 16   S: get_return_object
F: cotask     L: 21   S: initial_suspend
F: coreturn   L: 8    S: coreturn
F: cotask     L: 30   S: return_void
F: cotask     L: 26   S: final_suspend
F: cotask     L: 13   S: ~promise_type
```
## co_await
```llvm
define i64 @_ZN12CoroutineRef7coawaitEv()
define void @__await_suspend_wrapper__ZN12CoroutineRef7coawaitEv_init(ptr %0, ptr %1)
define void @__await_suspend_wrapper__ZN12CoroutineRef7coawaitEv_await(ptr %0, ptr %1)
define void @__await_suspend_wrapper__ZN12CoroutineRef7coawaitEv_final(ptr %0, ptr %1)
define i32 @main()
define void @_ZN12CoroutineRef7coawaitEv.resume(ptr %0)
define void @_ZN12CoroutineRef7coawaitEv.destroy(ptr %0)
define void @_ZN12CoroutineRef7coawaitEv.cleanup(ptr %0)
```
```
FILE          LINE    SYMBOL
F: cotask     L: 11   S: promise_type
F: cotask     L: 16   S: get_return_object
F: cotask     L: 21   S: initial_suspend
F: coawait    L: 9    S: coawait
F: cowaiter   L: 11   S: await_ready
F: cowaiter   L: 17   S: await_resume
F: cotask     L: 30   S: return_void
F: cotask     L: 26   S: final_suspend
F: cotask     L: 13   S: ~promise_type
```
## co_yield
```llvm
define i64 @_ZN12CoroutineRef7coyieldEv()
define void @__await_suspend_wrapper__ZN12CoroutineRef7coyieldEv_init(ptr %0, ptr %1)
define void @__await_suspend_wrapper__ZN12CoroutineRef7coyieldEv_yield(ptr %0, ptr %1)
define void @__await_suspend_wrapper__ZN12CoroutineRef7coyieldEv_final(ptr %0, ptr %1)
define i32 @main()
define void @_ZN12CoroutineRef7coyieldEv.resume(ptr %0)
define void @_ZN12CoroutineRef7coyieldEv.destroy(ptr %0)
define void @_ZN12CoroutineRef7coyieldEv.cleanup(ptr %0)
```
```
FILE          LINE    SYMBOL
F: cotask     L: 11   S: promise_type
F: cotask     L: 16   S: get_return_object
F: cotask     L: 21   S: initial_suspend
F: coyield    L: 8    S: coyield
F: cotask     L: 35   S: yield_value
F: cotask     L: 30   S: return_void
F: cotask     L: 26   S: final_suspend
F: cotask     L: 13   S: ~promise_type
```
