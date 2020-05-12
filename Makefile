# .PHONY = clean

build: cdflib.wasm cdflib.wasm.base64.json

build-native: cdflib.out

clean:
	rm -f cdflib.wasm
	rm -f cdflib.js
	rm -f cdflib.out

cdflib.out:
	clang cdflib.c -o cdflib.out

cdflib.wasm:
	emcc -s "EXPORTED_FUNCTIONS=['_cdflib_cdftnc_power', '_cdflib_cdft_power']" \
	-s BINARYEN_ASYNC_COMPILATION=0 \
	-s EXTRA_EXPORTED_RUNTIME_METHODS="['writeArrayToMemory', 'stackAlloc', 'stackSave', 'stackRestore', 'getValue']" \
	-s DEFAULT_LIBRARY_FUNCS_TO_INCLUDE="[]" \
	-s TOTAL_MEMORY=2MB \
	-s TOTAL_STACK=1MB \
	-s NO_FILESYSTEM=1 \
	-s ENVIRONMENT='node' \
	-s NODEJS_CATCH_EXIT=0 \
	-s INVOKE_RUN=0 \
	-s DISABLE_EXCEPTION_CATCHING=1 \
	-s ASSERTIONS=0 \
	cdflib.c -o cdflib.js

cdflib.wasm.base64.json:
	node -p "JSON.stringify(fs.readFileSync('./a.out.wasm', 'base64'))" > cdflib.wasm.base64.json
