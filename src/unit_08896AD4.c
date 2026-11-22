/* unit_08896AD4: 0x08896AD4-0x08896C10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC438;
extern u8 func_0884FB38(char *, s32);
extern void func_0884FAC4(char *, s32);

s32 func_08896AD4(char *arg0) {
    switch (*(signed char *)(arg0 + 0x1111)) {
    case 1:
        if (func_0884FB38(D_089CC438, 0x66) == 1) {
            break;
        }
        func_0884FAC4(D_089CC438, 0x66);
        *(u8 *)(arg0 + 0x1113) = 2;
        return 1;
    case 7:
        if (func_0884FB38(D_089CC438, 0x87) == 1) {
            break;
        }
        func_0884FAC4(D_089CC438, 0x87);
        func_0884FAC4(D_089CC438, 0x88);
        func_0884FAC4(D_089CC438, 0x89);
        func_0884FAC4(D_089CC438, 0x8A);
        func_0884FAC4(D_089CC438, 0x8B);
        func_0884FAC4(D_089CC438, 0x8C);
        func_0884FAC4(D_089CC438, 0x8D);
        func_0884FAC4(D_089CC438, 0x8E);
        func_0884FAC4(D_089CC438, 0x8F);
        *(u8 *)(arg0 + 0x1113) = 1;
        return 1;
    }
    return 0;
}
