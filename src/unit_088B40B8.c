/* unit_088B40B8: 0x088B40B8-0x088B4120 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern void func_088B4120(void *);
extern s32 func_088B4184(s32);
extern void func_088B41B4(void *);

void func_088B40B8(char *arg0) {
    u8 temp_a1;

    temp_a1 = *(u8 *)(arg0 + 0x22);
    switch (temp_a1) {                              /* irregular */
    case 0:
        func_088B4120(arg0);
        return;
    case 1:
        func_088B4184((s32) arg0);
        return;
    case 2:
        func_088B41B4(arg0);
        return;
    }
}
