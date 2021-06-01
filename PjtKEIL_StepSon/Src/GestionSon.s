	PRESERVE8
	THUMB   
	EXPORT CallbackSon
	EXPORT StartSon
	import Son
	export SortieSon	
	import LongueurSon
	include DriverJeuLaser.inc 
	
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		
index dcd 0	
SortieSon dcd 0
	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

CallbackSon proc
	
	
	
	;initialisation des variables
	push{r4}
	LDR R1,=Son
	LDR R3,=index
	
	LDR R12,=LongueurSon
	LDR R12,[R12]
	LDR R2,[R3]
	; on regarde dans son a l'index donné 
	LDRSH R0,[R1,R2,lsl#1]
	
	CMP R2,R12
	;on regarde si on est en fin de "tableau"
	BGE Fin
	;incrementation de l'index
	; R2 = R2 +1
	ADD R2,R2,#1

	STR R2,[R3]
	;on met R0 entre [0;719]
	
	ldr R1,=SortieSon
	MOV R4,#719
	ADD R0,R0,#32768
	MUL R0,R0,R4
	ASR R0,R0,#16
	
	STR R0,[R1]
	push {R0,R1,R2,R3,R4,R12,lr}
	bl PWM_Set_Value_TIM3_Ch3
	pop {R0,R1,R2,R3,R4,R12,lr}
	pop{r4}
	
Fin
	

	
	
	
	bx lr 

	endp
		
		
StartSon proc
	LDR R3,=index
	LDR R2,[R3]
	MOV R2,#0
	STR R2,[R3]
	bx lr
	endp

		
		
END	