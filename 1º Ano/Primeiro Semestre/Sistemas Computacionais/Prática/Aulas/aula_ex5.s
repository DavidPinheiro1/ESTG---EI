.data
	CR: .word32 0x10000
	DR: .word32 0x10008
	Mensagem: .asciiz "Iguais!"
	Maior: .asciiz "O maior e: "

.text
		ld r1,CR(r0)
		ld r2,DR(r0)

		daddi r3, r0,8
		sd r3, (r1);
		ld r5,(r2);
		
		sd r3, (r1);
		ld r6, (r2);
		
		bne r5,r6,Diferentes
		
		daddi r3, r0,4
		daddi r4, r0,Mensagem
		sd r4, (r2)
		sd r3,(r1)
		
		j Fim
		
Diferentes:
		daddi r3, r0,4
		daddi r4, r0,Maior
		sd r4, (r2)
		sd r3,(r1)

		dadd r7,r0,r5
		slt r3,r5,r6; Se r5<r6 então r3=1, se nao r3=0
		beq r3,r0,Maximo
		dadd r7,r6,r0

Maximo:	
		daddi r3,r0,2
		sd r7,(r2)
		sd r3,(r1)
		
Fim:	halt
	