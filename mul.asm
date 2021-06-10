    global umul64
    global smul64

    section .text
umul64:
    mov rax, rdi
    mul rsi ; rdx:rax := rax * rsi
    ret

smul64:
    mov rax, rdi
    imul rsi ; rdx:rax := rax * rsi
    ret