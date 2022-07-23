
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

    //uint8_t public_key[ECC_BYTES * 2];
    //uint8_t private_key[ECC_BYTES];
    //uint8_t hash[ECC_BYTES] = { 0x2 };
    //uint8_t signature[ECC_BYTES * 2];
    //int ret = 0;
    //uint32_t i = 0;

    //ret = ecc_make_key(public_key, private_key);
    //if (ret == 0) {
    //    printf("ecc_make_key failure\n");
    //}

    uint64_t res[4];
    uint64_t tttt[8] = { 
           0xfcde333333456232, 0x2FFFFFFFFFFF5aaa, 0x1f678f3bc76af292, 0x45321123312cbda3,
           0x4589654552145668, 0x2234adbce334554c, 0x1f678f4dfff1fadc, 0x453211233bbce123
    };
    uint64_t pcurve[4] = { 0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff };



    uint64_t product[8];
    for (int i = 0; i < 8; i++)
    {
        product[i] = tttt[7 - i];
    }

    vli_mmod_fast(res,product);

    printf("0x");
    for (int i = 0; i < 4; i++)
    {
        printf("%llx ", res[3 - i]);
    }
    printf("\n");
  
    //*****************************************************************
    uint64_t yyyy[4] = { 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFF985 };
    uint64_t input_t[4];
    for (int i = 0; i < 4; i++)
    {
        input_t[i] = yyyy[3 - i];
    }

    vli_modInv(res, input_t, pcurve);

    printf("0x");
    for (int i = 0; i < 4; i++)
    {
        printf("%llx ", res[3 - i]);
    }
    printf("\n");




	system("pause");
}











