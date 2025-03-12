i=0
g++ -std=c++17 code.cpp -o run
g++ -std=c++17 brute.cpp -o brute
while true;
do
    i=$(($i+1))
    python3 gen.py > input.txt
    ./run < input.txt > output.txt
    ./brute < input.txt > brute.txt
    echo $i
    diff output.txt brute.txt
    if [ $? -ne 0 ];then
        break
    fi
done
