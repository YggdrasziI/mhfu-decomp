/* unit_088C8760: 0x088C8760-0x088C88FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Anim {
    u16 flags;
    u16 u;
    u16 v;
} Anim;

extern s32 *D_089CC000;
extern void func_0886171C(char *, s32, char *, s32);

void func_088C8760(char *arg0, char *arg1, Anim *arg2, s32 arg3) {
    f32 su;
    f32 sv;

    if (arg2->u != 0) {
        su = (f32)(*(u16 *)(arg0 + 0x1C0) % arg2->u) / (f32)(u32)arg2->u;
        if (arg2->flags & 8) {
            su = 1.0f - su;
        }
        *D_089CC000 = (*(u32 *)&su >> 8) | 0x4A000000;
        D_089CC000++;
    }
    if (arg2->v != 0) {
        sv = (f32)(*(u16 *)(arg0 + 0x1C0) % arg2->v) / (f32)(u32)arg2->v;
        if (arg2->flags & 8) {
            sv = 1.0f - sv;
        }
        *D_089CC000 = (*(u32 *)&sv >> 8) | 0x4B000000;
        D_089CC000++;
    }
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    *D_089CC000 = 0x4A000000;
    D_089CC000++;
    *D_089CC000 = 0x4B000000;
    D_089CC000++;
}
