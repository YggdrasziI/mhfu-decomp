/* unit_08863668: 0x08863668-0x088637C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef float f32;

typedef struct Key {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Key;

typedef struct Track {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    Key keys[1];
} Track;

s16 func_08863668(void *arg0, Track *arg1, Key **arg2, Key **arg3, f32 arg4, s16 arg5) {
    Key *keys;
    Key *p;

    *arg2 = 0;
    *arg3 = 0;
    keys = arg1->keys;
    if (arg4 <= keys[0].unk2 || arg1->unk4 == 1) {
        *arg2 = keys;
        *arg3 = 0;
        return 0;
    }
    if (arg4 >= keys[arg1->unk4 - 1].unk2) {
        *arg2 = &keys[arg1->unk4 - 1];
        *arg3 = 0;
        return arg1->unk4 - 1;
    }
    if (arg5 < 0) {
        arg5 = 0;
    } else if (arg5 >= arg1->unk4) {
        arg5 = arg1->unk4 - 1;
    }
    p = &keys[arg5];
    while (1) {
        if (p->unk2 == arg4) {
            *arg2 = p;
            *arg3 = 0;
            return arg5;
        }
        if (p->unk2 < arg4 && arg4 < p[1].unk2) {
            *arg2 = p;
            *arg3 = p + 1;
            return arg5;
        }
        if (arg4 < p->unk2) {
            p--;
            arg5--;
        } else {
            p++;
            arg5++;
        }
    }
}
