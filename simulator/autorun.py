#!/usr/bin/python3.5

from os import walk, path
from sys import argv
from shutil import copyfile
from subprocess import check_output, STDOUT

if (len(argv) < 2): 
	print("Usage: python this_file /path/to/testcase\n\
Note: Run this script under the same folder as your \"single_cycle\" binary, and build your \"single_cycle\" before running. \n");
	exit();
else: 
	validTestcasePath = argv[1];

for (dirPath, dirNames, fileNames) in walk(validTestcasePath): 
	if fileNames == []: 
		continue;
	else: 
		print("test >> %s" % dirPath);
		copyfile(path.abspath(dirPath + "/iimage.bin"), path.abspath("./iimage.bin"));
		copyfile(path.abspath(dirPath + "/dimage.bin"), path.abspath("./dimage.bin"));
		check_output(["./single_cycle"]);
		try: 
			snapshotDiff = check_output(["diff", path.abspath("./snapshot.rpt"), path.abspath(dirPath + "/snapshot.rpt")]);
			error_dumpDiff = check_output(["diff", path.abspath("./error_dump.rpt"), path.abspath(dirPath + "/error_dump.rpt")]);
		except Exception, e: 
			print(e.output);
			exit();
		print("\n");
			
print("All pass!");
