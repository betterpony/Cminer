
#include <windows.h>
#include "logger.h"
#include "ecc.h"



int main()
{
	//int i = 0;
	//while (true)
	//{
	//	i++;


	//	printf("hello world ....0x%x\n",i);
	//	sleep(100);
	//}

    uint8_t public_key[ECC_BYTES * 2];
    uint8_t private_key[ECC_BYTES];
    uint8_t hash[ECC_BYTES] = { 0x2 };
    uint8_t signature[ECC_BYTES * 2];
    int ret = 0;
    uint32_t i = 0;

    ret = ecc_make_key(public_key, private_key);
    if (ret == 0) {
        printf("ecc_make_key failure\n");
    }

    printf("##############public key###############\n0x");
    for (i = 0; i < ECC_BYTES * 2; i++) {
        printf("%02x", public_key[i]);
    }

    printf("\n");
    printf("##############private key###############\n0x");
    for (i = 0; i < ECC_BYTES; i++) {
        printf("%02x",private_key[i]);
    }
    printf("\n");

    ret = ecdsa_sign(private_key, hash, signature);
    if (ret == 0) {
        printf("ecdsa_sign failure\n");
    }
    
    //    hash[0] = 0x3;
    ret = ecdsa_verify(public_key, hash, signature);
    if (ret == 1) {
        printf("verify passed\n");
    }
    else {
        printf("verify failed\n");
    }

    return 0;

	system("pause");
}











