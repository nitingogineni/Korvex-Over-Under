#include "main.h"
extern void deployintake();
extern void outtake();
extern void intaketriball();
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
inline int states[numStates] = {0, -1000, -1500, -9000, -27000, -23000};