/* unit_0889BE7C: 0x0889BE7C-0x0889BEC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

/* func_0889BE7C: copies a 0x14-byte record to the stack and sets bit 0x40
 * of the word at 0x12C4 of the object named by its third word. */

#pragma optimize_for_size off

typedef int s32;

typedef struct {
    float f0;
    float f4;
    char *obj;
    float fC;
    float f10;
} Rec;

void func_0889BE7C(Rec *arg0) {
    Rec r;

    r = *arg0;
    *(s32 *)(r.obj + 0x12C4) |= 0x40;
}
