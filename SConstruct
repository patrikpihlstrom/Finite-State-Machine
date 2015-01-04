print '\x1b[31m' + "\n--------------------Finite-State-Machine--------------------" + '\033[0m'

libs = Split("""
sfml-graphics
sfml-window
sfml-system
""")

sources = Split("""
src/application/main.cpp
src/application/Application.cpp
src/state/TestStates.cpp
""")

Program(target = 'Finite-State-Machine', source = sources, LIBS = libs, CXXFLAGS = "-std=c++11")
