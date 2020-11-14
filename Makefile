prebuild: 
	mkdir build

build: test.out cdflib.wasm cdflib.wasm.base64.json cdflibStandalone.js

clean:
	rm -rf build
	rm -f test/test.out

test.out:
	clang test/test.c cdflib/*.c -o test/test.out

cdflib.wasm:
	emcc -s "EXPORTED_FUNCTIONS=[ \
		'_cdflib_cdfbet_1', '_cdflib_cdfbet_2', '_cdflib_cdfbet_3', '_cdflib_cdfbet_4', \
		'_cdflib_cdfbin_1', '_cdflib_cdfbin_2', '_cdflib_cdfbin_3', '_cdflib_cdfbin_4', \
		'_cdflib_cdfchi_1', '_cdflib_cdfchi_2', '_cdflib_cdfchi_3', \
		'_cdflib_cdfchn_1', '_cdflib_cdfchn_2', '_cdflib_cdfchn_3', '_cdflib_cdfchn_4', \
		'_cdflib_cdff_1', '_cdflib_cdff_2', '_cdflib_cdff_3', '_cdflib_cdff_4', \
		'_cdflib_cdffnc_1', '_cdflib_cdffnc_2', '_cdflib_cdffnc_3', '_cdflib_cdffnc_4', '_cdflib_cdffnc_5', \
		'_cdflib_cdfgam_1', '_cdflib_cdfgam_2', '_cdflib_cdfgam_3', '_cdflib_cdfgam_4', \
		'_cdflib_cdfnbn_1', '_cdflib_cdfnbn_2', '_cdflib_cdfnbn_3', '_cdflib_cdfnbn_4', \
		'_cdflib_cdfnor_1', '_cdflib_cdfnor_2', '_cdflib_cdfnor_3', '_cdflib_cdfnor_4', \
		'_cdflib_cdfpoi_1', '_cdflib_cdfpoi_2', '_cdflib_cdfpoi_3', \
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
	--js-library c-defs.js \
	cdflib/*.c cdflib_wrapper.c -o build/cdflib.js

cdflib.wasm.base64.json cdflibStandalone.js:
	node generateFiles.js
