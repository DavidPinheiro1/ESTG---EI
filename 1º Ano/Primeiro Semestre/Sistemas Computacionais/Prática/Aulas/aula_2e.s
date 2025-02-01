.data
	CR: .word32 0x10000
	DR: .word32 0x10008
	Mensagem: .asciiz "Hello World!"
	Iguais: .asciiz "Iguais!"
	Contrario: .asciiz "O maior e:"
	
		.text
		ld r1,CR(r0)
		ld r2,DR(r0)

	Msg:
		daddi r4, r0,Mensagem
		sd r4, (r2)
		daddi r3, r0,4
		sd r3,(r1)
		
		daddi r3, r0,8
		sd r3, (r1)
		ld r10,(r3)
		ld r20, (r10)
		
		daddi r3, r0,8
		sd r3, (r1)
		ld r11, (r3)
		ld r21, (r11)
		
		beq r20,r21, igual
		bne r20,r21, contr
		
	igual:
		daddi r12, r0,Iguais
		sd r12, (r2)
		daddi r3, r0,4
		sd r3,(r1)	
		
		
	contr:
		daddi r4, r0,Contrario
		sd r4, (r2)
		daddi r3, r0,4
		sd r3,(r1)
		
	
	
		
		halt;