    global add128

    section .text
add128:
    add rdi, rdx ; arg[0] + arg[2], save CF
    adc rsi, rcx ; arg[1] + arg[3] + CF from previous addition
    mov rax, rdi
    mov rdx, rsi
    ret