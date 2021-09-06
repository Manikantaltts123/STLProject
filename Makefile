PROJECT_NAME = MallManagement
TEST_PROJECT_NAME = MallManagement_Test

BUILD_DIR = Build

SRC = src/read_from_csv.cc\
src/add_items_to_cart.cc\
src/display_shop_details.cc\
src/print_all_csv_details.cc\
src/generate_new_bill.cc\
src/generate_extras.cc\
src/class_function_declaration.cc\
src/remove_items_cart.cc\
src/ShoppiBuddyMain.cc\
src/check_user_option.cxx\
src/display_menu.cxx\
src/generate_file_map.cxx\
src/generate_price_map.cxx\
src/calculate_price.cxx\
src/calculate_final_price.cxx\
src/read_log_file.cxx\
src/check_membership.cxx\
src/displaybill.cxx\
src/cubeeaterymain.cxx\
src/game_main.cpp\
src/game_zone.cpp\
src/shop_adder.cc\
src/functionality.cc\
src/mall_navi_menu.cc\
src/theatre_functions.cc\
src/theatre_main.cc\

INC_H = inc

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
	
clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	make clean -C doc
	rmdir $(BUILD_DIR) doc/html
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)
