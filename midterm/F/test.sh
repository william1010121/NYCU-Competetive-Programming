judgeExecutable=$1
timeLimitCnt=0
wrongAnswerCnt=0
acceptedCnt=0
for i in ./data/secret/*.in; do
    #echo "Running for $i"
    # time limit in 1s
    # ans is ./data/secret/*.ans
    #rm -f tmp.ans
    timeout 1.5s $judgeExecutable < $i > tmp.ans
    #time $judgeExecutable < $i > tmp.ans
    if [ $? -ne 0 ]; then
        timeLimitCnt=$((timeLimitCnt + 1))
        echo "Time limit exceeded for $i"
        continue
    fi
    diff -q tmp.ans ./data/secret/$(basename $i .in).ans
    if [ $? -ne 0 ]; then
        wrongAnswerCnt=$((wrongAnswerCnt + 1))
        echo "Wrong answer for $i"
        continue
    fi
    acceptedCnt=$((acceptedCnt + 1))
done
echo "Accepted: $acceptedCnt"
echo "Wrong Answer: $wrongAnswerCnt"
echo "Time Limit Exceeded: $timeLimitCnt"
