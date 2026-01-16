
typedef enum {
    MECHANICAL = 1,
    CHEMICAL,
    ENERGETIC,
    QUANTUM,
    STEAM
} invType;

typedef enum {
    PROTOTYPE = 1,
    TESTING,
    ADMISSIBLE,
    FORBIDDEN,
    UNSTABLE
} invStatus;

struct invention {
    char name[101];
    invType type;
    int reliability;
    int energydemand;
    invStatus status;
};
const char *typeNames[] = {
    "", "mechanical", "chemical", "energetic", "quantum", "steam"
};

const char *statusNames[] = {
    "", "prototype", "testing", "admissible", "forbidden", "unstable"
};
