#include "plant.h"
#include "nut.h"
#include <QTimer>
#include <iostream>
#include "block.h"

Nut::Nut(){
    name = "Nut";
    imagePath = ":/Image/src/nut.png";
    plantType = 0;
    cdtime = 200;
    healthy = 500;
    cost = 50;
}
