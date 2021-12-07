#ifndef LOAD_PICTURE_H
#define LOAD_PICTURE_H

#include <QPixmap>
#include"public_parameter.h"

class picture{
public:
    QPixmap background;
    QPixmap store;
    QPixmap board_sunflower;
    QPixmap board_shooter;
    QPixmap board_dbshooter;
    QPixmap board_iceshooter;
    QPixmap board_nut;
    QPixmap board_tallnut;
    QPixmap board_squash;
    QPixmap board_cherry_bomb;
    QPixmap board_pumpkin;
    QPixmap board_garlic;
    QPixmap walking_zombie;
    ////////////////////
    QPixmap existing_sun;
    QPixmap waling_zombie_frozen;
    QPixmap newspaper_zombie;
    QPixmap newspaper_zombie_frozen;
    QPixmap newspaper_zombie_empty;
    QPixmap newspaper_zombie_empty_frozen;
    QPixmap conehead_zombie;
    QPixmap conehead_zombie_frozen;
    QPixmap jack_in_the_box_zombie;
    QPixmap jack_in_the_box_zombie_frozen;
    QPixmap pole_vaulting_zombie;
    QPixmap pole_vaulting_zombie_frozen;
    QPixmap pole_vaulting_zombie_jumped;
    QPixmap pole_vaulting_zombie_jumped_frozen;
    QPixmap pole_vaulting_zombie_jumping;
    QPixmap capture_zombie;
    QPixmap capture_zombie_frozen;

    QPixmap nut2;
    QPixmap nut3;
    QPixmap tallnut2;
    QPixmap tallnut3;
    QPixmap boom;
    QPixmap sunshine_p;
    QPixmap cart_p;
    QPixmap main_menu;


    QPixmap game_over;
    QPixmap sun_flower;
    QPixmap shooter;
    QPixmap repeater;
    QPixmap ice_shooter;
    QPixmap nut;
    QPixmap tall_nut;
    QPixmap squash;
    QPixmap cherry_bomb;
    QPixmap garlic;
    QPixmap pumpkin;
    QPixmap pea;
    QPixmap snow_pea;
    QPixmap cherry_explode;
    QPixmap zombie_explode;
    ////////////////////////////
    QPixmap cool_flower;
    QPixmap cool_shooter;
    QPixmap cool_dbshooter;
    QPixmap cool_ice;
    QPixmap cool_nut;
    QPixmap cool_tn;
    QPixmap cool_squash;
    QPixmap cool_cherry;
    QPixmap cool_garlic;
    QPixmap cool_pumpkin;

    QPixmap pause_button;
    QPixmap continue_button;
    QPixmap ShovelBank;
    QPixmap shovel;
    picture(){
        background.load(":/images/Background.jpg");
        store.load(":/images/Shop.png");
        board_sunflower.load(":/picture/sunFlowerOnMenu.png");
        board_shooter.load(":/picture/shooterOnMenu.png");
        board_iceshooter.load(":/picture/iceShooterOnMenu.png");
        board_dbshooter.load(":/picture/dbShooterOnMenu.png");
        board_nut.load(":/picture/nutOnMenu.png");
        board_tallnut.load(":/picture/highNutOnMenu.png");
        board_squash.load(":/picture/squashOnMenu.png");
        board_cherry_bomb.load(":/picture/bombOnMenu.png");
        board_pumpkin.load(":/picture/pumpkinOnMenu.png");
        board_garlic.load(":/picture/onionOnMenu.png");
        walking_zombie.load(":/picture/zombie.png");

        pumpkin.load(PUMPKIN);
        pole_vaulting_zombie_jumping.load(":/picture/pole_jumping2.png");
        capture_zombie.load(":/picture/catapult_zombie2.png");
        capture_zombie_frozen.load(":/picture/catapult_zombie3.png");
        nut2.load(":/picture/Wallnut_1.png");
        nut3.load(":/picture/Wallnut_2.png");
        tallnut2.load(":/picture/Tallnut_1.png");
        tallnut3.load(":/picture/Tallnut_2.png");
        boom.load(":/picture/Cherrybomb_1.png");
        cool_pumpkin.load(":/picture/pumpkinOnMenu2.png");
        sunshine_p.load(":/picture/Sunshine.png");

        pause_button.load(":/picture/PAUSE.png");
        continue_button.load(":/picture/Continue.png");
        ShovelBank.load(":/picture/ShovelBank.png");
        shovel.load(":/picture/shovel.png");
        cart_p.load(":/picture/cart.png");
        main_menu.load(":/picture/menu.jpg");

        existing_sun.load(GAME_SUNSHINE);
        waling_zombie_frozen.load(FROZEN_ZOMBIE);
        newspaper_zombie.load(NEWSPAPER_ZOMBIE_PAPER);
        newspaper_zombie_frozen.load(FROZEN_NEWSPAPER_ZOMBIE_PAPER);
        newspaper_zombie_empty.load(NEWSPAPER_ZOMBIE_EMPTY);
        newspaper_zombie_empty_frozen.load(FROZEN_NEWSPAPER_ZOMBIE_EMPTY);
        conehead_zombie.load(CONEHEAD_ZOMBIE);
        conehead_zombie_frozen.load(FROZEN_CONEHEAD_ZOMBIE);
        jack_in_the_box_zombie.load(JACK_IN_THE_BOX_ZOMBIE);
        jack_in_the_box_zombie_frozen.load(FROZEN_JACK_IN_THE_BOX_ZOMBIE);
        pole_vaulting_zombie.load(POLE_VAULTING_ZOMBIE);
        pole_vaulting_zombie_frozen.load(FROZEN_POLE_VAULTING_ZOMBIE);
        pole_vaulting_zombie_jumped.load(POLE_VAULTING_ZOMBIE_JUMPED);
        pole_vaulting_zombie_jumped_frozen.load(FROZEN_POLE_VAULTING_ZOMBIE_JUMPED);
        game_over.load(GAME_OVER);
        sun_flower.load(SUNFLOWER);
        shooter.load(SHOOTER);
        repeater.load(REPEATER);
        ice_shooter.load(ICESHOOTER);
        nut.load(NUT);
        tall_nut.load(TALLNUT);
        cherry_bomb.load(CHERRY);
        squash.load(SQUASH);
        garlic.load(GARLIC);
        pea.load(PEA);
        snow_pea.load(SNOWPEA);
        cherry_explode.load(CHERRY_EXPLODE);
        zombie_explode.load(ZOMBIE_EXPLODE);
        cool_flower.load(C_FLOWER);
        cool_tn.load(C_TN);
        cool_ice.load(C_ICE);
        cool_nut.load(C_NUT);
        cool_cherry.load(C_BOMB);
        cool_shooter.load(C_SHOOTER);
        cool_garlic.load(C_GARLIC);
        cool_squash.load(C_SQUASH);
        cool_dbshooter.load(C_DB);
    }

};



#endif // LOAD_PICTURE_H
