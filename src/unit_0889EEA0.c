/* unit_0889EEA0: 0x0889EEA0-0x0889EF04 (ULES01213) */

typedef int s32;
typedef unsigned int u32;

typedef struct {
    char *name;
    s32 init;
    s32 max;
    s32 id;
} SemaEntry;

extern s32 sceKernelCreateSema(char *, s32, s32, s32, s32);
extern SemaEntry D_089B1FF0[];

void func_0889EEA0(void) {
    u32 i;
    SemaEntry *p;

    for (i = 0, p = D_089B1FF0; i < 11; i++, p++) {
        if (p->name != 0) {
            p->id = sceKernelCreateSema(p->name, 0x100, p->init, p->max, 0);
        }
    }
}
