#include "main.h"
extern void deployintake();
extern void outtake();
extern void intaketriball();
inline bool isRedTeam = false;
inline bool isBlueTeam = false;
inline void selectRedTeam() {
    isRedTeam = true;
}
inline void selectBlueTeam(){
    isRedTeam = false;
}

inline int intake_speed;
