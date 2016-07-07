if [ $# -eq 1 ]; then
	ARGS=$(cat $1)
else
	if [ $# -eq 2 ]; then
		ARGS=$(sh rand.sh $2 > psin && cat psin)
	else
		exit 1
	fi
fi

set -e
make
time ./push_swap $ARGS > psout
if [ -n "$DEBUG" ]; then
	cat psout | ./checker -v $ARGS
else
	cat psout | ./checker $ARGS
fi
wc -l psout
