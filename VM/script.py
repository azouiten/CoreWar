import os
import sys
import random

comb_list = []
champs_file = open('champs')
champ_names = champs_file.readlines()
#while len(comb_list) < int(sys.argv[1]):
   # champs_to_play = random.choice(champ_names).rstrip('\n\r ') + ' ' + random.choice(champ_names).rstrip('\n\r ') + ' ' + random.choice(champ_names).rstrip('\n\r ') + ' ' + random.choice(champ_names).rstrip('\n\r ')
champs_to_play = 'op_cor/ld_carry.cor op_cor/fork.cor op_cor/lldi_carry.cor op_cor/aff.cor'
 #   if not champs_to_play in comb_list:
  #      comb_list.append(champs_to_play)
comb_list.append(champs_to_play)
errors = []
for i in comb_list:
    cycles = 0
    count = 64
    while count >= 64:
        print('Champs being analyzed -> [ ' + i + ' ] <- cycle ' + str(cycles))
        os.system('vm_champs/corewar ' + i + ' -d ' + str(cycles) + ' -a > dif1')
        os.system('./corewar ' + i + ' -dump ' + str(cycles) + ' > dif2')
        f1 = open('dif1')
        count = len(f1.readlines())
        os.system('diff dif1 dif2 > dif3')
        f3 = open('dif3')
        if f3.readlines() != []:
            mix_cycle = i + ' ' + str(cycles)
            errors.append(mix_cycle)
            print('files differ in ============ [%s] ---- in cycle [%d]' % (i, cycles))
            break
        cycles += 1

print('Done')
print('printing errors')
print(errors)

