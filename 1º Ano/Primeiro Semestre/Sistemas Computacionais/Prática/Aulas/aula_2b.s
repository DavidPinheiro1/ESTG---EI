	.data
	A:	.word 10
	B:	.word 8

	
		.text
		ld r4, A(r0)
		ld r5, B(r0)
		
		dadd r3, r4,r0
		dadd r4, r5,r0
		dadd r5, r3,r0
		
		sd r4, A(r0)
		sd r5, B(r0)
		halt;