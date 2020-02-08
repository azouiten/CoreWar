.name    "sebc"
.comment "sebc"

	st	r1, 10
	ld	%4, r3
	live	%1
	ld	%10, r2
	ldi	%10, r2, r4
	sti	r4, %10, r2
	add	r2, r3, r2
	zjmp	%10
	xor	r4, r4, r4
	zjmp	%10
