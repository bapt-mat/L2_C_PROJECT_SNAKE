TARGET=snake
MOD=mod_menu
MOD2=mod_jeu
MOD3=mod_plateau
MOD4=mod_save

########################################

CC=gcc
OPTIONS= -W -Wall -g -std=c89 -pedantic -O3 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
OPTION=`pkg-config --libs-only-l MLV`

########################################

$(TARGET) : $(TARGET).o $(MOD).o $(MOD2).o $(MOD3).o $(MOD4).o
	$(CC) $(OPTIONS) $(TARGET).o $(MOD).o $(MOD2).o $(MOD3).o $(MOD4).o $(OPTION) -o $(TARGET)
$(TARGET).o : $(TARGET).c
	$(CC) $(OPTIONS) -c $(TARGET).c
$(MOD).o : $(MOD).c $(MOD).h
	$(CC) $(OPTIONS) -c $(MOD).c
$(MOD2).o : $(MOD2).c $(MOD2).h
	$(CC) $(OPTIONS) -c $(MOD2).c
$(MOD3).o : $(MOD3).c $(MOD3).h
	$(CC) $(OPTIONS) -c $(MOD3).c
$(MOD4).o : $(MOD4).c $(MOD4).h
	$(CC) $(OPTIONS) -c $(MOD4).c
clean:
	rm -rf *.o *~ $(TARGET)

