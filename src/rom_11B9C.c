#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"

void sub_11C14(s16);
void sub_12524(void);
void sub_12BF8(void);
void sub_2AADC(void);

void sub_11B9C(void)
{
    s16 i;
    if (gMain.unk6 == 0)
    {
        gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
        sub_11C14(0);
        sub_12524();
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[i];
            sub_11C14(i);
        }
        sub_12BF8();
    }
}

void sub_11C14(s16 arg0)
{
    struct UnkPinballGame1334 *var0 = &gCurrentPinballGame->unk1334[arg0];
    var0->unk10.x = gUnknown_02031520.unk26;
    var0->unk10.y = gUnknown_02031520.unk28;
    var0->position.x = Q_24_8(var0->unk10.x);
    var0->position.y = Q_24_8(var0->unk10.y);
    var0->unk28.x = gUnknown_02031520.unk26 * 2;
    var0->unk28.y = gUnknown_02031520.unk28 * 2;
    var0->unkE = 0x100;
    var0->velocity.x = 0;
    var0->velocity.y = 0;
    if (gMain.selectedField == FIELD_RUBY)
        var0->unk1 = 3; 
    else
        var0->unk1 = 1;

    var0->unk6 = 0;
    gCurrentPinballGame->unk5B2 = 1;
}

extern const u16 gGravityDeltas_Strong[4];
extern const u16 gGravityDeltas_Medium[4];
extern const u16 gGravityDeltas_Light[4];


// Before updating the ball's position, cap the ball's velocity
// vector to a maximum speed.
#define UPDATE_BALL_POSITION(max_speed, angle)           \
{                                                        \
    maxSpeed = (max_speed);                              \
    if (squaredMagnitude > maxSpeed * maxSpeed)          \
    {                                                    \
        velocity.x =  (maxSpeed * Cos((angle))) / 20000; \
        velocity.y = (-maxSpeed * Sin((angle))) / 20000; \
    }                                                    \
    else                                                 \
    {                                                    \
        velocity.x = unk132c->velocity.x;                \
        velocity.y = unk132c->velocity.y;                \
    }                                                    \
    unk132c->position.x += velocity.x;                   \
    unk132c->position.y += velocity.y;                   \
}

void sub_11C98(void)
{
    struct Vector16 velocity;
    struct UnkPinballGame1334 *unk132c;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->unk132c;
    unk132c->prevPosition = unk132c->position;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;

            if (!gCurrentPinballGame->unk1F)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (unk132c->velocity.y > 160)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 80)
                    unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
                else
                    unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
            }

            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;
            
            if (unk132c->unk10.y < 380)
            {
                UPDATE_BALL_POSITION(272, angle);
            }
            else
            {
                UPDATE_BALL_POSITION(400, angle);
            }
        }
        else
        {
            u16 angle;

            if (!gCurrentPinballGame->unk1F)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (unk132c->velocity.y > 200)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 100)
                    unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
                else
                    unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
            }

            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;
            
            if (unk132c->unk10.y < 380)
            {
                UPDATE_BALL_POSITION(336, angle);
            }
            else
            {
                UPDATE_BALL_POSITION(400, angle);
            }
        }
    }
    else
    {
        sub_2AADC();
    }

    unk132c->unk2C = unk132c->unk28;
    unk132c->unk28.x = (unk132c->position.x + 64) / 128;
    unk132c->unk28.y = (unk132c->position.y + 64) / 128;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}

void sub_11F88(void)
{
    struct Vector16 velocity;
    struct UnkPinballGame1334 *unk132c;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->unk132c;
    unk132c->prevPosition = unk132c->position;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        if (!gCurrentPinballGame->unk1F && !gCurrentPinballGame->unk383)
        {
            // Gravity is applied at different strengths, depending on fast the ball is
            // currently moving downwards.
            if (unk132c->velocity.y > 150)
                unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
            else if (unk132c->velocity.y > 75)
                unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
            else
                unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;
            
            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (unk132c->unk10.y < 150)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else if (gMain.selectedField == FIELD_SPHEAL)
            {
                if (unk132c->unk10.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else
            {
                if (unk132c->unk10.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
        }
        else
        {
            u16 angle;
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (unk132c->unk10.y < 150)
                {
                    UPDATE_BALL_POSITION(304, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else if (gMain.selectedField == FIELD_SPHEAL)
            {
                if (unk132c->unk10.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else
            {
                if (unk132c->unk10.y < 218)
                {
                    UPDATE_BALL_POSITION(304, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
        }
    }
    else
    {
        sub_2AADC();
    }

    unk132c->unk2C = unk132c->unk28;
    unk132c->unk28.x = (unk132c->position.x + 64) / 128;
    unk132c->unk28.y = (unk132c->position.y + 64) / 128;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}
