.386
.model flat, stdcall
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;includem msvcrt.lib, si declaram ce functii vrem sa importam
includelib msvcrt.lib
extern exit: proc
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;declaram simbolul start ca public - de acolo incepe executia
public start
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;declararea datelor
.data

	sir1 db '1','*','A','a','B','2','3','#','x','a','1','E','e','/'
	sir2 db 10 dup(0)
	sir3 db 10 dup(0)
	sir4 db 10 dup(0)
	
.code
start:
	mov eax, 0
	mov ecx, 0

	mov cx,14
	mov esi,0
	mov edi,0
	mov ebx,0
	mov ebp,0
	
et:
	mov al,sir1[esi]
	cmp al,'0'
	jb urm
	cmp al,'9'
	ja big_letter
	
	mov sir2[ebx],al
	inc ebx
	jmp urm

big_letter:
	cmp al, 'A'
	jb urm
	cmp al, 'Z'
	ja litera
	
	mov sir4[ebp], al
	inc ebp
	jmp urm
	
litera:
	cmp al,'a'
	jb urm
	cmp al,'z'
	ja urm
	
	mov sir3[edi],al
	inc edi
	
urm:
	inc esi
	loop et
	
	;terminarea programului
	push 0
	call exit

end start