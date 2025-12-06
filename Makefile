# Regular clang++ on Windows (MSVC toolchain)
CXX = clang++
CXXFLAGS = -std=c++23

LIB_DIR = C:\IconsForAri\devlibs
INC_DIR = C:\IconsForAri\devlibs\include
BUILD = build

all: default

shared:
	$(CXX) $(CXXFLAGS) -shared calc.cpp -o libcalc.dll

default:
	$(CXX) $(CXXFLAGS) main.cpp -L$(LIB_DIR) -I$(INC_DIR) -llibcalc -o $(BUILD)\main.exe
