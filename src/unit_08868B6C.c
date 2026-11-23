/* unit_08868B6C: 0x08868B6C-0x08868C04 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08868B6C: drives the on-screen keyboard utility state. */

typedef unsigned char u8;
typedef int s32;

extern s32 sceUtilityOskGetStatus(void);
extern s32 sceUtilityOskUpdate(s32);
extern s32 sceUtilityOskShutdownStart(void);
extern void func_08868E54(char *);

void func_08868B6C(char *arg0) {
    if (*(u8 *)(arg0 + 0x74) != 0) {
        switch (sceUtilityOskGetStatus()) {
        case 1:
            break;
        case 2:
            sceUtilityOskUpdate(2);
            break;
        case 3:
            sceUtilityOskShutdownStart();
            break;
        case 4:
            break;
        case 0:
            func_08868E54(arg0);
            break;
        }
    }
}
