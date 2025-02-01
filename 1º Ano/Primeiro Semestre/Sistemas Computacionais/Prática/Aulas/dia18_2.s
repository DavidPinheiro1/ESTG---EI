.data
	CR: .word32 0x10000
	DR: .word32 0x10008
	String: .asciiz "ola mundo"

.text
		lwu r1,CR(r0)
		lwu r2,DR(r0)
		
		
		;i=0
		;while String[i]!=0
			;if minuscula
				; converter a String[i]
			;i++
						
		
		;contador a 0
		daddi r5,r0,0
		
While:		
		lb r4,String(r5)
		beqz r4,FimWhile; while String[i]!=0
		slti r3,r4,97; character < 'a'
		bnez r3,NaoConverte
		slti r3,r4,123; character < 'z'
		beqz r3,NaoConverte
		
		;Para converter:
		daddi r4,r4,-32
		sb r4,String(r5)

NaoConverte:
		daddi r5,r5,1; i++
		j While

FimWhile:
		
		;Mostrar String
		daddi r3,r0,String
		sd r3,(r2)
		daddi r3,r0,4
		sd r3,(r1)
		
		halt
		
	