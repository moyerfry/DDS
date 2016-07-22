import os

source_dir = '#./src'
build_dir = '#./build'

VariantDir(build_dir, source_dir, duplicate=0)

include_dirs = ['include']
program_name = 'DDSService'
program_main = 'DDSMain.cpp'
bin_dir = '#./bin'
cflags = '-std=c++14 -O2'

source_paths = ['./' + source_dir]
libs = []

VariantDir(build_dir, source_dir)

env = Environment(CC        ='g++',
                  CCFLAGS   =cflags,
                  CPPPATH   =include_dirs,
                  BINDER    =bin_dir)

env.Program(program_name, program_main, Glob(build_dir + '/*.cpp'))
