BUILD_DIR = ../build

all: $(BUILD_DIR)/Makefile
	$(MAKE) -C $(BUILD_DIR)
	
$(BUILD_DIR)/Makefile:
	mkdir -p $(BUILD_DIR)
	cmake -S .. -B $(BUILD_DIR)
	
clean:
	rm -rf $(BUILD_DIR)
	
test: all
	./$(BUILD_DIR)/src/mathlibTest
	
	
run: all
	./$(BUILD_DIR)/src/epicCalculator
	
.PHONY: all clean run
	

