#include "main.h"
inline bool isRedTeam = false;
inline void selectRedTeam() {
    isRedTeam = true;
}
inline void selectBlueTeam(){
    isRedTeam = false;
}

inline int intake_speed;
inline int target = 0;
inline const int numStates = 6;
inline int states[numStates] = {0, -4800, -15500, -9500, -27000, -23000};