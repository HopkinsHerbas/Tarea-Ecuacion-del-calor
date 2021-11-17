FLAGS0 = -O0
FLAGS2 = -O2
FLAGS3 = -O3

OBJECTS1 = heatExp.c tools.c
OBJECTS2 = heatimplicito.c tools.c

BIN1 = heatEx
BIN2 = heatIm
BIN3 = debug

all: $(BIN1)

heatEx: $(OBJECTS1)
	gcc -o $(BIN1) $(FLAGS3) $(OBJECTS1) -lm   #Habia error en el linking por no conseguir libreria matematica

heatIm: $(OBJECTS2)
	gcc -o $(BIN2) $(FLAGS3) $(OBJECTS2) -lm   #Habia error en el linking por no conseguir libreria matematica
	
debug: $(OBJECTS1)
	gcc -g -o $(BIN3) $(FLAGS0) $(OBJECTS1) -lm   #Habia error en el linking por no conseguir libreria matematica

#### falto la regla de clean
clean:
	rm -f *.o $(BIN1) $(BIN2) $(BIN3)
### no sé q escribir xdn't