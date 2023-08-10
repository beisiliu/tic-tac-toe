import os

os.chdir("./build-release")
os.system("cmake ..")
os.system("make")
os.system("./tic-tac-toe ")