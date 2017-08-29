.name "zork"
.comment "I'M ALIIIIVE"

l2:	sti	r1,%:live,%:l3
	and	r1,%0,r1
live: live %1
	zjmp %:live

l3: zjmp %:l2
