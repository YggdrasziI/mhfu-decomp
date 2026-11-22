/* unit_08870264: 0x08870264-0x088702F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 flags;
    u16 id;
    u16 pad;
} Slot;

s32 func_08870264(char *arg0, u16 arg1) {
    Slot *s;
    s32 i;

    s = (Slot *)(arg0 + 0x728);
    for (i = 0; i < 2; i++, s++) {
        if ((s->flags & 0x11) == 0x11 || (s->flags & 0x14) == 0x14) {
            if (s->id == arg1) {
                switch (*(u8 *)(arg0 + 0x67C)) {
                case 1:
                    if (i == 0) {
                        return 1;
                    }
                    break;
                case 2:
                    return 1;
                }
            }
        }
    }
    return 0;
}
