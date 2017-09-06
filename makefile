MAIN_PROGRAM = compress-cmd
LIB_DIRS = huffman
TESTS = unittests

.PHONY: main_program $(MAIN_PROGRAM)
main_program : $(MAIN_PROGRAM)

.PHONY: lib_dirs $(LIB_DIRS)
lib_dirs: $(LIB_DIRS)

.PHONY: tests $(TESTS)
tests: $(TESTS)

$(MAIN_PROGRAM): $(LIB_DIRS)
	$(MAKE) $(MFLAGS) -C $@
	  
$(LIB_DIRS):
	$(MAKE) $(MFLAGS) -C $@

# TODO BUILD RULE FOR TESTS

# ONLY ONE LIB, SO BUILD DEPENDENCIES ARE NOT NECESSARY
# State build order for libs example:
# foo must be built after bar
# foo: bar

.PHONY: clean
clean :
	rm -rf $(LIB_DIRS)/bin
	rm -rf $(MAIN_PROGRAM)/bin
	rm -rf $(TESTS)/bin


