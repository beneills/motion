# From http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/

CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity

SRCDIR := src
BUILDDIR := build
TARGET := bin/motion

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -std=c++11
LIB := -lSDL2 -lSDL2_gfx
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(filter-out src/main.cpp, $(SOURCES)) $(INC) $(LIB) -o bin/tester

.PHONY: clean
