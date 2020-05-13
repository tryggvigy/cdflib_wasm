build: test.out cdflib.wasm cdflib.wasm.base64.json cdflibStandalone.js

build-test: test.out

clean:
	rm -f cdflib.out
	rm -f cdflib.js
	rm -f cdflib.wasm
	rm -f cdflib.wasm.base64.json
	rm -f test/test.out
	rm -f cdflibStandalone.js

test.out:
	clang test/test.c cdflib.c -o test/test.out

cdflib.wasm:
	emcc -s "EXPORTED_FUNCTIONS=[ \
		'_cdflib_algdiv','_cdflib_alngam', '_cdflib_alnrel', '_cdflib_apser', '_cdflib_basym', \
		'_cdflib_cdft_1', '_cdflib_cdft_2', '_cdflib_cdft_3', \
		'_cdflib_cdftnc_1', '_cdflib_cdftnc_2', '_cdflib_cdftnc_3', '_cdflib_cdftnc_4']" \
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
