all: AC TLE WA

CXXFLAGS = -std=c++11 -O2
AC: ./submissions/accepted/F_ac_code_william.cpp
	@echo "Compiling accepted solution..."
	g++ $(CXXFLAGS) -o bin/AC ./submissions/accepted/F_ac_code_william.cpp
	@echo "Accepted solution compiled successfully."

TLE: ./submissions/time_limit/F_time_limit_code_william.cpp
	@echo "Compiling TLE solution..."
	g++ $(CXXFLAGS) -o bin/TLE ./submissions/time_limit/F_time_limit_code_william.cpp
	@echo "TLE solution compiled successfully."

WA: ./submissions/wrong_answer/F_wrong_answer_code_william.cpp
	@echo "Compiling WA solution..."
	g++ $(CXXFLAGS) -o bin/WA ./submissions/wrong_answer/F_wrong_answer_code_william.cpp
	@echo "WA solution compiled successfully."
