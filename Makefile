program:
	gcc main.c -o pwdShort
	# tmux split-window zsh -c "./pwdShort; echo; echo finished ; read"
