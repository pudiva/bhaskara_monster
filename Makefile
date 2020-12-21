.POSIX:
.PHONY: all clean
all: bhaskara_monster
clean:
	rm -f bhaskara_monster bhaskara_monster.o
bhaskara_monster: bhaskara_monster.o
