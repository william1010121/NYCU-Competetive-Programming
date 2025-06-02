all: AC WA TLE
CXXFLAGS = -std=c++11 -O2 -g
AC: ./submissions/accepted/G_ac_code_william.cpp
	@echo "Compiling accepted solution..."
	g++ $(CXXFLAGS) -o bin/AC ./submissions/accepted/G_ac_code_william.cpp
	@echo "Accepted solution compiled successfully."

TLE: ./submissions/time_limit/G_time_limit_code_william.cpp
	@echo "Compiling TLE solution..."
	g++ $(CXXFLAGS) -o bin/TLE ./submissions/time_limit/G_time_limit_code_william.cpp
	@echo "TLE solution compiled successfully."

WA: ./submissions/wrong_answer/G_wrong_answer_code_william.cpp
	@echo "Compiling WA solution..."
	g++ $(CXXFLAGS) -o bin/WA ./submissions/wrong_answer/G_wrong_answer_code_william.cpp
	@echo "WA solution compiled successfully."
