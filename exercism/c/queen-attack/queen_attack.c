#include "queen_attack.h"
#include <stdlib.h>

attack_status_t can_attack(position_t queen_1, position_t queen_2){
    if(queen_1.row >= 8 || queen_1.column >= 8 ||
        queen_2.row >= 8 || queen_2.column >=8){
        return INVALID_POSITION;
        }
    if(queen_1.row == queen_2.row && queen_1.column == queen_2.column){
        return INVALID_POSITION;
    }
    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column) {
        return CAN_ATTACK;
    }
    int delta_row = abs((int)queen_1.row - (int)queen_2.row);
    int delta_col = abs((int)queen_1.column - (int)queen_2.column);

    if(delta_row == delta_col){
        return CAN_ATTACK;
    }
    return CAN_NOT_ATTACK;
}