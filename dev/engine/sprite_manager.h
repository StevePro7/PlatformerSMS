#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

// Private helper method.
void engine_sprite_manager_draw(unsigned char x, unsigned char y, unsigned char tile);


static void engine_sprite_manager_draw(unsigned char x, unsigned char y, unsigned char tile)
{
    SMS_addSprite(x + 0, y + 0, tile + 0);
    /*SMS_addSprite(x + 8, y + 0, tile + 1);
    SMS_addSprite(x + 16, y + 0, tile + 2);
    SMS_addSprite(x + 24, y + 0, tile + 3);

    SMS_addSprite(x + 0, y + 8, tile + 4);
    SMS_addSprite(x + 8, y + 8, tile + 5);
    SMS_addSprite(x + 16, y + 8, tile + 6);
    SMS_addSprite(x + 24, y + 8, tile + 7);

    SMS_addSprite(x + 0, y + 16, tile + 8);
    SMS_addSprite(x + 8, y + 16, tile + 9);
    SMS_addSprite(x + 16, y + 16, tile + 10);
    SMS_addSprite(x + 24, y + 16, tile + 11);

    SMS_addSprite(x + 0, y + 24, tile + 12);
    SMS_addSprite(x + 8, y + 24, tile + 13);
    SMS_addSprite(x + 16, y + 24, tile + 14);
    SMS_addSprite(x + 24, y + 24, tile + 15);*/
}

#endif//_SPRITE_MANAGER_H_