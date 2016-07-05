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
cat psout | ./checker -v $ARGS
wc -l psout
