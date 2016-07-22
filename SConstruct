import os

source_dir = './src'
build_dir = './build'

include_dirs = ['include']
program_name = 'DDSService'
program_main = 'DDSMain.cpp'
bin_dir = '#./bin'
cflags = '-std=c++14 -O2'

sources = map(lambda x: x.replace(source_dir, build_dir), filter(lambda x: '.cpp' in x, os.listdir(source_dir)))
libs = []

VariantDir(build_dir, source_dir)

env = Environment(CC        ='g++',
                  CCFLAGS   =cflags,
                  CPPPATH   =include_dirs)

env.Program(program_name, sources, libs=libs)
