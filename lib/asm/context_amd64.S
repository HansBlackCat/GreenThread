#ifdef __APPLE__
    #define SET_CONTEXT _set_context
    #define SWITCH_CONTEXT _switch_context
#else
    #define SET_CONTEXT set_context
    #define SWITCH_CONTEXT switch_context
#endif

.global SET_CONTEXT
.global SWITCH_CONTEXT

.text
.align 4

SET_CONTEXT:
        pushq %rbp
        movq  %rsp, %rbp
        
        movq  %rbx, 0x00(%rdi)
        movq  %rbp, 0x08(%rdi) 
        movq  %r12, 0x10(%rdi)
        movq  %r13, 0x18(%rdi)
        movq  %r14, 0x20(%rdi)
        movq  %r15, 0x28(%rdi)
        movq  %rsp, 0x30(%rdi)
        movq  %rdx, 0x38(%rdi) 

        xor   %eax, %eax        
        inc   %eax             /* returns 1 */
        popq  %rbp
        ret

.text
.align 4

SWITCH_CONTEXT:
        pushq %rbp
        movq  %rsp, %rbp

        movq  0x00(%rdi), %rbx
        movq  0x08(%rdi), %rbp
        movq  0x10(%rdi), %r12
        movq  0x18(%rdi), %r13
        movq  0x20(%rdi), %r14
        movq  0x28(%rdi), %r15
        movq  0x30(%rdi), %rsp
        movq  0x38(%rdi), %rdx

        xor   %eax, %eax
        inc   %eax             /* returns 1 */
        popq  %rbp
        ret

