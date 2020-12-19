.POSIX:
.PHONY: all clean
bhaskara_monster: bhaskara_monster.o
clean:
	rm -f bhaskara_monster bhaskara_monster.o
all: bhaskara_monster
