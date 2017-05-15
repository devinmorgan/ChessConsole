#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "GameStateModule.h"
#include "DisplayModule.h"

int main() {
    while (true) {
        PlayMode type = promptUserForGamePlayMode();
        switch (type) {
            case TIMED :
                playTimedChess();
                break;
            case UNTIMED :
                playUntimedChess();
                break;
            case EXIT :
                return 0;
        }
    }
}