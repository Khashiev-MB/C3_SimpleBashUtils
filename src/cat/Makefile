EXIT = cat
Opt = -Wall -Werror -Wextra

all: s21_$(EXIT)

s21_$(EXIT): clean
	gcc $(Opt) s21_$(EXIT).c -o s21_$(EXIT) -g -std=c11

clean:
	rm -rf *.out s21_$(EXIT)



style:
	clang-format -style=google -n *.c *.h

format:
	clang-format -style=google -i *.c *.h