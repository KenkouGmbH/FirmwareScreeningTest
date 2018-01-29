TARGET=kenkou_keyboard_monitor.out

CC=gcc
LINKER=gcc

IDIR=include
BDIR=bin
ODIR=obj
SDIR=src

$(shell   mkdir -p $(ODIR))
$(shell   mkdir -p $(BDIR))

CFLAGS= -Wall -I$(IDIR)
LFLAGS= -Wall -I$(IDIR) -lm -lncurses
SOURCES := $(wildcard $(SDIR)/*.c)
OBJECTS := $(SOURCES:$(SDIR)/%.c=$(ODIR)/%.o)

$(BDIR)/$(TARGET): $(OBJECTS)
	$(LINKER) $(OBJECTS) -o $@ $(LFLAGS)
	@echo "Linking complete!"

$(OBJECTS): $(ODIR)/%.o : $(SDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS) 
	@echo Compiled "$<"

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


.PHONY: clean
clean:
	@echo "bin and obj directories are being deleted."
	@rm -rf $(ODIR) $(BDIR)
	@echo "Cleanup complete!"
