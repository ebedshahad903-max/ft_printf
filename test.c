// #include <stdio.h>
// #include <limits.h>
// #include "ft_printf.h"



// #include <stdio.h>
// #include "ft_printf.h"

// int main(void)
// {
//     int x = 42;
//     int ret_org;
//     int ret_ft;

//     /* TEST 10: Pointer */
//     printf("\n===== TEST: Pointer =====\n");

//     printf("Expected: \"Ptr: ");
//     ret_org = printf("%p", &x);
//     printf("\" (ret = %d)\n", ret_org);

//     printf("Actual:   \"Ptr: ");
//     ret_ft = ft_printf("%p", &x);
//     printf("\" (ret = %d)\n", ret_ft);

//     if (ret_org == ret_ft)
//         printf("RESULT: PASS\n");
//     else
//         printf("RESULT: FAIL\n");

//     /* TEST 11: NULL pointer */
//     printf("\n===== TEST: NULL Pointer =====\n");

//     printf("Expected: \"Ptr: ");
//     ret_org = printf("%p", (void *)NULL);
//     printf("\" (ret = %d)\n", ret_org);

//     printf("Actual:   \"Ptr: ");
//     ret_ft = ft_printf("%p", (void *)NULL);
//     printf("\" (ret = %d)\n", ret_ft);

//     if (ret_org == ret_ft)
//         printf("RESULT: PASS\n");
//     else
//         printf("RESULT: FAIL\n");

//     return 0;
// }
