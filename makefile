MAIN_PROGRAM = compress-cmd
LIB_DIRS = huffman
TESTS = unittests/huffman

# Declare as phony targers since dirs always exist
.PHONY: $(MAIN_PROGRAM)
.PHONY: $(LIB_DIRS)
.PHONY: $(TESTS)

all: $(MAIN_PROGRAM) $(TESTS)

$(MAIN_PROGRAM): $(LIB_DIRS)
	$(MAKE) $(MFLAGS) -C $@

$(LIB_DIRS):
	$(MAKE) $(MFLAGS) -C $@

$(TESTS):
	$(MAKE) $(MFLAGS) -C $@

# TODO BUILD RULE FOR TESTS

# ONLY ONE LIB, SO BUILD DEPENDENCIES ARE NOT NECESSARY
# State build order for libs example:
# foo must be built after bar
# foo: bar
$(TESTS): $(LIB_DIRS)

.PHONY: clean
clean :
	rm -rf $(LIB_DIRS)/bin
	rm -rf $(MAIN_PROGRAM)/bin
	rm -rf $(TESTS)/bin


