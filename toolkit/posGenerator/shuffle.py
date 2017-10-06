import os
import random

rootdir = './rear_car'
targetdir = './rear_car_2'

count = 1

pos_list = []

for file in os.listdir(rootdir):
	# os.rename(, os.path.join(rootdir,str(count)+".jpg"))
	pos_path = os.path.join(rootdir,file)
	pos_list += [pos_path]

for i in xrange(0, len(pos_list)):
	rand_pos = i + random.randint(0, len(pos_list) - i - 1)

	tmp = pos_list[i]
	pos_list[i] = pos_list[rand_pos]
	pos_list[rand_pos] = tmp

for item in pos_list:
	os.system ("cp %s %s" % (item, targetdir + '/' + str(count) + '.jpg'))
	count += 1
