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

var1 DB '1','A',"TEST"
v2 DW 05FAh, 45, 0110b
v3 EQU 99
	
.code
start:
	REP MOVSB
	RCL EBX, 1
	TEST EAX,EAX
	CMP AX,VAR1
	DIV EAX,CL

	;terminarea programului
	push 0
	call exit
	
end start