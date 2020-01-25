.name       "notbatman2"
.comment    "This city needs me"

live:
	live %-1
	ld %5, r2
	ld %9, r3
add r2, r3, r4
st r4, :live
