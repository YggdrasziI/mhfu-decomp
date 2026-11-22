/* unit_088860A0: 0x088860A0-0x08886124 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef short s16;

typedef struct {
    u16 unk0;
    u16 pad[11];
} Entry;

extern Entry D_0899D1A2[];

extern void func_08885E3C(char *arg0, s16 arg1);

void func_088860A0(char *arg0, u16 arg1) {
    switch (D_0899D1A2[arg1].unk0) {
    case 0:
        func_08885E3C(arg0, 0x18F6);
        break;
    case 2:
        func_08885E3C(arg0, 0x18F7);
        break;
    case 3:
        func_08885E3C(arg0, 0x18F8);
        break;
    }
}
