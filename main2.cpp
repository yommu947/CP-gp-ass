void AIarrange() {
    srand(time(0));
    int AIshipdirection, pt1, pt2, errorcheck;
    for (int i = 1; i <= carrier; i++) {
        do {//horizontal
            AIshipdirection = rand() % 2 + 1;
            if (AIshipdirection == 1) {
                pt1 = rand() % seasize;
                pt2 = rand() % 6;
                for (int i = pt2; i <= pt2 + 4; i++) {
                    if (AIchart[pt1][i] != 'o') {
                        errorcheck = 1;
                    } else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1][pt2 + 1] = 'o';
                    AIchart[pt1][pt2 + 2] = 'o';
                    AIchart[pt1][pt2 + 3] = 'o';
                    AIchart[pt1][pt2 + 4] = 'o';
                    /*carrierpt[0] = AIshipdirection;
                    carrierpt[1] = pt1;
                    carrierpt[2] = pt2;
                    carrierpt[3] = pt2 + 1;
                    carrierpt[4] = pt2 + 2;
                    carrierpt[5] = pt2 + 3;
                    carrierpt[6] = pt2 + 4;*/
                }
            } else {//vertical
                pt1 = rand() % 6;
                pt2 = rand() % seasize;
                for (int i = pt1; i <= pt1 + 4; i++) {
                    if (AIchart[i][pt2] != 'o') {
                        errorcheck = 1;
                    } else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    pt1 = rand() % 6;
                    pt2 = rand() % seasize;
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1 + 1][pt2] = 'o';
                    AIchart[pt1 + 2][pt2] = 'o';
                    AIchart[pt1 + 3][pt2] = 'o';
                    AIchart[pt1 + 4][pt2] = 'o';
                }
            }
        } while (errorcheck == 0);
    }
    for (int i = 1; i <= battleship; i++) {
        do {//horizontal
            AIshipdirection = rand() % 2 + 1;
            if (AIshipdirection == 1) {
                pt1 = rand() % seasize;
                pt2 = rand() % 7;
                for (int i = pt2; i <= pt2 + 3; i++) {
                    if (AIchart[pt1][i] != 'o') {
                        errorcheck = 1;
                    } else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1][pt2 + 1] = 'o';
                    AIchart[pt1][pt2 + 2] = 'o';
                    AIchart[pt1][pt2 + 3] = 'o';
                    /*carrierpt[0] = AIshipdirection;
                    carrierpt[1] = pt1;
                    carrierpt[2] = pt2;
                    carrierpt[3] = pt2 + 1;
                    carrierpt[4] = pt2 + 2;
                    carrierpt[5] = pt2 + 3;
                    carrierpt[6] = pt2 + 4;*/
                }
            } else {//vertical
                pt1 = rand() % 7;
                pt2 = rand() % seasize;
                for (int i = pt1; i <= pt1 + 3; i++) {
                    if (AIchart[i][pt2] != 'o') {
                        errorcheck = 1;
                    } else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    pt1 = rand() % 7;
                    pt2 = rand() % seasize;
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1 + 1][pt2] = 'o';
                    AIchart[pt1 + 2][pt2] = 'o';
                    AIchart[pt1 + 3][pt2] = 'o';
                }
            }
        } while (errorcheck == 0);
    }
    for (int i = 1; i <= submarine; i++) {
        do {//horizontal
            AIshipdirection = rand() % 2 + 1;
            if (AIshipdirection == 1) {
                pt1 = rand() % seasize;
                pt2 = rand() % 8;
                for (int i = pt2; i <= pt2 + 2; i++) {
                    if (AIchart[pt1][i] != 'o') {
                        errorcheck = 1;
                    } else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1][pt2 + 1] = 'o';
                    AIchart[pt1][pt2 + 2] = 'o';
                    /*carrierpt[0] = AIshipdirection;
                    carrierpt[1] = pt1;
                    carrierpt[2] = pt2;
                    carrierpt[3] = pt2 + 1;
                    carrierpt[4] = pt2 + 2;
                    carrierpt[5] = pt2 + 3;
                    carrierpt[6] = pt2 + 4;*/
                }
            } else {//vertical
                pt1 = rand() % 8;
                pt2 = rand() % seasize;
                for (int i = pt1; i <= pt1 + 2; i++) {
                    if (AIchart[i][pt2] != 'o') {
                        errorcheck = 1;
                    } else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    pt1 = rand() % 8;
                    pt2 = rand() % seasize;
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1 + 1][pt2] = 'o';
                    AIchart[pt1 + 2][pt2] = 'o';
                }
            }
        } while (errorcheck == 0);
    }
    for (int i = 1; i <= destroyer; i++) {
        do {//horizontal
            AIshipdirection = rand() % 2 + 1;
            if (AIshipdirection == 1) {
                pt1 = rand() % seasize;
                pt2 = rand() % 9;
                for (int i = pt2; i <= pt2 + 1; i++) {
                    if (AIchart[pt1][i] != 'o') {
                        errorcheck = 1;
                    } else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1][pt2 + 1] = 'o';
                    /*carrierpt[0] = AIshipdirection;
                    carrierpt[1] = pt1;
                    carrierpt[2] = pt2;
                    carrierpt[3] = pt2 + 1;
                    carrierpt[4] = pt2 + 2;
                    carrierpt[5] = pt2 + 3;
                    carrierpt[6] = pt2 + 4;*/
                }
            } else {//vertical
                pt1 = rand() % 9;
                pt2 = rand() % seasize;
                for (int i = pt1; i <= pt1 + 1; i++) {
                    if (AIchart[i][pt2] != 'o') {
                        errorcheck = 1;
                    } else {
                        errorcheck = 0;
                        break;
                    }
                }
                if (errorcheck == 1) {
                    pt1 = rand() % 9;
                    pt2 = rand() % seasize;
                    AIchart[pt1][pt2] = 'o';
                    AIchart[pt1 + 1][pt2] = 'o';
                }
            }
        } while (errorcheck == 0);
    }
    AIsea();
}
