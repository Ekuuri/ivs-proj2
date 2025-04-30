# ******************************************************************
# Project name: IVS 2 project
# Date: 17.4.2025
# Last change: 24.4.2025
# Team: audentes Fortuna iuvat
# Author: Tobias Leščenko
# ******************************************************************

BUILD_DIR = ../build
PACK_DIR = ../xlescet00_xjedliv01_xfurism00_xsrajed00
ZIPFILE = $(PACK_DIR).zip

all: $(BUILD_DIR)/Makefile
	$(MAKE) -C $(BUILD_DIR)
#cmake --install $(BUILD_DIR) --component epicCalc
	
$(BUILD_DIR)/Makefile:
	mkdir -p $(BUILD_DIR)
	cmake -S .. -B $(BUILD_DIR)
	
clean:
	rm -rf $(BUILD_DIR) $(PACK_DIR) doxygen

doc:
	doxygen Doxyfile
	
pack: doc all
	echo "Creating package directory $(PACK_DIR)..."
	rm -fr $(PACK_DIR)
	mkdir -p $(PACK_DIR)/repo
	git clone .. $(PACK_DIR)/repo
	
	mkdir -p $(PACK_DIR)/doc
	cp -fr doxygen/* $(PACK_DIR)/doc
	
	mkdir -p $(PACK_DIR)/install
	cmake -G "Unix Makefiles" -S .. -B $(PACK_DIR)/install
	cd $(PACK_DIR)/install && cmake --build . --target package
	cd $(PACK_DIR)/install && mv *.deb ..
	rm -fr $(PACK_DIR)/install
	mkdir -p $(PACK_DIR)/install
	cd $(PACK_DIR) && mv *.deb install/

	echo "Zipping package into $(PACK_DIR)/$(ZIPFILE)..."
	cd $(PACK_DIR) && zip -r $(notdir $(ZIPFILE)) .
	cd $(PACK_DIR) && find . ! -name $(notdir $(ZIPFILE)) -delete
	echo "Package created: $(PACK_DIR)/$(ZIPFILE)"
	
test: all
	./$(BUILD_DIR)/src/mathlibTest
	
	
run: all
	./$(BUILD_DIR)/src/epicCalculator

stddev: $(BUILD_DIR)/Makefile
	cmake --build $(BUILD_DIR) --target stddev
#cmake --install $(BUILD_DIR) --component stddev
	
.PHONY: all clean doc pack test run stddev
	

