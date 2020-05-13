build: cdflib.wasm cdflib.wasm.base64.json cdflibStandalone.js

build-native: cdflib.out

build-test: test.out

clean:
	rm -f cdflib.out
	rm -f cdflib.js
	rm -f cdflib.wasm
	rm -f cdflib.wasm.base64.json
	rm -f test/test.out
	rm -f cdflibStandalone.js

cdflib.out:
	clang cdflib.c -o cdflib.out

cdflib.wasm:
	emcc -s "EXPORTED_FUNCTIONS=[ \
		'_algdiv', '_cdft_1', '_cdft_2', '_cdft_3', '_cdftnc_1', '_cdftnc_2', '_cdftnc_3', '_cdftnc_4']" \
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
	cdflib.c cdflib_wrapper.c -o cdflib.js

cdflib.wasm.base64.json cdflibStandalone.js:
	node generateFiles.js

test.out:
	clang test/test.c cdflib.c -o test/test.out
