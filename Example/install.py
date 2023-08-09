import os

os.chdir("./build")
os.system("cmake ..")
os.system("make")
os.system("./example")