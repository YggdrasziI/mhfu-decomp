/* unit_088738D4: 0x088738D4-0x08873980 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad0[0x828];
    s32 ids[20];
    u16 counts[20];
    u32 total;
} Obj;

void func_088738D4(Obj *arg0, s32 arg1) {
    s32 i;
    s32 j;

    if (arg0->total < 300) {
        for (i = 0; i < 20; i++) {
            if (arg0->ids[i] == arg1) {
                arg0->counts[i]++;
                arg0->total++;
                return;
            }
        }
        for (j = 0; j < 20; j++) {
            if (arg0->ids[j] == 0) {
                arg0->ids[j] = arg1;
                arg0->counts[j]++;
                arg0->total++;
                return;
            }
        }
    }
}
