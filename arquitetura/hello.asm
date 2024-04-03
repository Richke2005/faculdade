section .data
    msg db 'Hello, World!', 0

section .text
    global _start

_start:
    ; Escreve a mensagem na saída padrão (stdout)
    mov eax, 4         ; syscall número 4 (sys_write)
    mov ebx, 1         ; file descriptor 1 (stdout)
    mov ecx, msg       ; ponteiro para a mensagem
    mov edx, 13        ; tamanho da mensagem
    int 0x80           ; chama o kernel

    ; Termina o programa
    mov eax, 1         ; syscall número 1 (sys_exit)
    xor ebx, ebx       ; código de retorno 0
    int 0x80           ; chama o kernel
