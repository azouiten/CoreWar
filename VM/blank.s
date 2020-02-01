.name       "Batman"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1    # <-- operation 'sti' is pointed to by the label 'loop'
live:
        live %0               # <-- operation 'live' is pointed to by the label 'live'
        ld %-19, r5
        add r7, r5, r7
        ld %0, r2             # <-- and this operation is not pointed to by any labels
	st r5, -19
        zjmp %:loop
