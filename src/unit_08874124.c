/* unit_08874124: 0x08874124-0x08874190 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    u16 unk2;
    u16 key;
} Entry;

extern Entry D_089A8624[];
extern char *D_089CC438;
extern s32 func_0884FB38(char *, s32);

s32 func_08874124(s32 arg0, s32 arg1) {
    Entry *p = D_089A8624;
    s32 i = 0;

    do {
        if (p->key == arg1) {
            arg1 = p->id;
            if (arg1 != 0x164) {
                switch (func_0884FB38(D_089CC438, arg1)) {
                case 0:
                    return 0;
                }
            }
            return 1;
        }
        i++;
        p++;
    } while (i < 0x26);
    return 1;
}
