PROJECT_NAME = MallManagement
TEST_PROJECT_NAME = MallManagement_Test

BUILD_DIR = Build

SRC =src/check_user_option.cxx\
src/display_menu.cxx\
src/generate_file_map.cxx\
src/generate_price_map.cxx\
src/calculate_price.cxx\
src/calculate_final_price.cxx\
src/read_log_file.cxx\
src/check_membership.cxx\
src/displaybill.cxx\

INC_H = inc

TEST = integrated_test.cxx
# for makefile to run in both windows and linux build
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

.PHONY : all test coverage run clean doc

all:$(BUILD_DIR)
	g++ integrated_main.cc -I $(INC_H) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC)) -lm -std=c++11
# to run the project
run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
# to make the build documentation
doc:
	make -C doc
$(BUILD_DIR):
	mkdir $(BUILD_DIR)
# for unit testing
test:
	g++ integrated_test.cxx -I $(INC_H) $(SRC) -lgtest -lgtest_main -lpthread -o $(call FixPath,$(TEST_PROJECT_NAME).$(EXEC)) -lm
	./$(call FixPath,$(TEST_PROJECT_NAME).$(EXEC))

Cppcheck:
	cppcheck --enable=all .

# for valgrind testing
valgrind:
	valgrind --leak-check=full ./$(TEST_PROJECT_NAME).$(EXEC)
	
coverage:
	g++ -fprofile-arcs -ftest-coverage $(TEST) -I $(INC_H) $(SRC) -lgtest -lgtest_main -lpthread -lm -o $(call FixPath, $(TEST_PROJECT_NAME).$(EXEC))
	$(call FixPath, ./$(TEST_PROJECT_NAME).$(EXEC))
	gcov -a $(TEST)
	
clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	make clean -C doc
	rmdir $(BUILD_DIR) doc/html
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)
