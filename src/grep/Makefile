EXIT = grep
Opt = -Wall -Werror -Wextra -g -std=c11

all: s21_$(EXIT)

s21_$(EXIT): clean
	gcc $(Opt) s21_$(EXIT).c -o s21_$(EXIT)

clean:
	rm -rf *.out s21_$(EXIT)


style:
	clang-format -style=google -n *.c *.h

format:
	clang-format -style=google -i *.c *.h
