.data
	CR: .word32 0x10000
	DR: .word32 0x10008
	String: .asciiz "OLA MUNDO"

.text
		lwu r1,CR(r0)
		lwu r2,DR(r0)

		;obter caracter
		daddi r3,r0,9
		sd r3,(r1)
		lb r4,(r2)
		
		;Converter em Maiusculas ou Minusculas
		daddi r4,r4,+32
		sb r4, String(r0)
		
		;Mostrar String
		daddi r3,r0,String
		sd r3,(r2)
		daddi r3,r0,4
		sd r3,(r1)
		
		halt
		
	
		