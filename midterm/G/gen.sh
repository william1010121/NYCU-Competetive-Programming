
for i in $(seq 3 3); do
    echo "Generating worst_$i.in"
    python3 ./generator/random_gen.py 100 0 0 0 0 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.in"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done


for i in $(seq 4 4); do
    echo "Generating worst_$i.in"
    python3 ./generator/random_gen.py 100 0 0 1 1000000000 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.in"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done

for i in $(seq 5 5); do
    echo "Generating worst_$i.in"
    python3 ./generator/random_gen.py 100 0 0 0 1 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.in"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done

for i in in $(seq 6 14); do
    echo "Generating worst_$i.in"
    python3 ./generator/random_gen.py 20 0 1000000000 0 1000000000 > ./data/secret/worst_"$i".in
    echo "Generating worst_$i.in"
    ./bin/AC < ./data/secret/worst_"$i".in > ./data/secret/worst_"$i".ans
    echo "Done $i"
done

for i in $(seq 15 20); do
    echo "Generating random_$i.in"
    python3 ./generator/random_gen.py 100000 0 1000000000 0 1000000000  > ./data/secret/random_"$i".in
    echo "Generating random_$i.in"
    ./bin/AC < ./data/secret/random_"$i".in > ./data/secret/random_"$i".ans
    echo "Done $i"
done
