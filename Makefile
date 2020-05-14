build: test.out cdflib.wasm cdflib.wasm.base64.json cdflibStandalone.js

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
		'_cdflib_bcorr', '_cdflib_betaln', '_cdflib_bfrac', '_cdflib_bgrat', '_cdflib_bpser', \
		'_cdflib_bratio', '_cdflib_brcmp1', '_cdflib_brcomp', '_cdflib_bup', '_cdflib_cdfbet_1', \
		'_cdflib_cdfbet_2', '_cdflib_cdfbet_3', '_cdflib_cdfbet_4', '_cdflib_cdfbin_1', \
		'_cdflib_cdfbin_2', '_cdflib_cdfbin_3', '_cdflib_cdfbin_4', '_cdflib_cdfchi_1', \
		'_cdflib_cdfchi_2', '_cdflib_cdfchi_3', '_cdflib_cdfchn_1', '_cdflib_cdfchn_2', \
		'_cdflib_cdfchn_3', '_cdflib_cdfchn_4', '_cdflib_cdff_1', '_cdflib_cdff_2', \
		'_cdflib_cdff_3', '_cdflib_cdff_4', '_cdflib_cdffnc_1', '_cdflib_cdffnc_2', \
		'_cdflib_cdffnc_3', '_cdflib_cdffnc_4', '_cdflib_cdffnc_5', \
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
