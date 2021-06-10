    global udiv12864
    global udiv12864r
    global umod12864

    section .text

; u64:u64 udiv12864r(u128, u64)
udiv12864r:
; u64 udiv12864(u128, u64)
udiv12864:          ; 64 := 128/64
    mov r8, rdx     ; save rdx
    mov rdx, rsi
    mov rax, rdi
    ; rdx:rax / r8, rax := q, rdx := r
    div r8
    ret

; u64 umod12864(u128, u64)
umod12864:          ; 64 := 128/64
    mov r8, rdx     ; save rdx
    mov rdx, rsi
    mov rax, rdi
    ; rdx:rax / r8, rax := q, rdx := r
    div r8
	mov rax, rdx
    ret
