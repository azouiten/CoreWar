.name       "bomberman"
.comment    "booom"

start:
		sti r1, %:live, %1		#put the value of  the player after the live call

live:
	live %0						#declaring live
	ld %4, r4
	ld %-64, r6
	ldi %:live, r5, r3
	sti r3, %:end, r5
	add r5, r4, r5
	add r6, r5, r2					#set the carry to 1
	zjmp %:reset
	ld %0 ,r2
	zjmp %:live				#jump to the start of the ex-code

reset:
	ld %0, r5
end:
