i=0
g++ -std=c++20 code.cpp -o run
g++ -std=c++20 brute.cpp -o brute
while true;
do
    echo $i
    i=$(($i+1))
    python3 gen.py > input.txt
    ./run < input.txt > output.txt
    ./brute < input.txt > brute.txt
    diff output.txt brute.txt
    if [ $? -ne 0 ];  then
        break
    fi
done
