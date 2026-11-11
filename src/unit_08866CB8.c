/* unit_08866CB8: 0x08866CB8-0x08866DC8 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_089CBBE0;
extern s32 D_09A0B540;
extern int func_08812264(s32, s32);
extern int func_08898748(s32, s32);

void func_08866CB8(char *arg0) {
    func_08898748(D_09A0B540, 2);
    *(s32 *)(arg0 + 0x80230) = 0;
    *(s32 *)(arg0 + 0x80228) = 0;
    *(s32 *)(arg0 + 0x8022C) = 0;
    func_08812264(D_089CBBE0, 7);
    *(s32 *)(arg0 + 0x8023C) = 0;
    *(s32 *)(arg0 + 0x80234) = 0;
    *(s32 *)(arg0 + 0x80238) = 0;
}

void func_08866D40(char *arg0) {
    func_08898748(D_09A0B540, 3);
    *(s32 *)(arg0 + 0x80248) = 0;
    *(s32 *)(arg0 + 0x80240) = 0;
    *(s32 *)(arg0 + 0x80244) = 0;
    func_08812264(D_089CBBE0, 8);
    *(s32 *)(arg0 + 0x80254) = 0;
    *(s32 *)(arg0 + 0x8024C) = 0;
    *(s32 *)(arg0 + 0x80250) = 0;
}
