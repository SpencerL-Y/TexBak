import os
import sys
i = 1
while i < 10:
    os.system("cd llvm_discussion" + str(i) + " && cp discussion" + str(i) + ".pdf ~/Desktop")
    os.system("cd ..")
    i += 1
