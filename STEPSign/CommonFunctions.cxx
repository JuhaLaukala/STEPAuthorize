#include "CommonFunctions.h"

void initialize()
{
	OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CONFIG, NULL);
	if (CONF_modules_load_file(NULL, NULL, 0) <= 0) {
		ERR_print_errors_fp(stderr);
		exit(EXIT_FAILURE);
	}

	// Load the configuration file
	if (CONF_modules_load_file(NULL, NULL, 0) <= 0) {
		ERR_print_errors_fp(stderr);
		exit(EXIT_FAILURE);
	}

	OpenSSL_add_all_digests();
	OpenSSL_add_all_algorithms();
	ERR_load_crypto_strings();
}

void clean_up()
{
	ERR_clear_error();
	ERR_free_strings();

	EVP_cleanup();

	CONF_modules_finish();
	CONF_modules_free();
	CONF_modules_unload(1);

	CRYPTO_cleanup_all_ex_data();
}