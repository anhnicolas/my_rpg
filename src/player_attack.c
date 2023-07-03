/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** player_attack
*/

#include <../include/my_rpg.h>

void move_projectile(game_t *g)
{
    PLAYER->projectilePos.x += PLAYER->projectileSpeed * (g->deltatime / 2);
    sfSprite_setPosition(PLAYER->projectile, PLAYER->projectilePos);
    PLAYER->projectileTime = sfClock_getElapsedTime(PLAYER->projectileClock);
    if (sfTime_asMilliseconds(PLAYER->projectileTime) > 100) {
        PLAYER->projectileFrame = (PLAYER->projectileFrame + 1) % 3;
        sfSprite_setTexture(PLAYER->projectile,
        PLAYER->projectileTexture[PLAYER->projectileFrame], sfTrue);
        sfClock_restart(PLAYER->projectileClock);
    }
    if (PLAYER->projectilePos.x >= PLAYER->pos.x + VIEW_SIZE.x) {
        PLAYER->canShoot = true;
    }
}

void shoot(game_t *g)
{
    if (PLAYER->canShoot) {
        sfMusic_play(PLAYER->projectileSound);
        PLAYER->projectilePos.x = PLAYER->pos.x + 50;
        PLAYER->projectilePos.y = PLAYER->pos.y - 25;
        sfSprite_setPosition(PLAYER->projectile, PLAYER->projectilePos);
        PLAYER->canShoot = false;
    }
}

void player_attack(game_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        PLAYER->frame_data = 0;
        shoot(g);
    }
}
