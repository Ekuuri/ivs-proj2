BUILD_DIR = ../build
PACK_DIR = ../xlescet00_xjedliv01_xfurism00_xsrajed00
ZIPFILE = $(PACK_DIR).zip

all: $(BUILD_DIR)/Makefile
	$(MAKE) -C $(BUILD_DIR)
	
$(BUILD_DIR)/Makefile:
	mkdir -p $(BUILD_DIR)
	cmake -S .. -B $(BUILD_DIR)
	
clean:
	rm -rf $(BUILD_DIR) $(PACK_DIR)
	
check:
	echo "Checking for required project files..."
	for file in \
		../dokumentace.pdf \
		../screenshot.png \
		../skutecnost.txt \
		../hodnoceni.txt \
		../src/* \
		../mockup/* \
		../plan/* \
		../profiling/*; do \
		if [ ! -e $$file ]; then echo "*** Missing: $$file"; exit 1; fi; \
		done
	echo "All required files are present."

doc:
	doxygen Doxyfile
	
pack: check doc all
	echo "Creating package directory $(PACK_DIR)..."
	rm -rf $(PACK_DIR)
	git clone .. $(PACK_DIR)
	
	mkdir -p $(PACK_DIR)/documentation
	cp -r docs/html $(PACK_DIR)/documentation || true
	
	# todo: installers
	mkdir -p $(PACK_DIR)/installers
	
	echo "Zipping package into $(PACK_DIR)/$(ZIPFILE)..."
	cd $(PACK_DIR) && zip -r $(notdir $(ZIPFILE)) .
	cd $(PACK_DIR) && find . ! -name $(notdir $(ZIPFILE)) -delete
	echo "Package created: $(PACK_DIR)/$(ZIPFILE)"
	
	
test: all
	./$(BUILD_DIR)/src/mathlibTest
	
	
run: all
	./$(BUILD_DIR)/src/epicCalculator
	
.PHONY: all clean check doc pack test run
	

