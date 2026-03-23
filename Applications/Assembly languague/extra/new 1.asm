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

SIR DB 5,17,15
	
.code
start:
	
	mov esi,0
	mov eax,0
	mov ah,15
	mov ecx,3
	mov al,SIR[esi]
	
	et_loop:
	cmp al,ah
	JAE urmator
	mov al,SIR[esi]
	
	urmator:
	inc esi
	loop et_loop

	;terminarea programului
	push 0
	call exit
	
end start