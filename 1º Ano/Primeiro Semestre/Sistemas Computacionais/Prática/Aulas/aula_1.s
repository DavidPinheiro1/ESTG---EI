	.data
	A:	.word 10; Isto é o mesmo que int.
	B:	.word 8
	C:	.word 0
	
		.text
		ld r4, A(r0); Colocar no R4 o valor da variavel A.
		ld r5, B(r0)
		dadd r3, r4,r5; dadd faz somas --> r3 = r4 + r5
		sd r3, C(r0); Copia valor de r3 para colocar na variavel C.
		halt;