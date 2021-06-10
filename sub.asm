    global sub128

    section .text
sub128:
    sub rdi, rdx ; arg[0] - arg[2], save CF
    sbb rsi, rcx ; arg[1] - arg[3] - CF from previous subtraction
    mov rax, rdi
    mov rdx, rsi
    ret
