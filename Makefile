.PHONY: all build clean run

# The name of the final executable (must match CMakeLists.txt)
EXECUTABLE = http_from_scratch

# The build directory
BUILD_DIR = build

# Default target
all: run

build:
	@mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR)

run: build
	@./$(BUILD_DIR)/$(EXECUTABLE)

clean:
	@rm -rf $(BUILD_DIR)
