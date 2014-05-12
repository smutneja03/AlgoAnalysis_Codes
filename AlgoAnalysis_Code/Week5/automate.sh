
gcc -g -o change-dp change-dp.c
gcc -g -o change-greedy change-greedy.c

>log_dp.txt

>log_greedy.txt

for (( i=1; i<=100;i+=1 ))
	do
		var=$(($RANDOM % 1500 + 1))
    	./change-dp denom.txt $var
    	./change-greedy denom.txt $var                   
  	done
