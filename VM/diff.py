import os

cycle = int(input("Cycle: "))
champs = input("Champs: ")
count = 64
quit = 0
while count >= 64:
	print("It is now cycle: " + str(cycle))
	os.system('./ocorewar ' + champs + ' -d ' + str(cycle) + ' -a ' + ' > dif1')
	os.system('./corewar ' + champs + ' -d ' + str(cycle) + ' > dif2')
	os.system('diff dif1 dif2 > mok')
	mok = open('mok')
	lines = mok.readlines()
	if len(lines) != 0:
		print('Files are diffrent in cycle: ' + str(cycle))
		break
	dif1 = open("dif1")
#	dif2 = open("dif2")
	list1 = dif1.readlines()
#	list2 = dif2.readlines()
	count = len(list1)
#	if len(list1) != len(list2):
#		print("Files diffrent length in cycle: " + str(cycle) + ' [' + str(len(list1)) + ' , ' + str(len(list2)) + '].')
#		break
#	for i in range(len(list1)):
#		if list1[i] != list2[i]:
#			print("Files diffrent in cycle: " + str(cycle))
#			quit = 1
#			break
#	if quit:
#		break
	cycle += 1
print("Everything is good till cycle: " + str(cycle))
