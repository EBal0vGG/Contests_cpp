CC=g++

all: build compile

build:
	@mkdir -p build

compile: build/num_A build/num_B
	@printf "Compilation is successful\n"

build/num_A: n_A/num_A.cpp
	@$(CC) n_A/num_A.cpp -o build/num_A

build/num_B: n_B/num_B.cpp
	@$(CC) n_B/num_B.cpp -o build/num_B

run_A: build/num_A
	@printf "Running num_A\n"
	@./build/num_A

run_B: build/num_B
	@printf "Running num_B\n"
	@./build/num_B

clean:
	@printf "Cleaning successful\n"
	@rm -rf build

.PHONY: compile run_A run_B clean