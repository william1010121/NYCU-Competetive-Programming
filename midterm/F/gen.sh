#!/usr/bin/env sh

for i in $(seq 3 4); do
    echo "Generating worst_$i.in"
    python3 ./generator/worst.py 100000 1 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.ans"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done

for i in $(seq 5 6); do
    echo "Generating worst_$i.in"
    python3 ./generator/worst.py 100000 2 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.ans"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done

for i in $(seq 7 7); do
    echo "Generating worst_$i.in"
    python3 ./generator/worst.py 100000 3 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.ans"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done

for i in $(seq 8 8 ); do
    echo "Generating worst_$i.in"
    python3 ./generator/worst.py 100000 4 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.ans"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done


for i in $(seq 9 10); do
    echo "Generating worst_$i.in"
    python3 ./generator/worst.py 100000 5 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.ans"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done

for i in $(seq 11 15); do
    echo "Generating random_$i.in"
    python3 ./generator/random_gen.py 100000 100000 1 1000000000  > ./data/secret/random_"$i".in
    echo "Generating random_$i.ans"
    ./bin/AC < ./data/secret/random_"$i".in > ./data/secret/random_"$i".ans
    echo "Done $i"
done

for i in $(seq 16 20); do
    echo "Generating random_$i.in"
    python3 ./generator/random_gen.py 100000 100000 0 1000000000  > ./data/secret/random_"$i".in
    echo "Generating random_$i.in"
    ./bin/AC < ./data/secret/random_"$i".in > ./data/secret/random_"$i".ans
    echo "Done $i"
done
