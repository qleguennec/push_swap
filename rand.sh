if [[ "$OSTYPE" = "Linux" ]]; then
	shuf -i 0-1000000000 -n $1 | tr '\n' ' '
else
	od -vAn -N "$(( $1 * 4 ))" -t d < /dev/urandom
fi
