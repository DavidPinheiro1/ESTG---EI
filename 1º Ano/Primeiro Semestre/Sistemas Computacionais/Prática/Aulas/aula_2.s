	.data
	A:	.word 10
	B:	.word 8
	C:	.word 0
	Z:	.word 2
	
		.text
	main:
		ld r4, A(r0)
		ld r5, B(r0)
		ld r6, Z(r0) 
		dadd r3, r4,r5; r3=10+8
		dadd r3, r3,r6; r3= 18+2
		sd r3, C(r0)
		halt;