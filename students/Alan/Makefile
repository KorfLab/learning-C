# Definitions

CFLAGS = -Wall -Werror
OBJECTS = biosequence.o

APP = demo
OBJ = demo.o

# Targets

default:
	make $(APP)

$(APP): $(OBJ) $(OBJECTS)
	$(CC) -o $(APP) $(OBJ) $(OBJECTS)

clean:
	rm -f *.o $(APP)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


