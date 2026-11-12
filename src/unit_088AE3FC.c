/* unit_088AE3FC: 0x088AE3FC-0x088AE464 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern void func_088AE464(void *);
extern s32 func_088AE4A0(s32);
extern void func_088AE4EC(void *);

void func_088AE3FC(char *arg0) {
    u8 temp_a1;

    temp_a1 = *(u8 *)(arg0 + 0x22);
    switch (temp_a1) {                              /* irregular */
    case 0:
        func_088AE464(arg0);
        return;
    case 1:
        func_088AE4A0((s32) arg0);
        return;
    case 2:
        func_088AE4EC(arg0);
        return;
    }
}
