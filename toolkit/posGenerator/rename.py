import os

rootdir = './neg'

count = 1

for file in os.listdir(rootdir):
	os.rename(os.path.join(rootdir,file), os.path.join(rootdir,str(count)+".jpg"))
	count += 1