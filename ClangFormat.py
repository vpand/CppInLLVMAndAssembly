import os
import sys
import subprocess

def paths(path):
    path_collection = []
    for dirpath, dirnames, filenames in os.walk(path):
        for file in filenames:
            fullpath = os.path.join(dirpath, file)
            path_collection.append(fullpath)
    return path_collection
    
clang_format = os.getenv('CLANG_FORMAT')
if not clang_format or not os.path.exists(clang_format):
     print('CLANG_FORMAT env is missing.')
     sys.exit(-1)

thisdir = os.path.dirname(__file__)
if len(thisdir) == 0:
     thisdir = '.'

def main():
    srcexts = ['.c', '.cc', '.cpp', '.h', '.hpp', '.m', '.mm']
    for p in paths(thisdir):
        if p.find('build') >= 0 or p.find('.git') >= 0:
            continue
        for ext in srcexts:
            if p.endswith(ext):
                print('Formatting "%s" ...' % (p))
                subprocess.Popen([clang_format, '-i', '-style=LLVM', p]).wait()
                break

if __name__ == '__main__':
    main()
